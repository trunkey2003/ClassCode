int n;
	while (x > 0)
	{
		n = x % 2;
		x = x / 2;
		enstack(st, n);
	}

	for (node* p = st.pHead; p != NULL; p = p->pNext){
		cout << p->info;
	}
}

bool isEmpty(List l)
{
	return (l.pHead == NULL);
}

node *Createnode(int info)
{
	node *p;
	p = new node();
	p->info = info;
	p->pNext = NULL;
	return p;
}

void AddHead(List &l, node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void enstack(List &l, int x)
{
	node *p = Createnode(x);
	AddHead(l, p);
}

void destack(List &l)
{
	node *p;
	if (isEmpty(l))
		return;
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
