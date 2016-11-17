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

		cursor = head;

		while(flag == false){

			if(newValue == cursor->value){
				return false;
			}

			else if(newValue < cursor->value){

				if(cursor->left == NULL){
					cursor->left = new Node();
					cursor = cursor->left;
					cursor->value = newValue;
					flag = true;
				}

				else{
					cursor = cursor->left;
				}
			}

			else{

				if(cursor->right == NULL){
					cursor->right = new Node();
					cursor = cursor->right;
					cursor->value = newValue;
					flag = true;
				}

				else{
					cursor = cursor->right;
				}
			}
		}
		return true;
	}

	bool Tree::isEmpty(){
		if(head == NULL){
			return true;
		}
		return false;
	}

	bool Tree::findNode(int newValue){

		cursor = head;

		if(isEmpty()){
			return false;
		}

		for(;;){

			if(cursor->value == newValue){
				return true;
			}

			else if(newValue < cursor->value){
				if(cursor->left == NULL){
					return false;
				}

				else{
					cursor = cursor->left;
				}
			}

			else{
				if(cursor->right == NULL){
					return false;
				}

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

			temp1 = cursor;

			while(flag2 == false){
				temp2 = cursor;
				cursor = cursor->right;

				// case 1; left side is null
				if(cursor->left == NULL){
					flag2 = true;
				}

				// case 2; left side is not null
				else{

					while(flag3 == false){
						temp2 = cursor;
						cursor = cursor->left;
						if(cursor->left == NULL){
							flag3 = true;
						}
					}

					flag2 = true;

				}

			}

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