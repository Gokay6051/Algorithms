#include<iostream>

using namespace std;

class Node{
	public:
		Node *next;
		int data;
		
		Node(int num): data(num), next(NULL) {}
};

class LinkedList{
	private:
		Node *head;
		
		void ReversePrint(Node *p) {
			if(p == NULL){
				return;
			}
			
			if(p->next != NULL) {
				ReversePrint(p->next);
			}
			cout << p->data << " ";
		}
		
	public:
		//Constructor
		LinkedList(): head(NULL) {}
		
		//Append a new Node
		void Append(int num) {
			if(head == NULL) {
				head = new Node(num);
				head->next = NULL;
			}
			else {
				Node *p = head;
				while(p->next != NULL){
					p = p->next;
				}
				p->next = new Node(num);
				p->next->next = NULL;
			}
		}
		
		//Print list datas
		void PrintList() {
			Node *p = head;
			
			while(p != NULL){
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
		
		//Ex: 1-1-5-6-6-6-7-8-7-7 ----> 1-5-6-7-8-7
		void Remove() {
			Node *p, *w;
			
			if(head != NULL && head->next != NULL) {
				p = head;
				w = p->next;
				
				while(w != NULL) {
					if(p->data == w->data) {
						p->next = w->next;
						//delete w; //Buna gerek var mi?
						w = p->next;
					}
					else{
						p = w;
						w = p->next;
					}
					
				}
			}
		}
		
		//Ex: 0-0-1-0-1-0-0-1-0-0 ----> 0-0-0-0-0-0-0-0-1-1-1
		void Rearrange() {
			Node *p, *w;
			
			if(head !=NULL && head->next != NULL) {
				p = head;
				
				while(p->next != NULL) {
					if(p->next->data == 0) {
						w = p->next->next;
						p->next->next = head;
						head = p->next;
						p->next = w;
					}
					else{
						p = p->next;
					}
				} 
			}
		}
		
		//Ex: 1-7-6-5-4-7-7 ----> 7-7-4-5-6-7-1
		void ReversePrint() {
			ReversePrint(this->head);
		}
};

int main() {
	LinkedList myList;
	
	myList.Append(5);
	myList.Append(4);
	myList.Append(3);
	myList.Append(2);
	myList.Append(1);
	
	
	//Original list
	myList.PrintList();
	//List after Rearrange function
	myList.ReversePrint();
	
	return 0;
}


