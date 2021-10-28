/*
 * bstNode.cpp
 *
 *  Created on: Oct 20, 2021
 *      Author: pinkhathacker
 */

#include "bstNode.hpp"
#include <iostream>
#include <stdlib.h>

#include <string.h>
using namespace std;

bstNode::bstNode(){
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 0;
	student = NULL;
}

bstNode::bstNode(string f, string l, int n, string j){
	student = new Student(f, l, n, j);
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	//student = NULL;
}

void bstNode::printNode(){
	cout << "Height of node: " << height << endl;
	cout << "Name: " << student->first << " " << student->last << endl;
	cout << "Humor: " << student->joke;
}

bstNode::~bstNode(){
	//TODO: Destructor
	cout << "Delete " << student->first<<" "<<student->last << endl;

}

