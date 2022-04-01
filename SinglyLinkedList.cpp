#include <iostream>

using namespace std;

template <typename Type>
struct Node
{
    Type data;
    Node *pNext;
    Node()
    {
    }
    Node(Type data)
    {
        this->data = data;
        pNext = NULL;
    }

    Node(Node *node)
    {
        data = node->data;
        pNext = node->pNext;
    }
};

template <typename Type>
struct SinglyLinkedList
{
    int length;
    Node<Type> *pHead;
    Node<Type> *pTail;

    SinglyLinkedList()
    {
        pHead = NULL;
        pTail = NULL;
        length = 0;
    }

    Type operator[](int index)
    {
        if (index > length - 1 || length == 0)
            return -123456789;
        if (index == 0)
            return pHead->data;

        // init p = pHead;
        Node<Type> *p(pHead);
        int i = 0;
        while (i < index)
        {
            p = p->pNext;
            i++;
        }
        return p->data;
    }

    void push_back(Type data)
    {
        Node<Type> *p = new Node<Type>(data);
        if (pHead == NULL)
        {
            pTail = p;
            pHead = pTail;
        }
        else
        {
            pTail->pNext = p;
            pTail = p;
        }
        length++;
    }

    void push_front(Type data)
    {
        Node<Type> *p = new Node<Type>(data);
        if (pHead == NULL)
        {
            pHead = p;
            pTail = pHead;
        }
        else
        {
            p->pNext = pHead;
            pHead = p;
        }
        length++;
    }

    void erase(Type x)
    {
        // init p = pHead;
        Node<Type> *p(pHead);
        // mark to delete
        Node<Type> *mark;

        int i = 0;
        while (p)
        {
            if (p->pNext && p->pNext->data == x)
            {
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

    void eraseAll(Type x)
    {
        // init p = pHead;
        Node<Type> *p(pHead);
        // mark to delete
        Node<Type> *markBegin;
        Node<Type> *markDelete[length];
        int needToDelete = 0;
        while (p)
        {
            if (p->pNext && p->pNext->data == x)
            {
                // mark the begin
                markBegin = p;
                markDelete[needToDelete] = p->pNext;
                needToDelete++;
                while (p->pNext && p->pNext->data == x)
                {
                    p = p->pNext;
                }
                p = p->pNext;
                if (p)
                    markBegin->pNext = p;
                else
                    markBegin->pNext = NULL;
                // return;
            }
            if (p)
                p = p->pNext;
        }

        // free node memory
        for (int i = 0; i < needToDelete; i++)
        {
            delete markDelete[i];
        }

        // ensure delete pHead == x
        if (pHead->data == x)
        {
            markDelete[0] = pHead;
            pHead = pHead->pNext;
            delete markDelete[0];
        }
    }

    void change(Type x, Type y)
    {
        Node<Type> *p(pHead);
        Node<Type> *markX(NULL);
        Node<Type> *temp(NULL);
        while (p)
        {
            if (p->data == x)
            {
                markX = p;
                break;
            }
            p = p->pNext;
        }

        if (!markX)
        {
            return;
        }
        markX->data = y;
    }

    void swap(Node<Type>* p1, Node<Type>* p2)
    {
        Type temp = p1->data;
        p1->data = p2->data;
        p2->data = temp;
    }

    void swap(Node<Type>& n1, Node<Type>& n2)
    {
        Type temp = n1.data;
        n1.data = n2.data;
        n2.data = temp;
    }

    void swap(int x, int y){
        if (x > length - 1 || y > length - 1) return;
        int max = (x > y)? x : y;
        Node<Type> *p(pHead);
        Node<Type> *px(NULL);
        Node<Type> *py(NULL);
        int i = 0;
        while (p)
        {
            if (x == i) {
              px = p;  
            }

            if (y == i){
              py = p;  
            }

            if (max == i) break;

            i++;
            p = p->pNext;
        }

        swap(px, py);
    }
};

template <typename Type>
void Input(SinglyLinkedList<Type> l)
{
}

template <typename Type>
void Output(SinglyLinkedList<Type> l)
{
    cout << "[";
    for (Node<Type> *iterator = l.pHead; iterator != NULL; iterator = iterator->pNext)
    {
        cout << iterator->data;
        if (iterator != l.pTail)
            cout << ",";
    }
    cout << "]";
}
