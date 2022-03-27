#include <iostream>
//note that 0 == NULL

struct Node{
	int data;
	Node* next;
	Node(){
		
	}
	Node(int data){
		this->data = data;
	}
};

struct LinkedList{
	int length;
	Node* head;
    Node* tail;
	
	LinkedList(){
		length = 0;
        head = NULL;
        tail = NULL;
	}
	
	void push_front(int data){
		if (data == 0) return;
		if (head == NULL){
            Node* temp = new Node(data);
			head = temp;
            tail = head;
		} else {
            Node* p;
			p->next = head;
            p->data = data;
            head = p;
		}
		length++;
	}

	
	void push_back(int data){
		if (data == 0) return;
		if (head == NULL){
            Node* temp = new Node(data);
			tail = temp;
            head = tail;
		} else {
            Node* p;
			p->next = NULL;
            p->data = data;
            tail->next = p;
            tail = p;
		}
		length++;
	}
};
