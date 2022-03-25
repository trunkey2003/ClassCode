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
	
	void push(Type data){
		Node<Type>* temp = new Node<Type>(data);
		temp->next = head;
		head = temp;
		length++;
	}
};
