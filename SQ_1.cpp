struct Node
{
	int data;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

Node* CreateNode(int data)
{
	Node *p;
	p = new Node();
	p->data = data;
	p->pNext = NULL;
	return p;
}

void PushFront(List &l, Node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

bool IsEmpty(List l)
{
	return (l.pHead == NULL);
}

void Pop(List &l)
{
	if (IsEmpty(l))
	{
		cout << "Stack rong." << endl;
		return;
	}

	Node *p;

	p = l.pHead;
	l.pHead = l.pHead->pNext;
	if (l.pHead == NULL)
		l.pTail = NULL;
	delete p;
}

void Input(List &l, int x)
{
	int n;

	while (true)
	{
		cin >> n;
		if (n == 0)
			return;

		if (n != x)
		{
			Node *p = CreateNode(n);
			PushFront(l, p);
		}
		else
		{
			Pop(l);
		}
	}

	if (IsEmpty(l))
		cout << "Stack rong.";
}

void Output(List l)
{
	cout << "Cac gia tri co trong stack la:";
	for (Node *p = l.pHead; p != NULL; p = p->pNext){
		cout << " " << p->data;
	}
}
int main()
{
	List l;
	CreateList(l);
	int x;
	cin >> x;
	Input(l, x);
	if (IsEmpty(l))
		cout << "Stack rong.";
	else
		Output(l);
	return 0;
}
