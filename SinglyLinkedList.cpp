#include <iostream>

using namespace std;

template <typename Type>
struct Node{
	Type data;
	Node* pNext;
	Node(){
		
	}
	Node(Type data){
		this->data = data;
		pNext = NULL;
	}

    Node(Node* node){
        data = node->data;
        pNext = node->pNext;
    }
};

template <typename Type>
struct SinglyLinkedList{
	int length;
	Node<Type>* pHead;
    Node<Type>* pTail;
	
	SinglyLinkedList(){
		pHead = NULL;
        pTail = NULL;
		length = 0;
	}

	Type operator[](int index){
		if (index > length - 1 || length == 0) return -123456789;
		if (index == 0) return pHead->data;

        //init p = pHead;
		Node<Type>* p (pHead);
		int i = 0;
	 	while (i < index){
	 		p = p->pNext;
			i++;
		}
		return p->data;
	}
	
	void push_back(Type data){
		if (pHead == NULL)
        {
            Node<Type> *p = new Node<Type>(data);
            pTail = p;
            pHead = pTail;
        }
        else
        {
            Node<Type> *p = new Node<Type>(data);
            pTail->pNext = p;
            pTail = p;
        }
        length++;
	}

	
	void push_front(Type data){
		Node<Type>* p = new Node<Type>(data);
		if (pHead == NULL)
        {
            Node<Type> *p = new Node<Type>(data);
            pHead = p;
            pTail = pHead;
        }
        else
        {
            Node<Type> *p = new Node<Type>(data);
            p->pNext = pHead;
            pHead = p;
        }
        length++;
	}

    void erase(Type x){
        //init p = pHead;
        Node<Type> *p (pHead);
        //mark to delete
        Node<Type> *mark;

        int i = 0;
        while (p){
            if (p->pNext && p->pNext->data == x){
                mark = p->pNext;
                p->pNext = p->pNext->pNext;
                delete mark;
                length--;
                return;
            }
            i++;
            p = p->pNext;
        }
    }

    void eraseAll(Type x){
        //init p = pHead;
        Node<Type> *p (pHead);
        //mark to delete
        Node<Type> *markBegin;
        Node<Type> *markDelete[length];
        int needToDelete = 0;
        while (p){
            if (p->pNext && p->pNext->data == x){
                //mark the begin
                markBegin = p;
                markDelete[needToDelete] = p->pNext;
                needToDelete++;
                    while (p->pNext && p->pNext->data == x){
                        p = p->pNext;
                    }
                p = p->pNext;
                if (p) markBegin->pNext = p; else markBegin->pNext = NULL;
                // return;
            }
            if (p) p = p->pNext;
        }

        //free node memory
        for (int i = 0; i < needToDelete; i++){
            delete markDelete[i];
        }

        //ensure delete pHead == x
        if (pHead->data == x) {
            markDelete[0] = pHead;
            pHead = pHead->pNext;
            delete markDelete[0];
        }
    }

    void change(Type x, Type y){
        Node<Type> *p (pHead);
        Node<Type> *markX(NULL);
        Node<Type> *temp(NULL);
        while (p){
            if (p->data == x) {
                markX = p;
                break;
            }
            p = p->pNext;
        }

        if (!markX) {
            return;
        } 
        markX->data = y;        
    }
};

template <typename Type>
void Input(SinglyLinkedList<Type> l){

}

template <typename Type>
void Output(SinglyLinkedList<Type> l){
    cout << "[";
    for (Node<Type>* iterator = l.pHead; iterator != NULL; iterator = iterator->pNext){
        cout << iterator->data;
        if (iterator != l.pTail) cout << ",";
    }
    cout << "]";
}
