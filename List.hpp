#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	Node();
	string data;
	Node* next;
};

class List {
public:
	List();
	void insert(string newData);
	string getRandomNode();

private:
	Node* head;
};

class DecisionTreeNode {
public:
	List jokes;
	List facts;
	DecisionTreeNode* left;
	DecisionTreeNode* right;
};

#endif LIST_H