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

/*LEVEL ORDER TRAVERSAL */
vector<vector<int> > levelorder(Node* node){
    vector<vector<int> > ans;
    if(node == NULL){return ans;}
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for( int i=0;i<size;i++)
        {
            Node* node2 = q.front();
            q.pop();
            if(node2->left != NULL){q.push(node2->left);}
            if(node2->right != NULL){q.push(node2->right);}

            level.push_back(node2->data);
        }
        ans.push_back(level);
    }

    return ans;
}

vector<int> preorder(Node* node ){
    vector<int> ans;
    stack<Node*> s;
    if(node == NULL){return ans;}

    s.push(node);
    while(!s.empty())
    {
        node = s.top();
        s.pop();
        ans.push_back(node->data);
        if(node->right != NULL){s.push(node->right);}
        if(node->left != NULL){s.push(node->left);}
    }

    return ans;
}
vector<int> inorder(Node* root) {
           vector<int> ans;
            Node* node = root;
            stack<Node* > s;
           while(true){
               if(node != NULL){s.push(node); node=node->left;}
               else{
                   if(s.empty() == true){break;}
                   node = s.top();
                   s.pop();
                   ans.push_back(node->data);
                   node=node->right;
               }
           }
           return ans;

        
    }

  vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node* > s;

        Node* curr = root;
        Node* temp;
while(curr != NULL or !s.empty())
{
        if(curr != NULL){
            s.push(curr);
          curr = curr->left;
        }

        else{
            temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();

                ans.push_back(temp->data);

                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                s.pop();

                ans.push_back(temp->data);
                }
            }
            else{curr =temp;}
        }
    }
        return ans;
        
    }


   /*3 in one traversal*/

 void traverse(Node* root, vector<int> &pre, vector<int> &in, vector<int> &post){
    stack<pair<Node* , int > > s;
    s.push({root,1});
     if(root == NULL ){return;}
    while(!s.empty())
    {
        auto it = s.top(); s.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);

            if(it.first->right != NULL){
                s.push( {it.first->right,1} );
            }
        }

        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);

            if(it.first->right != NULL){
                s.push({it.first->right,2});
            }
        }
        else{post.push_back(it.first->data);}
    }
 }   
/*MAIN*/
int main(){
   struct Node *root = new Node(1);
root->left = new Node(2);
root->left->left = new Node(4);
root->left ->right = new Node(5);
root->right = new Node(3);
root->right->left = new Node(6);
root->right->right = new Node(7);


cout<<"ALL OKAY NO ERROR"<<endl;

cout<<"PRE ORDER TRAVERSAL"<<endl;
printpreorder(root);
cout<<endl;
cout<<"INORDER TRAVERSAL"<<endl;
printinorder(root);
cout<<endl;
cout<<"POST ORDER TRAVERSAL"<<endl;
printpostorder(root);

cout<<endl;
cout<<"LEVEL ORDER TRAVERSAL"<<endl;

vector<vector<int> > print = levelorder(root);

for(int i =0;i<print.size();i++)
{
    for( int j=0;j<print[i].size();j++){
        cout<<print[i][j]<<" ";
    }
}

cout<<endl;
cout<<"I++ PRE ORDER TRAVERSAL"<<endl;

vector<int> ans = preorder(root);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";
}
cout<<endl;
cout<<"I++ IN ORDER TRAVERSAL"<<endl;

vector<int> ans2 = inorder(root);
for(int i=0;i<ans2.size();i++)
{
    cout<<ans2[i]<<" ";
}

cout<<endl;
cout<<"I++ POST ORDER TRAVERSAL"<<endl;

vector<int> ans3 = postorder(root);
for(int i=0;i<ans3.size();i++)
{
    cout<<ans3[i]<<" ";
}

/*declaring vectors for post pre in*/
vector<int> pre;
vector<int> post;
vector<int> in;
cout<<endl<<"PREORDER LIST:";
for(int i =0;i<pre.size();i++)
{cout<<pre[i]<<" ";}
cout<<endl<<"POST ORDER LIST:";
for(int i =0;i<post.size();i++)
{cout<<post[i]<<" ";}
cout<<endl<<"INORDER LIST: ";
for(int i =0;i<in.size();i++)
{cout<<in[i]<<" ";}
    return 0;
}
