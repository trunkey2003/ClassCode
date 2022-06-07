#include <iostream>

using namespace std;

template <typename Type>
struct Node
{
    Type data;
    Node<Type> *left;
    Node<Type> *right;
    Node(){};
    Node(Type data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    };
};

template <typename Type>
using Tree = Node<Type>*;

template <typename Type>
Node<Type> *CreateNode(Type init)
{
    Node<Type> *p = new Node<Type>;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
};

template <typename Type>
void CreateTree(Tree<Type> &root)
{
    root = NULL;
};

template <typename Type>
void DestroyTree(Tree<Type> &root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
};

template <typename Type>
void AddNode(Tree<Type> &root, Type data)
{
    Node<Type>* node = CreateNode(data);
    if (root)
    {
        if (root->data == node->data)
            return;
        if (node->data < root->data)
            AddNode(root->left, data);
        else
            AddNode(root->right, data);
    }
    else
    {
        root = node;
    }
};

template <typename Type>
Node<Type> *FindNode(Tree<Type> root, Type x)
{
    if (root)
    {
        if (root->data == x)
            return root;
        if (x < root->data)
            return FindNode(root->left, x);
        return FindNode(root->right, x);
    }
    return NULL;
};

template <typename Type>
void PrintTree(Tree<Type> root, int option)
{
    switch (option)
    {
    case 1:
    {
        if (root)
        {
            PrintTree(root->left, option);
            cout << root->data << " ";
            PrintTree(root->right, option);
        };
        break;
    };
    case 2:
    {
        if (root)
        {
            PrintTree(root->left, option);
            PrintTree(root->right, option);
            cout << root->data << " ";
        }
        break;
    };
    case 3:
    {
        if (root)
        {
            PrintTree(root->right, option);
            cout << root->data << " ";
            PrintTree(root->left, option);
        }
        break;
    };
    case 4:
    {
        if (root)
        {
            PrintTree(root->right, option);
            PrintTree(root->left, option);
            cout << root->data << " ";
        }
        break;
    };
    case 5:
    {
        if (root)
        {
            cout << root->data << " ";
            PrintTree(root->left, option);
            PrintTree(root->right, option);
        }
        break;
    };
    case 6:
    {
        if (root)
        {
            cout << root->data << " ";
            PrintTree(root->right, option);
            PrintTree(root->left, option);
        }
        break;
    };
    default: 
        cout << "Wrong option!" << endl;
        break;
    };
};

template <typename Type>
void NLR(Tree<Type> root)
{
    if (root)
    {
        //
        NLR(root->left);
        NLR(root->right);
    }
};

template <typename Type>
void LNR(Tree<Type> root)
{
    if (root)
    {
        LNR(root->left);
        //
        LNR(root->right);
    }
};

template <typename Type>
void LRN(Tree<Type> root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        //
    }
};

template <typename Type>
void FindAndReplace1(Tree<Type> &p, Tree<Type> &tree)
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

template <typename Type>
void FindAndReplace2(Tree<Type> &p, Tree<Type> &tree)
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

template <typename Type>
void DeleteNode(Tree<Type> &root, Type x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else
        {
            Node<Type> *p = root;
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
