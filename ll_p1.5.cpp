void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void NhapList(List &li)
{
    int x;
    do
    {
        cin >> x;
        if (x == 0)
            return;
        if (li.pHead == NULL)
        {
            Node *p = new Node;
            p->info = x;
            p->pNext = NULL;
            li.pTail = p;
            li.pHead = li.pTail;
        }
        else
        {
            Node *p = new Node;
            p->info = x;
            p->pNext = NULL;
            li.pTail->pNext = p;
            li.pTail = p;
        }
    } while (x != 0);
}

void XuatList(List l)
{
    if (!l.pHead) return; 
    Node *p = l.pHead;
    cout << p->info << " ";
    while (p->pNext != NULL)
    {
        p = p->pNext;
        cout << p->info << " ";
    };
}

void Split(List l, List &l1, List &l2)
{
    Node *p = l.pHead;
    int* arr1 = new int[5001]();
    int count = 0;
    bool isDuplicated = false;
    if (p->info % 2 == 0)
    {
        Node *p2 = new Node;
        p2->info = p->info;
        p2->pNext = NULL;
        l1.pTail = p2;
        l1.pHead = l1.pTail;
    }
    else
    {
        Node *p2 = new Node;
        p2->info = p->info;
        p2->pNext = NULL;
        l2.pTail = p2;
        l2.pHead = l2.pTail;
    }
    arr1[count] = p->info;
    count++;
    while (p->pNext != NULL)
    {
        isDuplicated = false;
        p = p->pNext;
        for (int i = 0; i < count; i++) {
            if (arr1[i] == p->info){
                isDuplicated = true;
                break;
            } 
        }
        arr1[count] = p->info;
        count++;
        if (isDuplicated) {
            continue;
        }   
        if (p->info % 2 == 0)
        {
            if (l1.pHead == NULL)
            {
                Node *p2 = new Node;
                p2->info = p->info;
                p2->pNext = NULL;
                l1.pTail = p2;
                l1.pHead = l1.pTail;
            }
            else
            {
                Node *p2 = new Node;
                p2->info = p->info;
                p2->pNext = NULL;
                l1.pTail->pNext = p2;
                l1.pTail = p2;
            }
        }
        else
        {
            if (l2.pHead == NULL)
            {
                Node *p2 = new Node;
                p2->info = p->info;
                p2->pNext = NULL;
                l2.pTail = p2;
                l2.pHead = l2.pTail;
            }
            else
            {
                Node *p2 = new Node;
                p2->info = p->info;
                p2->pNext = NULL;
                l2.pTail->pNext = p2;
                l2.pTail = p2;
            }
        }
    };
}

int DemSoPhanTu(List l)
{
    if (!l.pHead) return 0; 
    Node *p = l.pHead;
    int i = 1;
    while (p->pNext != NULL)
    {
        i++;
        p = p->pNext;
    };
    return i;
}
