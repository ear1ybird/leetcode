#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int num;

    Node()
    {
        this->num = 0;
        this->left = NULL;
        this->right = NULL;
    }

    Node(int num)
    {
        this->num = num;
        this->left = NULL;
        this->right = NULL;
    }
};

void FrontTraverse(Node *node)
{
    if (node != NULL)
    {
        cout << node->num << endl;
    }
    else
    {
        return;
    }
    FrontTraverse(node->left);
    FrontTraverse(node->right);
}

int main(void)
{
    Node* root=new Node(1);
    Node* cur=root;
    cur->left=new Node(2);
    cur->right=new Node(3);
    cur->left->left=new Node(4);
    cur->left->right=new Node(5);
    cur->right->left=new Node(6);
    cur->right->right=new Node(7);

    FrontTraverse(root);

    return 0;
}
