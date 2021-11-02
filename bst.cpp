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

	bstNode *insert = new bstNode(f, l, n, j);
	bstNode *temp2 = root;
	if(temp2 == NULL){
		root = insert;
		setHeight(insert);
		return true;
	}else{
		while(temp2 != NULL){
			if((insert->student->last) < (temp2->student->last)){
				if(temp2->left == NULL){
					temp2->left = insert;
					insert->parent = temp2;
					setHeight(insert);
					return true;
				}else{
					temp2 = temp2->left;
				}
			}else if((insert->student->last) > (temp2->student->last)){
				if(temp2->right == NULL){
					temp2->right = insert;
					insert->parent = temp2;
					setHeight(insert);
					return true;
				}else{
					temp2 = temp2->right;
				}
			}else if((insert->student->last) == (temp2->student->last)){
				if((insert->student->first) == (temp2->student->first)){
					return false;
				}else{
					if((insert->student->first) < (temp2->student->first)){
						if(temp2->left == NULL){
								temp2->left = insert;
								insert->parent = temp2;
								setHeight(insert);
								return true;
							}else{
								temp2 = temp2->left;
							}
					}else if((insert->student->last) > (temp2->student->last)){
						if(temp2->right == NULL){
							temp2->right = insert;
							insert->parent = temp2;
							setHeight(insert);
							return true;
						}else{
							temp2 = temp2->right;
						}
					}
				}
			}
		}
	}
	return false;
}

bstNode *bst::find(string l, string f){
	//TODO: *bst::find()
	/*
	 * finds whether a student with the last name l and first
	 * name f is in the tree is in the tree, and, if it is, returns the node holding that
	 * student. Otherwise it returns NULL.
	 */
	//this is me
	bstNode *current = root;
	//bstNode *temp = current;
	if(current == NULL){
		return NULL;
	}else{
		while(current != NULL ){
			if(current->student->last < l){
				current = current->right;
			}else if(current->student->last > l){
				current = current->left;
			}else {
				if (current == NULL) {
					cout << "first null check" << endl;
					return NULL;
				}else {
					if((current->student->first == f) && (current->student->last == l)){
						cout << "test" << endl;
						current->printNode();
						cout << "test" << endl;
						return current;
					}else if(current->student->last == l && current->student->first != f){
						if(current->student->first < f){
							current = current->right;
	//						if(current->student->last == l && current->student->first == f){
	//							cout << "if equal -- " << current->student->first << " " << current->student->last << endl;
	//							current->printNode();
	//							return current;
	//						}
						}else if(current->student->first > f){
							current = current->left;
							//cout << current->right->student->first<<endl;
	//						if(current != NULL && current->student->last == l && current->student->first == f){
	//							cout << "last if" << endl;
	//
	//							current->printNode();
	//							return current;
	//						}
						}
		//				if(current->left != NULL){
		//					current = current->left;
		//				}else if(current->right != NULL){
		//					current = current->right;
		//				}
					}
				}
			}
		}
	}
	cout << current<< endl;
	return current;
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
	/*
	 * for removing a node with no children
	 */
    if(tmp->parent->student->last == tmp->student->last){
    	if(tmp->student->first > tmp->parent->student->first){
				tmp->parent->right = NULL;
		 }else{
			 tmp->parent->left = NULL;
		 }
    }else if(tmp->student->last > tmp->parent->student->last){
    	tmp->parent->right = NULL;
    }else{
    	tmp->parent->left = NULL;
    }
    setHeight(tmp->parent);
    return tmp;
}

bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){
	/*
	 * for removing a node with one child, with the leftFlag
	 * indicating whether the node’s child is either the left child
	 * or the right child.
	 */
	if(tmp->parent->left == tmp){
		if(leftFlag == true){
			tmp->parent->left = tmp->left;
			tmp->left->parent = tmp->parent;
		}else{
			tmp->parent->left = tmp->right;
			tmp->right->parent = tmp->parent;
		}
		bstNode *current = tmp;
		while(current->left != NULL){
			current = current->left;
		}
		setHeight(current);
	}else{
		if(leftFlag == true){
			tmp->parent->right = tmp->left;
			tmp->left->parent = tmp->parent;
		}else{
			tmp->parent->right = tmp->right;
			tmp->right->parent = tmp->parent;
		}
		bstNode *current = tmp;
		while(current->right != NULL){
			current = current->right;
		}
		setHeight(current);
	}
	return tmp;
}

bstNode *bst::remove(string l, string f){
	/*
	 * this method removes a node from the tree, and
	 * returns that node. There are 3 cases when you remove a node: either the node being
	 * removed has no children (left or right), in which case this method calls the method
	 * removeNoKids, the node you are removing has only one child, in which case the method
	 * calls removeOneKid (with a Boolean flag set to true if there is a left child, and
	 * false if there is a right child), or the node being removed has both a left and a
	 * right child, in which you replace the node being removed with the appropriate
	 * replacement child, and then remove the node used as a replacement by calling either
	 * removeNoKids or removeOneKid, depending on which is appropriate.
	 */
	//cout << "getting here" << endl;
	bstNode *current = find(l, f);
	//cout << current<<endl;
	//cout << "under find" << endl;
	//first case - no children
	if(current->left == NULL && current->right == NULL){
		//cout << "first case" << endl;
		return removeNoKids(current);
	//second case -
	}else if(current->left != NULL && current->right == NULL){
		//cout << "second case" << endl;
		return removeOneKid(current, true);
	}else if(current->left == NULL && current->right != NULL){
		return removeOneKid(current, false);
	//third case - has two children
	}else if(current->left != NULL && current->right != NULL){
		//cout << "third case" << endl;
		//find the rightmost
		bstNode *temp = current;
		while(temp->right != NULL){
				temp = temp->right;
		}
		if(temp->left == NULL && temp->right == NULL){
			removeNoKids(temp);
		}else if(temp->left == NULL && temp->right != NULL){
			//right
			removeOneKid(temp, false);
		}else if(temp->left != NULL && temp->right == NULL){
			//left
			removeOneKid(temp, true);
		}

	}
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
