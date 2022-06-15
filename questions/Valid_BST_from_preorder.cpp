//https://www.interviewbit.com/problems/valid-bst-from-preorder/discussion/
int validBST(int i,int n,vector<int> &A){
    // cout<<i<<" "<<n<<endl;
    // let A[i] be root of a subtree
    if(i>=n-1){
        return 1;
    }
    int j=i+1;
    for(;j<n;j++){
        if(A[i]<A[j]){
            // left subtree from i+1 to j-1 - Checked    
            // right j to n-1
            // cout<<j<<endl;
            for(int k=j+1;k<n;k++){
                if(A[i]>=A[k]){
                    return 0;
                }
            }
            break;
        }
        else if(A[i]==A[j]){
            return 0;
        }
    }
    return (validBST(i+1,j,A))&&(validBST(j,n,A));
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    // root left right
    return validBST(0,n,A);
}
