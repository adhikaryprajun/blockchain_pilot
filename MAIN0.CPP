#include<iostream.h>
#include<malloc.h>
/**************************************/
class MyBlock {
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
	//Math Problem
}
inline char * MyBlock::calculateHash() const {
	// SHA 256 Hashing
	return "Calculate Hash Data....";
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
	Chain chain;

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
	cout<<"Adding MyBlock to chain"<<endl;
	bNew.previousHash = getLastMyBlock().getHash();
	bNew.mineMyBlock(challenge);
	chain.insertLast(bNew);
}
MyBlock MyBlockchain::getLastMyBlock(){
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
	
	int k = 0;
	MyBlockchain chain = MyBlockchain();
	char * d1, * d2, * d3;
	cin>>d;
	
	MyBlock b1;
	b1.setData(d1);
	b1.setIndex(++k);
	//cout<<b1.getData()<<endl;
	chain.addMyBlock(b1);
	chain.display();
	
	//char * dd;
	cin>>d2;
	
	MyBlock b2;// (++k, d);
	b2.setData(d2);
	b2.setIndex(++k);
	//cout<<b1.getData()<<"->";
	//cout<<b2.getData()<<endl;
	chain.addMyBlock(b2);
	chain.display();
	
	//char * ddd;
	cin>>d3;
	
	MyBlock b3;// (++k, d);
	b3.setData(d3);
	b3.setIndex(++k);
	//cout<<b1.getData()<<"->";
	//cout<<b2.getData()<<"->";
	//cout<<b3.getData()<<endl;
	chain.addMyBlock(b3);
	chain.display();

	

	int i = 0, j = 0;
	cout<<"Welcome To MyBlockchain DEMO Application Program"<<endl;
	MyBlockchain bChain = MyBlockchain();
	char * dota;
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
				char dota[10];
				cout<<"Enter data::"<<endl;
				//char * dota;
				cin.sync();
				cin>>dota;
				MyBlock bNew;// = new MyBlock();
				//(++j, dota);
				bNew.setData(dota);
				bNew.setIndex(++j);
				cout<<"Before Adding to Block::"<<bNew.getData()<<endl;
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