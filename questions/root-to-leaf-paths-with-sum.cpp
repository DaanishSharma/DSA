//https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
vector<vector<int>>ans;
void sol(TreeNode* n,vector<int>path,int s,int t){
    // cout<<s<<" "<<n->val<<endl;
    if(n->left==NULL and n->right==NULL){
        path.push_back(n->val);
        s+=n->val;
        if(s==t){
           ans.push_back(path);
            // cout<<"Yo\n";
            return;
        }
        else{
            return;
        }
    }
    path.push_back(n->val);
    if(n->left!=NULL){
        sol(n->left,path,s+(n->val),t);
    }
    if(n->right!=NULL){
        sol(n->right,path,s+(n->val),t);
    }
}
vector<vector<int>> Solution::pathSum(TreeNode* A, int B) {
    ans.clear();
        vector<int>v;
        if(A==NULL){
            return ans;
        }
        sol(A,v,0,B);
        return ans; 
}
