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

    void displayList()
    {
        if (length == 0)
            return;
        Node *p = head;
        int i = 0;
        int count = 0;
        while (i < length)
        {
            cout << p->data << " ";
            if (isPrime(p->data) && i % 2 == 0) count++;
            p = p->next;
            i++;
        }
        cout << endl;
        cout << "Danh sach co "<< count <<" so nguyen to o vi tri le.";
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
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
            return;
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

bool checkDuplicated(int a, LinkedList b)
{
    if (b.length == 0)
        return 1;
    for (int j = 0; j < b.length; j++)
    {
        if (a == b(j))
            return 0;
    }
    return 1;
}

void Input(LinkedList &a)
{
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
        return;
    }

    cout << "Danh sach vua nhap la: ";

    a.displayList();

    // cout << endl;
    // cout << "So lan xuat hien cua tung phan tu trong danh sach la:" << endl;

    // LinkedList b;
    // int count = 0;

    // for (int i = 0; i < a.length; i++){
    // 	if (!checkDuplicated(a(i),b)) continue;
    // 	cout << a(i);
    // 	b.push_back(a(i));
    // 	count = 1;
    // 	for (int j = i+1; j < a.length; j++){
    // 		if (a(j) == a(i)) count++;
    // 	}
    // 	cout << ": " << count << endl;
    // }
}

int main()
{
    LinkedList a;
    Input(a);
    Output(a);
}
