/**

https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
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
int rv=0;
int ans=0;
int f;
void inorder(TreeNode* n){
    if(n==NULL){
        return;
    }
    inorder(n->left);
    ans+=1;
    if(ans==f){
        rv=n->val;
        return;
    }
   inorder(n->right);
    
}
class Solution {
public:
    int kthSmallest(TreeNode* n, int k) {
       f=k;
        rv=0;
        ans=0;
    inorder(n);
    return rv; 
    }
};
