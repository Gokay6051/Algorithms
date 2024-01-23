#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <cctype>
#include "StringToInteger(atoi).cpp"
#include <typeinfo>
#include <queue>

using namespace std;

Graph::Graph(int V) {
	ifstream Dfile("CityDistances.txt");
	ifstream Nfile("adjacent_cities.txt");
	string dist;
    string cityName;
    //CityDistances.txt dosyasi satirlari
	string line;
	//adjacent_cities.txt dosyasi satirlari
	string line2;
	//stoi objesi
	Solution obj;
	
    if (!Dfile.is_open() || !Nfile.is_open()) 
        cout << "Dosya acilamadi!" << endl;
      
    // Ýlk satýrý oku 
    getline(Dfile, line);
    

    istringstream Diss(line);
    string part;
    while (getline(Diss, part, ';')) {
        // "Plate Number;City Name;" kýsmýný atladýk
        if (part == "City Name") {
            break;
        }
    }
    
    // Þehir isimlerini ";" karakterine göre parçala LinkedList UCSCities ve vectorune ekle
    while (getline(Diss, cityName, ';')) {
    	LinkedList newCity;
        newCity.addNode(cityName, 0);
        cities.push_back(newCity);
        
        //UCSCitiese ekleniyor
        UCSCities ucsobj;
        ucsobj.cityName = cityName;
        ucsobj.cost = 0;
        ucsobj.comeFrom = "-";
        ucsobj.visited=false;
        ucs.push_back(ucsobj);
    }
    
    int k=0;
    //komsu sehirler ekleniyor
    while(getline(Nfile, line2)){ 	
    	getline(Dfile, line);
    	istringstream Niss(line2);
    	//adjacent_cities dosyasýndan ilk sehri atliyorum
    	getline(Niss, cityName, ',');	
    	string cityName2;
    	
    	while (getline(Niss,cityName2, ',')) {
    		int i;
    		LinkedList linkedList = cities[k];
    		istringstream Diss(line);
    		//city_distances kismindan þehir ve plakayi atliyorum
    		getline(Diss, dist, ';');
    		getline(Diss, dist, ';');	
    		//Adana ----> adana, bas harfler kücültülüyor
    		cityName2[0] = tolower(cityName2[0]);
    		
    		
    		for(i=0; i<V; ++i){
    			LinkedList linkedList2 = cities[i];
    			
    			if(linkedList2.head->cityName == cityName2){	
    				for(int j=0; j<=i; ++j){
						getline(Diss, dist, ';');
					}
					linkedList.addNode(cityName2, obj.myAtoi(dist));
    				break;
				}		
			}
    	}
		//Kacinci sehrin komsularini ekliyoruz onun icin (plaka-1)	
    	++k;
	}	
	/*
	for(int i=0; i<V; ++i){
		string str1= ucs[i].cityName;
		string str2= ucs[i].comeFrom;
		int integer = ucs[i].cost;
		cout << str1 << " " << str2 << " " << integer << endl;
	}	
   	*/
   	Nfile.close();
    Dfile.close();
}

int Graph::UCS(string startCity, string destinationCity){
	LinkedList startCityLL;
	UCSCities startCityUCS;
	UCSCities cityUCS;
	Node* nextCity;
	
	//cities vectorunden startCity'i bulma ve startCityLL'e atma
	startCityLL = FindStartCity(startCity);	
	
	//startCity visited hale getiriliyor
	startCityUCS = VisitStartCity(startCityLL);
	
	//Komsu sehirlerin eger gerekliyse costlarini guncelleme
	UpdateNeighbours(startCityLL, startCityUCS);
	
	//bir sonraki sehir
	cityUCS = FindNextCity();
		
	//hedeflenen þehirse toplam mesafeyi döndür
	if(cityUCS.cityName == destinationCity){ 
		return cityUCS.cost;
	}
	
	//cout << cityUCS.cityName << "  " << destinationCity << " "  << endl << endl;
	int dist = UCS(cityUCS.cityName, destinationCity);
	
	ResetUCS();
	return dist;
}

void Graph::ClosestCities(string startCity, int K){
	if(K == 0) {
		return;
	}
	LinkedList startCityLL;
	UCSCities startCityUCS;
	UCSCities cityUCS;
	Node* nextCity;
	
	//cities vectorunden startCity'i bulma ve startCityLL'e atma
	startCityLL = FindStartCity(startCity);	
	
	//startCity visited hale getiriliyor
	startCityUCS = VisitStartCity(startCityLL);
	
	//Komsu sehirlerin eger gerekliyse costlarini guncelleme
	UpdateNeighbours(startCityLL, startCityUCS);
	
	//bir sonraki sehir
	cityUCS = FindNextCity();
	
	cout << "-" <<cityUCS.cityName << "  " << cityUCS.cost << "km  ";
	ClosestCities(cityUCS.cityName, K-1);
	
	ResetUCS();
}

//cities vectorunden startCity'i bulma ve startCityLL'le döndürme
LinkedList Graph::FindStartCity(string startCity) {
	LinkedList startCityLL;
	for(int i=0; i<81; ++i){
		startCityLL = cities[i];
		if(startCityLL.head->cityName == startCity){
			break;
		}	
	}
	return startCityLL;
}

//startCity visited hale getiriliyor
UCSCities Graph::VisitStartCity(LinkedList startCityLL) {
	Node* iter = startCityLL.head;
	int i;
	for(i=0; i<81; ++i){ 
		if(ucs[i].cityName == iter->cityName){
			ucs[i].visited = true;
			ucs[i].comeFrom = ucs[i].cityName;
			break;
		}		
	}
	return ucs[i];
}

//Komsu sehirlerin eger gerekliyse costlarini guncelleme
void Graph::UpdateNeighbours(LinkedList startCityLL, UCSCities startCityUCS) {
	UCSCities cityUCS;
	Node* iter = startCityLL.head->next;
	while(iter != NULL) {
		bool flag=false;
		int i;
		//komsu sehri ucs'ten bul
		for(i=0; i<81; ++i){ 
			cityUCS = ucs[i];
			if(cityUCS.cityName == iter->cityName){
				flag=true;
				break;
			}		
		}
		if(flag == true && ucs[i].visited == false && (ucs[i].cost == 0 || ucs[i].cost > iter->edge + startCityUCS.cost)){
			ucs[i].comeFrom = startCityLL.head->cityName;
			ucs[i].cost = iter->edge + startCityUCS.cost;
		}
		iter = iter->next;
	}
}

//bir sonraki sehir
UCSCities Graph::FindNextCity(){
	UCSCities cityUCS;
	int min = 3000;
	
	for(int i=0; i<81; ++i){
		if(ucs[i].comeFrom != "-" && ucs[i].cost<min && ucs[i].visited == false){	
			min = ucs[i].cost;
			cityUCS = ucs[i];
			//cout << cityUCS.cityName << " " << cityUCS.cost << " " << min << endl; 
		}	
	}
	
	return cityUCS;
}

//Reset ucs
void Graph::ResetUCS(){
	for(int i=0; i<81; ++i){
		ucs[i].comeFrom = "-";
		ucs[i].cost = 0;
		ucs[i].visited = false;
	}
}

int Graph::Stoi(string plate){
	Solution obj;
	return obj.myAtoi(plate);
}
