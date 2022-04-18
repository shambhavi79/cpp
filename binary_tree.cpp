#include <iostream>

using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
    
};

void preorder(Node* root){
    if(root==NULL){
        return
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

vector<vector<int>> bfs(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    if(root==NULL){
        return a;
    }
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int s=q.size();
        while(s--){
            Node* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        a.push_back(level);
    }
    return a;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left), height(root->right))+1;
}

bool isPresent(Node* root, int d){
    if(root==NULL){
        return false;
    }
    if(root->data==d){
        return true;
    }
    if(isPresent(root->left, d)){
        return true;
    }
    if(isPresent(root->right, d)){
        return true;
    }
    return false;
}

int maxintree(Node* root){
    if(root==NULL){
        return INT_MIN;
    }
    int lmax=maxintree(root->left);
    int rmax=maxintree(root->right);
    
    return max(root->data, max(lmax, rmax));
}

int main()
{
    cout<<"Hello World";

    return 0;
}