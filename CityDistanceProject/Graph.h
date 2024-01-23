#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>



// Forward declaration
class LinkedList;
//class Node;

using namespace std;

struct UCSCities{
	//initially all cities' comeFrom = "-"
	string comeFrom;
	string cityName;
	int cost;
	bool visited;
};

class Graph{
public:
    vector<LinkedList> cities;
    vector<UCSCities> ucs;
    //txt dosyalarindan Graph olusturuyor
    Graph(int V);
    int UCS(string startCity, string destinationCity);
    void ClosestCities(string startCity, int K);
    //cities vectorunden startCity'i bulma ve startCityLL'le döndürme
    LinkedList FindStartCity(string startCity);
    //startCity visited hale getiriliyor
   	UCSCities VisitStartCity(LinkedList startCityLL);
   	//Komsu sehirlerin eger gerekliyse costlarini guncelleme
   	void UpdateNeighbours(LinkedList startCityLL, UCSCities startCityUCS);
   	//bir sonraki sehir
   	UCSCities FindNextCity();
   	//Reset ucs
   	void ResetUCS();
   	int Stoi(string plate);
};

#endif
