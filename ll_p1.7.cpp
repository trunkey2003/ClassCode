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
};

void Input(LinkedList &a, int& y)
{
    int x;
    do
    {
        cin >> x;
        if (x)
            a.push_front(x);
    } while (x != 0);
    cin >> y;
}

void Output(LinkedList a, int x)
{
    if (a.length == 0)
    {
        cout << "Danh sach rong.";
        return;
    }
    Node* p = new Node;
    p = a.head;
    bool check = false;
    for (int i = 0; i < a.length; i++){
        if (p->data == x){
            check = true;
        }
        p = p->next;
    }

    if (!check) cout << "Khong tim thay " << x << " trong danh sach:" << endl;
    if (check && a.length == 1){
        cout << "Danh sach rong.";
        return;
    }

    bool check2 = false;
    p = a.head;
    for (int i = 0; i < a.length; i++){
        if (p->data == x && !check2) {
            check2 = true;
            p = p->next;
            continue;
        }
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    LinkedList a;
    int x;
    Input(a, x);
    Output(a, x);
}
