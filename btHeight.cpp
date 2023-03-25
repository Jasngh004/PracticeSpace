#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node* right;
    struct Node* left;

    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

int maxDepth(Node* root){
    if(root == NULL){return 0;}

    int lp = maxDepth(root->left);
    int rp = maxDepth(root->right);

    return 1 + max(lp,rp);
}

int main(){
    struct Node *root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right= new Node(8);

    int height = maxDepth(root);
    cout<<"Height is:"<<height<<endl;
    return 0;
}