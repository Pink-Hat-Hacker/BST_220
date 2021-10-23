/*
 * bst.cpp
 *
 *  Created on: Oct 20, 2021
 *      Author: pinkhathacker
 */

#include "bst.hpp"
#include "bstNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


bst::bst(){
	root=NULL;
}
bst::bst(string f, string l, int n, string j){
	root = new bstNode( f,l, n, j);
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
}

bstNode *bst::find(string l, string f){

}
void bst::printTreeIO(){

}
void bst::printTreeIO(bstNode *n){

}
void bst::printTreePre(){

}
void bst::printTreePre(bstNode *n){

}
void bst::printTreePost(){

}
void bst::printTreePost(bstNode *n){

}

void bst::clearTree(){
	if (root == NULL) {
	cout << "Tree already empty" << endl;
	}
	else {
	cout << endl << "Clearing Tree:" << endl;
	clearTree(root);
	root = NULL;
	}
}

void bst::clearTree(bstNode *tmp){
	if (tmp == NULL) {
	return;
	}
	else {
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

}
