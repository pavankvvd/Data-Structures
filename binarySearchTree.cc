#include "headers.h"

int number = 0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;
Node *root = NULL;

void insert(Node *root,Node *temp)
{
    if (root == NULL || temp == NULL) {
        cout << "node is empty";
    } else if (temp->data > root->data) {
        if (root->right == NULL) {
            root->right = temp;
        } else {
            insert(root->right, temp);
        }
    } else if (temp->data < root->data) {
        if (root->left == NULL) {
            root->left = temp;
        } else {
            insert(root->left, temp);
        }
    }
}

void createNode(int data)
{
    cout << "inserting " << data <<endl;
    struct node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        root = temp;
    } else {
        insert(root,temp);
    }
}

void displayInorder(Node *root)
{
    if (root == NULL) {
        return;
    } else {
        displayInorder(root->left);
        cout << root->data << endl;
        number = number+ 1;
        displayInorder(root->right);
    }
}

int main()
{
    createNode(6);
//  delete root;
//  if (root != NULL) {
//      cout << "root is NULL";
//  }

    createNode(4);
    createNode(3);
    createNode(8);
    cout << "printing inorder " << endl;
    displayInorder(root);

    cout << " number of nodes :" << number << endl;
    return 0;
}
