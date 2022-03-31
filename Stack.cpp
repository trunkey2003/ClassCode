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
struct Stack
{
    int length;
    Node<Type> *pHead;
    Node<Type> *pTail;

    Stack()
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

    void push(Type data)
    {
        Node<Type> *p = new Node<Type>(data);
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

    Type pop()
    {
        if (!pHead)
        {
            cout << "Empty Stack";
            exit(1);
        }
        Type top;
        // mark to delete
        Node<Type> *mark(pHead);
        top = pHead->data;
        pHead = pHead->pNext;
        delete mark;
        return top;
    }

    Type top()
    {
        if (!pHead)
        {
            cout << "Empty Stack";
            exit(1);
        }
        return pHead->data;
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

    bool isEmpty()
    {
        return (pHead == NULL);
    }
};

template <typename Type>
void Input(Stack<Type> s)
{
}

template <typename Type>
void Output(Stack<Type> s)
{
    cout << "[";
    for (Node<Type> *iterator = s.pHead; iterator != NULL; iterator = iterator->pNext)
    {
        cout << iterator->data;
        if (iterator != s.pTail)
            cout << ",";
    }
    cout << "]";
}
