
// https://www.interviewbit.com/problems/longest-consecutive-sequence/
int Solution::longestConsecutive(const vector<int> &A) {
    unordered_map<int,int>s; 
    for(int i=0;i<A.size();i++){
        s[A[i]]=i+1;
    }
    int i=0;
    int mx=1;
    vector<int>vis(A.size(),0);
    int cnt=0;
    while(i<A.size()&&cnt<A.size()){

        if(vis[i]){
            i++;
            continue;
        } 
        int j=A[i]-1;
        int count=1;
        while(s[j]!=0){
            vis[s[j]-1]=1;
            j = j-1;
            count+=1;
        }
        j=A[i]+1;
        while(s[j]!=0){
            vis[s[j]-1]=1;
            j = j+1;
            count+=1;
        }
        mx=max(mx,count);
        vis[i]=1;
        i++;
        cnt+=1;
    }
    
    return mx;
}
