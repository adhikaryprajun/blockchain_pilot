#include<iostream.h>

class Block {
private:
	int index;
	//int nonce;
	const char * data;
	char * hash;
	
	char * calculateHash() const;
public:
	char * previousHash; 

	Block(int, const char * &);
	char * getHash();
	void mineBlock(int);
};
Block::Block(int indexIn, const char * &dataIn) : index(indexIn), data(dataIn) {
	//nonce = -1;
}
char * Block::getHash() {
    return hash;
}
void Block::mineBlock(int challenge) {
    //char cstr[6];
    //for (int i = 0; i < challenge; ++i) {
	//cstr[i] = '0';
    //}
    //cstr[challenge] = '\0';
    //char * str(cstr);
    //do {
    //	nonce++;
    //	hash = calculafteHash();
    //} while (hash.substr(0, challenge) != cstr);
    cout << "Block mined: " << hash << endl;
}
inline char * Block::calculateHash() const {
    // stringstream ss;
    // ss << index << tTime << data << nonce << previousHash;
    // return sha256(ss.str());
    return "Calculate Hash Data....";
}
/**************************************/
class Vector {
public:
	void emplace_back(Block);
	void push_back(Block);
	Block back();
};
void Vector::emplace_back(Block b) {
	cout<<"Emplace back on chain..."<<endl;
}
void Vector::push_back(Block b) {
	cout<<"Pushing Back to the chain"<<endl;
}
Block Vector::back() { 
	cout<<"Getting last block"<<endl;
	return Block(0, "Genesis Block"); 
}

/**************************************/
class Blockchain {
private:
	int challenge;
	Vector vectorChain;
	
	Block getLastBlock() const; 
public:
	Blockchain();
	void addBlock(Block bNew);
};
Blockchain::Blockchain() {
	cout<<"Creating Genesis Block";
	vectorChain.emplace_back(Block(0, "Genesis Block"));
	challenge = 6;
}
void Blockchain::addBlock(Block bNew) {
	cout<<"Adding Block to chain"<<endl;
    bNew.previousHash = getLastBlock().getHash();
    bNew.mineBlock(challenge);
    vectorChain.push_back(bNew);
}
Block Blockchain::getLastBlock() const {
	cout<<"Getting last block"<<endl;
    return vectorChain.back();
}
/**************************************/
int main() {

	int i=0, j=0;
	cout<<"Starting program"<<endl;

	Blockchain bChain = Blockchain();
	do {
		cout<<"###############################"<<endl;
		cout<<"Enter options"<<endl;
		cout<<"###############################"<<endl;
		cout<<" 1. Add Block"<<endl;
		cout<<" 2. Exit"<<endl;
		cout<<"###############################"<<endl;
		cout<<"=>";
		cin>>i;	
		switch(i) {
			case 1:
				char * data;
				cout<<"Enter data::"<<endl;
				cin>>data;
				bChain.addBlock(Block(++j, data));
				break;
			case 2:
				return 0;
			default:
				break;
		}
	} while(i != 2);
	
	cin>>i;
	cout<<"Ending Program"<<endl;
	return 0;
}