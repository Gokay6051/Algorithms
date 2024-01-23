#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Forward declaration
class Graph;

using namespace std;

class Node {
public:
    string cityName;
    //bir onceki sehir ile uzakligi
    int edge;
    Node* next;
    /*
    // priority_queue'ya eklenen öðelerin karþýlaþtýrýlmasý için gerekli operatör
    bool operator<(const Node& other) const {
        return distance > other.distance;  // Büyükten küçüðe sýralama için ters sýralama yapýlýyor
    }

    // const üye fonksiyon
    int getDistance() const {
        return distance;
    }*/
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    void addNode(const string& city, const int& distance);
    void printNeighbours();
};

#endif
