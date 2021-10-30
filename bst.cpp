/*
 * bst.cpp
 *
 *  Created on: Oct 20, 2021
 *      Author: pinkhathacker
 */

#include "bst.hpp"
#include "bstNode.hpp"
#include "Student.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


bst::bst(){
	root = NULL;
}

bst::bst(string f, string l, int n, string j){
	root = new bstNode(f, l, n, j);
}

bool bst::insert(string f, string l, int n, string j){
	//TODO: bst::insert() bst.cpp
	/*
	 * this method takes as input parameters all
	 * the fields necessary to create a student object (and will be the fields passed into
	 * the bstNode constructor, where the student field exists). This method returns true
	 * if a new node is created and the data is inserted into the tree successfully, and
	 * false otherwise.
	 */

	bstNode *temp = new bstNode(f, l, n, j);
	bstNode *temp2 = root;
	if(temp2 == NULL){
		root = temp;
		//setHeight()
		return true;
	}else{

		while(temp2 != NULL){
			if((temp->student->last) < (temp2->student->last)){
				if(temp2->left == NULL){
					temp2->left = temp;
					temp->parent = temp2;
					//setHieght()
					return true;
				}
				temp2 = temp2->left;
			}else if((temp->student->last) > (temp2->student->last)){
				if(temp2->right == NULL){
					temp2->right = temp;
					temp->parent = temp2;
					//setHeight()
					return true;
				}
				temp2 = temp2->right;
			}else if((temp->student->last) == (temp2->student->last)){
				if((temp->student->first) == (temp2->student->first)){
					return false;
				}else{
					if((temp->student->first) < (temp2->student->first)){
						if(temp2->left == NULL){
								temp2->left = temp;
								temp->parent = temp2;
								//setHieght()
								return true;
							}
							temp2 = temp2->left;
					}else if((temp->student->last) > (temp2->student->last)){
						if(temp2->right == NULL){
							temp2->right = temp;
							temp->parent = temp2;
							//setHeight()
							return true;
						}
						temp2 = temp2->right;
					}
				}
			}
		}
	}
	return true;
}

bstNode *bst::find(string l, string f){
	//TODO: *bst::find()
	/*
	 * finds whether a student with the last name l and first
	 * name f is in the tree is in the tree, and, if it is, returns the node holding that
	 * student. Otherwise it returns NULL.
	 */
}

void bst::printTreeIO(){
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void bst::printTreeIO(bstNode *n){
	//TODO: bst::printTreeIO
	/*
	 * recursive function that prints out the data in the tree
	 * in order
	 */
	if(n == NULL){
			return;
	}else{
		//if im understanding this right go left print stack, then go right and print stack
		printTreePre(n->left);
		n->printNode();
		printTreePre(n->right);
	}
}

void bst::printTreePre(){
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void bst::printTreePre(bstNode *n){
	//TODO: printTreePre()
	/*
	 * a recursive function that prints out the datain the
	 * tree in pre-order
	 */
	if(n == NULL){
		return;
	}else{
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void bst::printTreePost(){
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void bst::printTreePost(bstNode *n){
	//TODO: printTreePost()
	/*
	 * a recursive function that prints out the data in
	 * the tree in post-order
	 */
	if(n == NULL){
		return;
	}else{
		printTreePre(n->left);
		printTreePre(n->right);
		n->printNode();
	}
}

void bst::clearTree(){
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void bst::clearTree(bstNode *tmp){
	if (tmp == NULL) {
		return;
	}else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}

}

bstNode *bst::removeNoKids(bstNode *tmp){

}

bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){

}
bstNode *bst::remove(string f, string l){

}
void bst::setHeight(bstNode *n){
	while(n != root){
		n = n->parent;
		if((n->right != NULL) && (n->left != NULL)){
			if((n->right->height < n->left->height)){
				n->height = n->left->height+1;
			}else{
				n->height = n->right->height+1;
			}
		}else if((n->right == NULL) && (n->left != NULL)){
			n->height = n->left->height + 1;
		}else if((n->right != NULL) && (n->left == NULL)){
			n->height = n->right->height + 1;
		}else if((n->right == NULL) && (n->left == NULL)){
			n->height = 1;
		}
	}
}
