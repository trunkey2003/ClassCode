#include <iostream>
// #include <fstream>
// note that 0 == NULL

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList
{
    int length;
    Node *head;
    Node *tail;

    int operator()(int index)
    {
        if (index > length - 1 || length == 0)
            exit(1);
        if (index == 0)
            return head->data;
        Node *p = head;
        int i = 0;
        while (i < index)
        {
            p = p->next;
            i++;
        }
        int res = p->data;
        return res;
    }

    void display()
    {
        if (length == 0)
            return;
        Node *p = head;
        int arr[50000] = {0};
        int arr2[50000];
        int arr3[50000] = {0};
        int count = 0;
        int count2 = 0;
        int i = 0;
        while (i < length)
        {
            arr[count] = p->data;
            count++;
            arr3[p->data] = arr3[p->data] + 1;

            if (!checkDuplicated(p->data, arr2, count2)){
                arr2[count2] = p->data;
                count2++;
            }
            p = p->next;
            i++;
        }
        for (int i = 0; i < count; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "So lan xuat hien cua tung phan tu trong danh sach la:" << endl;
        for (int i = 0; i < count2; i++){
            cout << arr2[i] << ": " << arr3[arr2[i]] << endl;
        }
    }

    LinkedList()
    {
        length = 0;
        head = NULL;
        tail = NULL;
    }

    void push_front(int data)
    {
        if (data == 0)
            return;
        if (head == NULL)
        {
            Node *p = new Node(data);
            head = p;
            tail = head;
        }
        else
        {
            Node *p = new Node(data);
            p->next = head;
            p->data = data;
            head = p;
        }
        length++;
    }

    void push_back(int data)
    {
        if (data == 0)
        {
            cout << "Danh sach rong.";
            exit(1);
        }

        if (head == NULL)
        {
            Node *p = new Node(data);
            tail = p;
            head = tail;
        }
        else
        {
            Node *p = new Node(data);
            tail->next = p;
            tail = p;
        }
        length++;
    }

    bool checkDuplicated(int a, int* b, int length)
    {
        if (length== 0)
            return 0;
        for (int j = 0; j < length; j++)
        {
            if (a == b[j])
                return 1;
        }
        return 0;
    }
};

void Input(LinkedList &a)
{
    // ifstream ifs("test.txt");
    int x;
    do
    {
        cin >> x;
        if (x)
            a.push_back(x);
    } while (x != 0);
}

void Output(LinkedList a)
{
    if (a.length == 0)
    {
        cout << "Danh sach rong.";
        exit(0);
    }

    cout << "Danh sach vua nhap la: ";

    a.display();



    // a.findUniqueIndexAndDisplay();
}

int main()
{
    LinkedList a;
    Input(a);
    Output(a);
    return 0;
}
