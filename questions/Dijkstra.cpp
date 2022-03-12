struct node{
    double prob;
    int i;
};
struct cmp
{
    bool operator()(node const &a, node const &b)
    {
        return a.prob < b.prob;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        bool vis[n];
        memset(vis,false,sizeof(vis));
        map<int,map<int,double>>p;
        for(int i=0;i<edges.size();i++)
        {
            p[edges[i][0]][edges[i][1]]=succProb[i];
            p[edges[i][1]][edges[i][0]]=succProb[i];
            // cout<<p[edges[i][1]][edges[i][0]]<<endl;
        }
        priority_queue<node,vector<node>,cmp>pq;
        node s;
        s.i = start;
        s.prob = 1;
        pq.push(s);
        while(pq.size()>0){
            node t = pq.top();
            pq.pop();
            if(t.i==end) return   t.prob;
            if(vis[t.i]==true){
                continue;
            }
            vis[t.i]=1;
            for(pair<int,double> x:p[t.i])
            {
                if(!vis[x.first]){
                    node temp;
                    temp.i= x.first;
                    temp.prob= t.prob*p[t.i][x.first];
                    pq.push(temp);
                    // cout<<t.prob<<" "<<p[t.i][x.first]<<endl;
                    // cout<<t.i<<" "<<x.first<<" "<<p[t.i][x.first]<<endl;
                }                
            }
        }
        return 0;
    }
};
