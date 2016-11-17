// Header Files
#include <iostream>

using namespace std;

// initialize Node struct
struct Node{
	int value;
	Node *left;
	Node *right;

	// initialize values in Node
	Node(){
		value = 0;
		left = NULL;
		right = NULL;
	}
};

// initialize List class
class Tree{
	
public:
	Tree();
	Tree(int newValue);
	~Tree();

	bool addNode(int newValue);
	bool isEmpty();
	bool findNode(int newValue);
	bool deleteNode(int newValue);
	bool clearTree();
	bool printInOrder();
	bool printPreOrder();
	bool printPostOrder();

private:
	Node *head;
	Node *cursor;
	Node *temp1;
	Node *temp2;
};