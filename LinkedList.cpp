#include <iostream>

using namespace std;

template <typename Type>
struct Node{
	Type data;
	Node* next;
	Node(){
		
	}
	Node(Type data){
		this->data = data;
		next = NULL;
	}
};

template <typename Type>
struct LinkedList{
	int length;
	Node<Type>* head;
	
	Type operator[](int index){
		if (index > length - 1 || length == 0) return 0;
		if (index == 0) return head->data;
		Node<Type>* p = head;
		int i = 0;
	 	while (i < index){
	 		p = p->next;
			i++;
		}
		return p->data;
	}
	
	LinkedList(){
		head = NULL;
		length = 0;
	}
	
	void push_back(Type data){
		if (data == 0) return;
		Node<Type>* temp = new Node<Type>(data);
		Node<Type>* p;
		if (head == NULL){
			head = temp;
		} else {
			p = head;
			while (p->next != NULL){
				p = p->next;
			}
			p->next = temp;
		}
		length++;
	}

	
	void push_front(Type data){
		if (data == 0) return;
		Node<Type>* temp = new Node<Type>(data);
		temp->next = head;
        head = temp;
        length++;
	}
};
