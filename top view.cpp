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

vector<int> addleft(Node *root, vector<int>& ans){
        if( root == NULL){return ans;}
         addleft(root->left,ans);
         ans.push_back(root->data);
    }
    
    vector<int> addright(Node *root, vector<int>& ans){
        if(root == NULL){return ans;}
        ans.push_back(root->data);
        addright(root->right,ans);
    }
    void topView(Node *root)
    {
        //Your code here
        
        vector<int> ans;
        if(root == NULL){return;}
        
        addleft(root->left,ans);
        ans.push_back(root->data);
        addright(root->right,ans);
        
        for( int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";
}
        //return ans;
    }


int main(){
    struct Node *root = new Node(1);
root->left = new Node(2);
root->left->left = new Node(4);
root->left ->right = new Node(5);
root->right = new Node(3);
root->right->left = new Node(6);
root->right->right = new Node(7);

topView(root);

cout<<"Output is returned"<<endl;

}