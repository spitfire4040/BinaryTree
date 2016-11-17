// Header Files
#include <iostream>
#include "tree.h"

using namespace std;

// parameterized constructor
Tree::Tree(int newValue){
	this->head = NULL;
	this->cursor = NULL;
	this->temp = NULL;

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
	temp = NULL;
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

		cursor = head;

		if(isEmpty()){
			return false;
		}

		if(cursor->value == newValue){
			if(cursor->left == NULL && cursor->right == NULL){
				delete[] cursor;
				cursor = NULL;
				head = NULL;
			}
			else{
				
			}
		}

		return true;
	}

	bool Tree::clearTree(){

		return true;
	}

	bool printInOrder(){

		return true;
	}

	bool printPostOrder(){

		return true;
	}