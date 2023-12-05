#include "List.hpp"

Node::Node(): next(nullptr) {}

List::List() : head(nullptr) {}

void List::insert(string newData) {
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
}

string List::getRandomNode() {
	vector <Node*> nodes;
	Node* current = head;
	while (current != nullptr)
	{
		nodes.push_back(current);
		current = current->next;
	}

	srand(time(nullptr)); // Seed for random number generator
	int index = rand() % nodes.size(); // Hashing to get a random index
	return nodes[index]->data;
}