#include<iostream.h>
#include<malloc.h>
/**************************************/
class MyBlock {
private:
	int index;
	const char * data;
	char * hash;
	char * calculateHash() const;
public:
	char * previousHash;
	MyBlock(int, char *);
	char * getHash();
	int getIndex();
	const char * getData();
	void mineMyBlock(int);
};
MyBlock::MyBlock(int indexIn, char * dataIn) : index(indexIn), data(dataIn) {}
char * MyBlock::getHash() {
	return this->hash;
}
int MyBlock::getIndex() {
	return this->index;
}
const char * MyBlock::getData() {
	return this->data;
}
void MyBlock::mineMyBlock(int challenge) {
	//cout<<"MyBlock mined: "<<hash<<endl;
}
inline char * MyBlock::calculateHash() const {
	return "Calculate Hash Data....";
}
/**************************************/
class Node {
public:
	MyBlock myBlock;
	Node * next;
};
Node * start;
/**************************************/
class Chain {
public:
	Node * createNodeFromMyBlock(MyBlock);
	void insertLast(MyBlock);
	Node * getLast();
	void display();
	Chain() {
		start = NULL;
	}
};
Node * Chain::createNodeFromMyBlock(MyBlock myBlock) {
	Node * temp;
	if (temp == NULL) {
		cout<<"Memory not allocated "<<endl;
		return 0;
	} else {
		temp->myBlock = myBlock;
		temp->next = NULL;
		return temp;
	}
}
void Chain::insertLast(MyBlock myBlock) {
	Node * temp, * s;
	temp = createNodeFromMyBlock(myBlock);
	s = start;
	while (s->next != NULL) {
		s = s->next;
	}
	s->next = temp;
}
Node * Chain::getLast() {
	Node * s;
	s = start;
	while (s->next != NULL) {
		s = s->next;
	}
	return s;
}
void Chain::display() {
	Node * temp;
	if (start == NULL) {
		cout<<"The Chain is Empty"<<endl;
		return;
	}
	temp = start;
	cout<<"Elements of Chain are: "<<endl;
	while (temp != NULL) {
		cout<<temp->myBlock.getIndex()<<"-"<<temp->myBlock.getData()<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
/**************************************/
class MyBlockchain {
private:
	int challenge;
	Chain chain;

	MyBlock getLastMyBlock() const;
public:
	MyBlockchain();
	void addMyBlock(MyBlock);
	void display();
};
MyBlockchain::MyBlockchain() {
//	cout<<"Creating Genesis MyBlock"<<endl;
	start = chain.createNodeFromMyBlock(MyBlock(0, "Genesis MyBlock"));
//	cout<<"Setting Challenge to 6"<<endl;
	challenge = 6;
}
void MyBlockchain::addMyBlock(MyBlock bNew) {
//	cout<<"Adding MyBlock to chain"<<endl;
	bNew.previousHash = getLastMyBlock().getHash();
//	cout<<"Getting Hash"<<endl;
	bNew.mineMyBlock(challenge);
//	cout<<"Mine MyBlock"<<endl;
	chain.insertLast(bNew);
//	cout<<"Insert in Laast"<<endl;
}
MyBlock MyBlockchain::getLastMyBlock() const {
	cout<<"Getting last MyBlock->"<<chain.getLast()->myBlock.getData()<<endl;
	return chain.getLast()->myBlock;
}
void MyBlockchain::display() {
	chain.display();
}
/**************************************/
int main() {
	/*
	int i=0, j=0;
	char * info = "HI";
	cout<<"Welcome To MyBlockchain DEMO Application Program"<<endl;
	MyBlockchain bChain = MyBlockchain();
	cout<<"-----------"<<endl;
	cout<<"-----------"<<endl;
	cin>>info;
	cout<<info<<endl;
	bChain.addMyBlock(MyBlock(++j, "A"));
	bChain.display();
	cout<<"-----------"<<endl;
	cin>>info;
	cout<<info<<endl;
	bChain.addMyBlock(MyBlock(++j, "B"));
	bChain.display();
	cout<<"-----------"<<endl;
	cin>>info;
	cout<<info<<endl;
	bChain.addMyBlock(MyBlock(++j, "C"));
	bChain.display();
	cout<<"-----------"<<endl;
	cin>>info;
	cout<<info<<endl;
	bChain.addMyBlock(MyBlock(++j, info));
	bChain.display();
	cout<<"-----------"<<endl;
	cin>>info;
	cout<<info<<endl;
	bChain.addMyBlock(MyBlock(++j, info));
	bChain.display();
	cout<<"-----------"<<endl;
	cin>>info;
	cout<<info<<endl;
	bChain.addMyBlock(MyBlock(++j, info));
	bChain.display();
	cout<<"-----------"<<endl;
	cout<<"-----------"<<endl;
	*/


/*
	int k = 0;
	char * d;
	MyBlockchain chain = MyBlockchain();
	cin>>d;
	MyBlock b1 (++k, d);
	cout<<b1.getData()<<endl;
	chain.addMyBlock(b1);
	chain.display();
	char * dd;
	cin>>d;
	MyBlock b2 (++k, d);
	cout<<b1.getData()<<"->";
	cout<<b2.getData()<<endl;
	chain.addMyBlock(b1);
	chain.display();
	char * ddd;
	cin>>d;
	MyBlock b3 (++k, d);
	cout<<b1.getData()<<"->";
	cout<<b2.getData()<<"->";
	cout<<b3.getData()<<endl;
	chain.addMyBlock(b1);
	chain.display();
*/

	int i = 0, j = 0;
	cout<<"Welcome To MyBlockchain DEMO Application Program"<<endl;
	MyBlockchain bChain = MyBlockchain();
	do {
		cout<<endl;
		cout<<"###############################"<<endl;
		cout<<"Enter options"<<endl;
		cout<<"###############################"<<endl;
		cout<<" 1. Add MyBlock"<<endl;
		cout<<" 2. Display Chain"<<endl;
		cout<<" 3. Exit"<<endl;
		cout<<"###############################"<<endl;
		cout<<"=>";
		cin>>i;
		switch(i) {
			case 1:
				//char data[10];
				cout<<"Enter data::"<<endl;
				char * dota;
				cin.sync();
				cin>>dota;
				MyBlock bNew(++j, dota);
				cout<<"Before Adding to Block"<<bNew.getData()<<endl;
				bChain.addMyBlock(bNew);
				//cout<<"Last Block Data"<<bChain.getLastMyBlock().getData()<<endl;
				break;
			case 2:
				bChain.display();
				break;
			default:
				break;
		}
	} while(i != 3);
	cout<<"Closing MyBlockchain..."<<endl;
	cin>>i;
	return 0;
}