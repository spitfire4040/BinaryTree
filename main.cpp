#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

// Main Function
int main(){

	Tree tree1(10);

	if(tree1.addNode(9)){
		cout << "added 9" << endl;
	}

	else{
		cout << "didn't add 9" << endl;
	}

	if(tree1.addNode(8)){
		cout << "added 8" << endl;
	}

	else{
		cout << "didn't add 8" << endl;
	}

	if(tree1.addNode(12)){
		cout << "added 12" << endl;
	}

	else{
		cout << "didn't add 12" << endl;
	}

	if(tree1.addNode(12)){
		cout << "added 12" << endl;
	}

	else{
		cout << "didn't add 12" << endl;
	}

	if(tree1.findNode(7)){
		cout << "found 7" << endl;
	}

	else{
		cout << "didn't find 7" << endl;
	}

	if(tree1.findNode(12)){
		cout << "found 12" << endl;
	}

	else{
		cout << "didn't find 12" << endl;
	}

	if(tree1.findNode(2)){
		cout << "found 2" << endl;
	}

	else{
		cout << "didn't find 2" << endl;
	}

	if(tree1.findNode(8)){
		cout << "found 8" << endl;
	}

	else{
		cout << "didn't find 8" << endl;
	}	

	tree1.deleteNode(8);

	if(tree1.findNode(8)){
		cout << "found 8" << endl;
	}

	else{
		cout << "didn't find 8" << endl;
	}	

	return 0;
}