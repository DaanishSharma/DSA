/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //https://www.interviewbit.com/problems/reverse-level-order/
vector<int> Solution::solve(TreeNode* A) {
    stack<vector<int>>s;
    queue<TreeNode*>q;
    q.push(A);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>l;
            for(int i=0;i<size;i++){
                A=q.front();
                q.pop();
                if(A->left!=NULL)   q.push(A->left);
                if(A->right!=NULL)   q.push(A->right);
                l.push_back(A->val);
            }
            s.push(l);
        }
    
    
    vector<int>ans;
    while(!s.empty()){
        auto top =s.top();
        for(auto i :top){
            ans.push_back(i);     
        }
       
        s.pop();
    }
    return ans;
}
