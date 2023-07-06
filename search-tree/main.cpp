#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(Node* &root, int data) {
    if (root == nullptr) {  
        root = createNode(data);  
	return ;
    }  
    
    if (data < root->data) {
         insertNode(root->left, data);
    } else if (data > root->data) {
	 insertNode(root->right, data);
    }

}
/*Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}*/

Node* findNode(Node* root, int data) {
   if (root == nullptr || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
int mass[]={17,-17,3,-3,10,50,-12,34,-9,2};
for (int i=0; i<10;++i){
	insertNode(root,mass[i]);
	std::cout << mass[i] << ' ' ;
}
std::cout << std::endl;
    // Insert nodes
    /*root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);*/
     cout << "Bigeen: ";
    inOrderTraversal(root);
    cout << endl;

    // Find nodes
    Node* node1 = findNode(root, 20);
    Node* node2 = findNode(root, 90);

    if (node1 != nullptr) {
        cout << "Node 20 found in tree" << endl;
    } else {
        cout << "Node 20 not found in tree" << endl;
    }

    if (node2 != nullptr) {
        cout << "Node 90 found in tree" << endl;
    } else {
        cout << "Node 90 not found in tree" << endl;
    }

    // In-order traversal
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
