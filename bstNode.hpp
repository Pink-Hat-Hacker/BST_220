/*
 * bstNode.hpp
 *
 *  Created on: Oct 20, 2021
 *      Author: pinkhathacker
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_

#include <stdlib.h>
#include <iostream>

#include "Student.hpp"

using namespace std;

class bstNode{

	friend class bst;
	friend class TreeInterface;
	bstNode *left;
	bstNode *right;
	bstNode *parent;
	int height;
	Student *student;

public:
	bstNode();
	bstNode(string f, string l, int n, string j);
	~bstNode();
	void printNode();
};

#endif /* BSTNODE_HPP_ */
