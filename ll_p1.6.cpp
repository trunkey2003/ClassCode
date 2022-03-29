void nhap(List &li)
{
    int x;
    do
    {
        cin >> x;
        if (x == 0)
            return;
        if (li.pHead == NULL)
        {
            node *p = new node;
            p->info = x;
            p->pNext = NULL;
            li.pTail = p;
            li.pHead = li.pTail;
        }
        else
        {
            node *p = new node;
            p->info = x;
            p->pNext = NULL;
            li.pTail->pNext = p;
            li.pTail = p;
        }
    } while (x != 0);
}

void ReverseList(List& l){
    node* rHead = NULL;
    node* rTail = NULL;
    node* llist = l.pHead;
    bool firstTime = true;
    while (llist){
        node *p = new node;
        p->info = llist->info;
        p->pNext = rHead;
        if (firstTime){
            rTail = p;
            firstTime = false;
        }
        rHead = p;
        llist = llist->pNext;
    }
    l.pHead = rHead;
}

void xuat(List l)
{
    if (!l.pHead) return; 
    node *p = l.pHead;
    cout << p->info << " ";
    while (p->pNext != NULL)
    {
        p = p->pNext;
        cout << p->info << " ";
    };
}
