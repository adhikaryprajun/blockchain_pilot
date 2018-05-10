#include<iostream.h>
#include<malloc.h>
#include<string.h>
/**************************************/
class Block {
public:
	virtual void mineMyBlock(int)=0;
};
class MyBlock:public Block {
private:
	int index;
	char * data;
	char * hash;
	char * calculateHash() const;
public:
	char * previousHash;
	char * getHash();
	int getIndex();
	void setIndex(int);
	char * getData();
	void setData(char *);
	void mineMyBlock(int);
	friend void blockDetails(MyBlock);
};
char * MyBlock::getHash() {
	return this->hash;
}
int MyBlock::getIndex() {
	return this->index;
}
void MyBlock::setIndex(int index) {
	this->index = index;
}
char * MyBlock::getData() {
	return this->data;
}
void MyBlock::setData(char * data) {
	this->data=data;
}
void MyBlock::mineMyBlock(int challenge) {
	/*
	char cstr[6];
	for (int i = 0; i < challenge; ++i) {
		cstr[i] = '0';
	}
	cstr[challenge] = '\0';
	//do {
	//	hash = calculateHash();
	//} while (hash.substr(0, challenge) != cstr);
	*/
}
inline char * MyBlock::calculateHash() const {
	// SHA 256 Hashing
	return "Calculate Hash Data....";
}
void blockDetails(MyBlock block) {
	cout<<block.index<<" "<<block.data<<" "<<block.hash<<endl;
}
/**************************************/
struct Node {
public:
	MyBlock myBlock;
	Node * next;
} * start;
/**************************************/
class Chain {
private:
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
	cout<<"------"<<"Creating Node from Block"<<"------"<<endl;
	struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
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
	cout<<"------"<<"Insert in last"<<"------"<<endl;
	struct Node * temp, * s;
	temp = createNodeFromMyBlock(myBlock);
	cout<<"Data In Node To Be Added::"<<temp->myBlock.getData();
	s = start;
	while (s->next != NULL) {
		cout<<"Data::"<<s->myBlock.getData()<<endl;
		s = s->next;
	}
	s->next = temp;
}
Node * Chain::getLast() {
	cout<<"------"<<"Gettting Last Block"<<"------"<<endl;
	struct Node * s;
	s = start;
	while (s->next != NULL) {
		cout<<"Data::"<<s->myBlock.getData()<<endl;
		s = s->next;
	}
	return s;
}
void Chain::display() {
	cout<<"------"<<"Displaying"<<"------"<<endl;
	struct Node * temp;
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
	cout<<"END"<<endl;
}
/**************************************/
class MyBlockchain {
private:
	int challenge;
	Chain chain; // Single Linked List Chain

	MyBlock getLastMyBlock();
public:
	MyBlockchain();
	void addMyBlock(MyBlock);
	void display();
};
MyBlockchain::MyBlockchain() {
	cout<<"Creating Genesis MyBlock"<<endl;
	MyBlock block;
	block.setData("Genesis");
	block.setIndex(0);
	start = chain.createNodeFromMyBlock(block);
	challenge = 6;
}
void MyBlockchain::addMyBlock(MyBlock bNew) {
	cout<<"Adding MyBlock To Chain"<<endl;
	bNew.previousHash = getLastMyBlock().getHash();
	bNew.mineMyBlock(challenge);
	chain.insertLast(bNew);
}
MyBlock MyBlockchain::getLastMyBlock(){
	cout<<"Getting Last MyBlock -> "<<chain.getLast()->myBlock.getData()<<endl;
	return chain.getLast()->myBlock;
}
void MyBlockchain::display() {
	chain.display();
}
/**************************************/
int main() {
	int k = 0;
	MyBlockchain chain = MyBlockchain();
	
	char * d1, * d2, * d3, * d4, * d5;
	
	cout<<"Enter Data 1 ::";
	cin>>d1;
	MyBlock b1;
	b1.setData(d1);
	b1.setIndex(++k);
	blockDetails(b1);
	chain.addMyBlock(b1);
	chain.display();
	
	cout<<"Enter Data 2 ::";
	cin>>d2;	
	MyBlock b2;
	b2.setData(d2);
	b2.setIndex(++k);
	blockDetails(b2);
	chain.addMyBlock(b2);
	chain.display();
	
	cout<<"Enter Data 3 ::";
	cin>>d3;
	MyBlock b3;
	b3.setData(d3);
	b3.setIndex(++k);
	blockDetails(b3);
	chain.addMyBlock(b3);
	chain.display();

	cout<<"Enter Data 4 ::";
	cin>>d4;
	MyBlock b4;
	b4.setData(d4);
	b4.setIndex(++k);
	blockDetails(b4);
	chain.addMyBlock(b4);
	chain.display();

	cout<<"Enter Data 5 ::";
	cin>>d5;
	MyBlock b5;
	b5.setData(d5);
	b5.setIndex(++k);
	blockDetails(b5);
	chain.addMyBlock(b5);
	chain.display();

	int end;
	cout<<"Press any key to exit..."<<endl;
	cin>>end;
	return 0;
}