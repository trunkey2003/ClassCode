if (s == "")
	{
		cout << "Chuoi rong.";
		exit(1);
	}
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != c)
			{
				enqueue(queue, s[i]);
			}
			else
			{
				dequeue(queue);
			}
		}
		cout << endl;
		if (isEmpty(queue) == true)
			cout << "Hang doi rong.";
		else
		{
			Xuat(queue);
		}
	}
	return 0;
}

void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

node *CreateNode(char info)
{
	node *p;
	p = new node();
	p->info = info;
	p->pNext = NULL;
	return p;
}

void AddTail(List &l, node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

bool isEmpty(List l)
{
	return (l.pHead == NULL);
}

void enqueue(List &l, char x)
{
	node *p = CreateNode(x);
	AddTail(l, p);
}

int dequeue(List &l)
{
	if (isEmpty(l)) return 0;
	cout << l.pHead->info;
	node *p;
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	if (l.pHead == NULL) l.pTail = NULL;
	delete p;
	return 1;
}

void Xuat(List l)
{
	cout << "Cac gia tri co trong hang doi la: ";
	node *p = l.pHead;
	for (node *p = l.pHead; p != NULL; p = p->pNext){
		cout << p->info;
	}
}
