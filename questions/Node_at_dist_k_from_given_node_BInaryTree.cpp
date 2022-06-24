/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
vector<int>ans;
map<int,bool>mp;
map<TreeNode*,TreeNode*>parent;
void t(TreeNode* n){
    if(n==NULL){
        return;
    }
    if(n->left!=NULL){
        // if(parent[n]!=NULL){
        //     cout<<n->val<<" "<<parent[n]->val<<endl;
        // }

        parent[n->left]=n;
        t(n->left);
    }   
    if(n->right!=NULL){
        // if(parent[n]!=NULL){
        //     cout<<n->val<<" "<<parent[n]->val<<endl;
        // }  
        parent[n->right]=n;
        t(n->right);
    }
    
}
void bfs(TreeNode* n,int d){
    if(n==NULL){
        return;
    }
    if(mp[n->val]==1){
        return;
    }
    mp[n->val]=1;
    cout<<n->val<<endl;
    if(d==0)    ans.push_back(n->val);
    bfs(parent[n],d-1);
    if(parent[n]!=NULL){
        cout<<n->val<<" "<<parent[n]->val<<endl;
    }
    if(n->left!=NULL){
        bfs(n->left,d-1);
    }
    if(n->right!=NULL){
        bfs(n->right,d-1);
    }
    
}
class Solution {
public:
    vector<int> distanceK(TreeNode* A, TreeNode* tar, int k) {
        ans.clear();
        mp.clear();
        parent.clear();          
        t(A);
        // cout<<tar->val<<endl;
        bfs(tar,k);
        return ans;  
    }
};
