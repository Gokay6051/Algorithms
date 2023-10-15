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
		
	public:
		LinkedList(): head(NULL) {}
		
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
		
		void PrintList() {
			Node *p = head;
			
			while(p != NULL){
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
		
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
};

int main() {
	LinkedList myList;
	/*
	myList.Append(1);
	myList.Append(1);
	myList.Append(1);
	myList.Append(5);
	myList.Append(2);
	myList.Append(5);
	myList.Append(2);
	myList.Append(5);
	myList.Append(5);
	myList.Append(5);
	myList.Append(4);
	myList.Append(4);
	myList.Append(1);
	myList.Append(4);
	myList.Append(4);
	myList.Append(5);
	myList.Append(5);
	myList.Append(5);
	myList.Append(1);
	myList.Append(6);
	myList.Append(6);
	
	//Original list
	myList.PrintList();
	
	//List after Remove function
	myList.Remove();
	myList.PrintList();
	*/
	
	myList.Append(0);
	myList.Append(0);
	myList.Append(0);
	myList.Append(1);
	myList.Append(0);
	myList.Append(1);
	myList.Append(1);
	myList.Append(0);
	myList.Append(0);
	myList.Append(1);
	myList.Append(1);

	
	//Original list
	myList.PrintList();
	//List after Rearrange function
	myList.Rearrange();
	myList.PrintList();
	
	
	return 0;
}


