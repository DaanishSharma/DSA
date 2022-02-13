
// leetcode solution - https://leetcode.com/problems/course-schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,map<int,int>>m;
        int count;
        vector<int>id(numCourses,0);
        for(auto x:prerequisites){
            if(x[0]==x[1]){
                cout<<1<<endl;
                return false;
            }
            m[x[1]][x[0]]=1;
            id[x[0]]+=1;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(id[i]==0){
                q.push(i);
            }
        }
        if(q.size()==0){
            return false;
        }
        count = q.size();
        int front;
        while(q.size()!=0){
            front = q.front();
            q.pop();
            for(auto &x:m[front]){
                id[x.first]-=1;
                if(id[x.first]==0){
                    q.push(x.first);
                    count++;
                }
            }
        }
        return count==numCourses;
    }
};
