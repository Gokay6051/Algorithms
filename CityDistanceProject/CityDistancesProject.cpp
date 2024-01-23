#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include "Graph.h"
#include "LinkedList.h"
#include "Graph.cpp" 

using namespace std;

int main() {
	Graph graph(81);
	int choice;
	string startCity = "";
	string destinationCity;
	int kClosest;
	int dist;
	int plate;
	
    do {
        // Menu
    	cout << endl << "Menu:" << endl;
        cout << "1. Enter city(or select)" << endl;
        cout << "2. Print selected(or entered) city" << endl;
        cout << "3. List k closest  cities (to selected city)" << endl;
        cout << "4. Find Shortest Path" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	system("cls");
            	cout << "sehir giriniz: ";
                cin >> startCity;
                //plaka girilirse sehir ismine cevriliyor
                if (isdigit(startCity[0])) {
                	plate = graph.Stoi(startCity);
        			startCity = graph.ucs[plate-1].cityName;
    			}
                break;
                
            case 2:
            	system("cls");
            	if(startCity == ""){
            		cout << "Lutfen sehir seciniz!" << endl;
				}
				else{
					cout << startCity << endl;
				}
                break;
                
            case 3:
            	system("cls");
            	if(startCity == ""){
            		cout << "Lutfen sehir seciniz!" << endl;
				}
				else{
            		cout << "Lutfen kac sehir gormek istediginizi giriniz: ";
            		cin >> kClosest;
                	cout << startCity << "'e en yakin " << kClosest  <<" sehir: ";
                	graph.ClosestCities(startCity, kClosest);
				}
                break;
                
            case 4:
                system("cls");
            	if(startCity == ""){
            		cout << "Lutfen sehir seciniz!" << endl;
				}
				else{
					cout << "hedef sehri giriniz: ";
            		cin >> destinationCity;
            		if (isdigit(destinationCity[0])) {
                		plate = graph.Stoi(destinationCity);
        				destinationCity = graph.ucs[plate-1].cityName;
    				}
            		dist = graph.UCS(startCity, destinationCity);
	 				cout << startCity << " ve " << destinationCity << " arasindaki en kisa mesafe: " << dist << "km";
				}
                break;
                
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    
	return 0;
}
