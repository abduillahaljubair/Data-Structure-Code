#include <iostream>
using namespace std;

struct node {
    int data;
    node *right;
    node *left;
};

node *root = NULL;

void BST_Insert(int val) {
    node *temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = temp;
    } else {
        node *curr_node = root;
        while (curr_node != NULL) {
            if (temp->data < curr_node->data) {
                if (curr_node->left == NULL) {
                    curr_node->left = temp;
                    break;
                } else {
                    curr_node = curr_node->left;
                }
            } else {
                if (curr_node->right == NULL) {
                    curr_node->right = temp;
                    break;
                } else {
                    curr_node = curr_node->right;
                }
            }
        }
    }
}

void preorder(node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void INorder(node *root) {
    if (root != NULL) {
        INorder(root->left);
        cout << root->data << " ";
        INorder(root->right);
    }
}

void Postorder(node *root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    int x;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        BST_Insert(x);
    }

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    INorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    Postorder(root);
    cout << endl;

    return 0;
}
