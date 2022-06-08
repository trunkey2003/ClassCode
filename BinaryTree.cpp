struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(){};
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    };
};

typedef Node *Tree;

Node *CreateNode(int init)
{
    Node *p = new Node;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
};

void CreateTree(Tree &root)
{
    root = NULL;
};

void DestroyTree(Tree &root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
};

void AddNode(Tree &root, Node *node)
{
    if (root)
    {
        if (node->data <= root->data)
            AddNode(root->left, node);
        else
            AddNode(root->right, node);
    }
    else
    {
        root = node;
    }
};

void FindAndReplace1(Tree &p, Tree &tree)
{
    if (tree->left)
        FindAndReplace1(p, tree->left);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->right;
    }
};

void FindAndReplace2(Tree &p, Tree &tree)
{
    if (tree->right)
        FindAndReplace2(p, tree->right);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->left;
    }
};

void DeleteNode(Tree &root, int x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else
        {
            Node *p = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
                FindAndReplace1(p, root->right);
            // FindAndReplace2(p, root->left);
            delete p;
        }
    }
    else
    {
        cout << "Not found!\n";
    }
};

void NLR(Tree root)
{
    if (root)
    {
        //
        NLR(root->left);
        NLR(root->right);
    }
};

void LNR(Tree root)
{
    if (root)
    {
        LNR(root->left);
        //
        LNR(root->right);
    }
};

void LRN(Tree root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        //
    }
};
