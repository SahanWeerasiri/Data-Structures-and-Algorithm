#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root==nullptr){
        return;
    }
    traverseInOrder(root->left);
    cout<<root->data<<" ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *nod, int key) {
    if(nod==nullptr){
        struct node *temp=new struct node();
        temp->data=key;
        temp->left=nullptr;
        temp->right=nullptr;
        return temp;
    }
    if(nod->data>=key){
        nod->left=insertNode(nod->left,key);
    }else{
        nod->right=insertNode(nod->right,key);
    }
    return nod;

}

struct node *findMini(node *root){
    node *current=root;
    while(current->left->left!=nullptr){
        current=current->left;
    }
    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root==nullptr){
        return root;
    }
    if(key>root->data){
        root->right=deleteNode(root->right,key);
    }else if (key<root->data){
        root->left=deleteNode(root->left,key);
    }else{
        if(root->left==nullptr && root->right==nullptr){
            struct node *temp=root;
            root=nullptr;
            delete temp;
        }else if(root->left==nullptr){
            struct node *temp=root->right;
            root=root->right;
            delete temp;
        }else if(root->right==nullptr){
            struct node *temp=root->left;
            root=root->left;
            delete temp;
        }else{
            struct node *temp=findMini(root->right);
            root->data=temp->left->data;
            root->right=deleteNode(temp->right,temp->data);

        }
    } 
    return root;

}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        traverseInOrder(root);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
    case 3: //show
        traverseInOrder(root);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  
}