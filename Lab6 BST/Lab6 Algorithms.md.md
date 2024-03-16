> # Algorithms
> In C++
> * BST with nodes using class
> * BST with nodes using structs
***
#  BST with nodes using class
```cpp
#include <iostream>
using namespace std;


class node{
    public:
    int data;
    struct node *left;
    struct node *right;
};
void insert(node *root,int val){
    if(root->left==nullptr && root->data>val){
        node *temp=new node();
        temp->data=val;
        temp->left=nullptr;
        temp->right=nullptr;
        root->left=temp;
        return;
    }else if(root->right==nullptr && root->data<=val){
        node *temp=new node();
        temp->data=val;
        temp->left=nullptr;
        temp->right=nullptr;
        root->right=temp;
        return;
    }else if(root->data>val){
        insert(root->left,val);
    }else{
        insert(root->right,val);
    }
}
void travelInOrder(node *root){
    if(root==nullptr){
        return;
    }
    travelInOrder(root->left);
    cout<<root->data<<" ";
    travelInOrder(root->right);
}
void travelPreOrder(node *root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    travelPreOrder(root->left);
    travelPreOrder(root->right);
}
void travelPostOrder(node *root){
    if(root==nullptr){
        return;
    }
    travelPostOrder(root->left);
    travelPostOrder(root->right);
    cout<<root->data<<" ";
}
bool search(node *root,int val){
    if(root==nullptr){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(root->data>val){
        return search(root->left,val);
    }else{
        return search(root->right,val);
    }   
    
}
node* findMini(node *root){
    node *current=root;
    while(current->left!=nullptr){
        current=current->left;
    }
    cout<<current->data<<endl;
    return current;
}

node* Delete(node *root,int val){
    if(root==nullptr){
        return root;
    }
    if(root->data>val){
        root->left=Delete(root->left,val);
    }else{
        root->right=Delete(root->right,val);
    }
    if(root->data==val){
        if(root->left ==nullptr && root->right==nullptr){
        root=nullptr;
    }else if(root->left ==nullptr && root->right!=nullptr){
        node *temp=root;
        root=root->right;
    }else if(root->left !=nullptr && root->right==nullptr){
        node *temp=root;
        root=root->left;
    }else{
        node *temp=findMini(root->right);
        root->data=temp->data;
        root=Delete(root->right,temp->data);
        
    }
    }  
    return root;
    
}
int main(){
    //BST creation
    // commands : insert,search,delete,travel_in,travel_pre,travel_post,exit

    node *root=nullptr;
    while(true){
        string cmd;
        cin>>cmd;
        int val;
        if(cmd=="insert"){
            cin>>val;
            if(root==nullptr){
                node *temp=new node();
                temp->data=val;
                temp->left=nullptr;
                temp->right=nullptr;
                root=temp;
                continue;
            }
            insert(root,val);
        }else if(cmd=="search"){
            cin>>val;
            cout<<search(root,val)<<endl;

        }else if(cmd=="delete"){
            cin>>val;
            root=Delete(root,val);
        }else if(cmd=="travel_in"){
            travelInOrder(root);
            cout<<endl;
        }else if(cmd=="travel_pre"){
            travelPreOrder(root);
            cout<<endl;
        }else if(cmd=="travel_post"){
            travelPostOrder(root);
            cout<<endl;
        }else if(cmd=="exit"){
            cout<<"Exited!\nHave a nice day\n";
            break;    
        }else {
            cout<<"Invalid Command\n";
        }
    }


}

````
***
# BST with nodes using structs
```cpp
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
```
