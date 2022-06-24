/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        ll ans = 0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        while(q.size()!=0){ 
            ll size = q.size();
            ll mn = q.front().second;
            ll left,right;
            for(int i=0;i<size;i++){
                TreeNode* n = q.front().first;
                ll N = q.front().second-mn;
                q.pop();
                if(i==0)    left = N;
                if(i==size-1)   right = N;
                if(n->left){
                    q.push({n->left,2*N+1});
                }
                if(n->right){
                    q.push({n->right,2*N+2});
                }
                // cout<<N<<endl;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
