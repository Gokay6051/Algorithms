#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"
#include "LinkedList.h"


using namespace std;

void LinkedList::addNode(const string& city, const int& distance){
	Node* newNode = new Node;
	newNode->cityName = city;
    newNode->edge = distance;  
    newNode->next = NULL;
	
	//cout << city << " eklendi!" << endl;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* iter = head;
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = newNode;
    }
}

void LinkedList::printNeighbours() {
    Node* iter = head;
	
	cout << iter->cityName << " sehrinin komsulari:" << endl;
	iter = iter->next;
    while (iter != NULL) {
        cout << iter->cityName << " " << iter->edge << endl;
        iter = iter->next;
    }
}
