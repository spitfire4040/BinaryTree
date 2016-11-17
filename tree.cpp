// Header Files
#include <iostream>
#include "tree.h"

using namespace std;

// parameterized constructor
Tree::Tree(int newValue){
	this->head = NULL;
	this->cursor = NULL;
	this->temp1 = NULL;
	this->temp2 = NULL;

	head = new Node();
	cursor = head;
	head->value = newValue;

	cout << "parameterized constructor called" << endl;
}

// destructor
Tree::~Tree(){
	cout << "destructor called" << endl;
	clearTree();
	head = NULL;
	cursor = NULL;
	temp1 = NULL;
	temp2 = NULL;
}

	bool Tree::addNode(int newValue){
		bool flag = false;

		// set cursor to head
		cursor = head;

		// iterate until end is found
		while(flag == false){

			// if value exists, don'd add it again
			if(newValue == cursor->value){
				return false;
			}

			// if value is less than node, go left
			else if(newValue < cursor->value){

				// if at the end, add node
				if(cursor->left == NULL){
					cursor->left = new Node();
					cursor = cursor->left;
					cursor->value = newValue;
					flag = true;
				}

				// if not at the end, go again
				else{
					cursor = cursor->left;
				}
			}

			// if value is greater than node, go right
			else{

				// if at the end, add node
				if(cursor->right == NULL){
					cursor->right = new Node();
					cursor = cursor->right;
					cursor->value = newValue;
					flag = true;
				}

				// if not at the end, go again
				else{
					cursor = cursor->right;
				}
			}
		}
		return true;
	}

	bool Tree::isEmpty(){

		// if head is null, it's empty
		if(head == NULL){
			return true;
		}

		// if head != null, it's not empty
		return false;
	}

	bool Tree::findNode(int newValue){

		// set cursor to head
		cursor = head;

		// check for empty tree
		if(isEmpty()){
			return false;
		}

		// iterate forever
		for(;;){

			// end if value is found
			if(cursor->value == newValue){
				return true;
			}

			// if value is less than current, go left
			else if(newValue < cursor->value){

				// if end and not found stop
				if(cursor->left == NULL){
					return false;
				}

				// if value is greater than current, go right
				else{
					cursor = cursor->left;
				}
			}

			// if end and not found stop
			else{
				if(cursor->right == NULL){
					return false;
				}

				// if not found, go right
				else{
					cursor = cursor->right;
				}
			}
		}
		return true;
	}

	bool Tree::deleteNode(int newValue){

		cursor = temp1 = head;
		bool flag1 = false;
		bool flag2 = false;
		bool flag3 = false;

		// check for empty tree
		if(isEmpty()){
			return false;
		}

		// step 1: locate node
		while(flag1 == false){

			// current node is the right one
			if(cursor->value == newValue){
				flag1 = true;
			}

			// search left side
			else if(newValue < cursor->value){
				temp1 = cursor;
				cursor = cursor->left;
				cout << "going left" << endl;
			}

			// search right side
			else{
				temp1 = cursor;
				cursor = cursor->right;
				cout << "going right" << endl;
			}
		}
		cout << "you are here..." << cursor->value << endl;


		// case 1: node has no children (delete node)
		if((cursor->left == NULL) && (cursor->right == NULL)){
			delete[] cursor;
			cursor = NULL;
			return true;
		}


		// case 2: node has 1 child on left (bypass node)
		if((cursor->left != NULL) && (cursor->right != NULL)){
			temp1->left = cursor->left;
			delete[] cursor;
			cursor = NULL;
			return true;
		}


		// case 3: node has 1 child on right (bypass node)
		if((cursor->left == NULL) && (cursor->right != NULL)){
			temp1->right = cursor->right;
			delete[] cursor;
			cursor = NULL;
			return true;
		}


		// case 4: node has 2 children (substitute successor node)
		if((cursor->left != NULL) && (cursor->right != NULL)){

			// set temp1 to cursor (make it follow 1 behind)
			temp1 = cursor;

			// go 1 step to the right then find minimum value (successor)
			while(flag2 == false){
				temp2 = cursor;
				cursor = cursor->right;

				// case 1; left side is null
				if(cursor->left == NULL){
					flag2 = true;
				}

				// case 2; left side is not null
				else{

					// iterate until minimum (left end) is found
					while(flag3 == false){

						// set temp2 so it can be set to null after deleting successor (make it follow)
						temp2 = cursor;
						cursor = cursor->left;

						// seek the end
						if(cursor->left == NULL){
							// stop inner loop
							flag3 = true;
						}
					}

					// stop outer loop
					flag2 = true;

				}

			}

			// the end...swap values and delete original successor
			temp1->value = cursor->value;
			delete[] cursor;
			cursor = NULL;
			temp2->left = NULL;
			return true;

		}

		return false;
	}

	bool Tree::clearTree(){

		return true;
	}

	bool printInOrder(){

		return true;
	}

	bool printPreOrder(){

		return true;
	}

	bool printPostOrder(){

		return true;
	}