#include <bits/stdc++.h>
using namespace std;
/*defining tree*/
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left =NULL;
        right = NULL;
    }

};
/*TRAVERSALS*/
void printpreorder(Node* node){
    if(node == NULL){return;}

    cout<<node->data<<" ";
    printpreorder(node->left);
    printpreorder(node->right);
}

void printinorder(Node* node){
    if(node == NULL){ return; }
    printinorder(node->left);
    cout<<node->data<<" ";
    printinorder(node->right);
}

void printpostorder(Node* node){
    if(node == NULL){return;}
    printpostorder(node->left);
    printpostorder(node->right);
    cout<<node->data<<" ";
}
/*MAIN*/
int main(){
struct Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);

root->left->right = new Node(5);
cout<<"ALL OKAY NO ERROR"<<endl;

cout<<"PRE ORDER TRAVERSAL"<<endl;
printpreorder(root);
cout<<endl;
cout<<"INORDER TRAVERSAL"<<endl;
printinorder(root);
cout<<endl;
cout<<"POST ORDER TRAVERSAL"<<endl;
printpostorder(root);
    return 0;
}
