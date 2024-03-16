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
        search(root->left,val);
    }else{
        search(root->right,val);
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
void deletion(node *root,int val){
    

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