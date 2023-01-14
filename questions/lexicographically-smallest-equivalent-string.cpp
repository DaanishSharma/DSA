// https://leetcode.com/problems/lexicographically-smallest-equivalent-string
class unionFind{
    private:
        int numComponents;
        vector<int>parent;
        vector<int>size;
    public:
        unionFind(int n){
            numComponents=n;
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int find(int x){
            if(parent[x]==x){
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        bool unite(int x,int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY){
                return false;
            }
            if(size[rootX] < size[rootY]){
                swap(rootX,rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            numComponents--;
            return true;
        }
        bool connected(int x, int y) {
            return find(x) == find(y);
        }
        int getNumComponents() {
            return numComponents;
        }
        int findSmallestComponentNumber(int x) {
    
            int root = find(x);
            int smallest = x;
            for (int i = 0; i < parent.size(); i++) {
                if (find(i) == root && i < smallest) {
                    smallest = i;
                    break;
                }
            }
        return smallest;
        }
};
class Solution {
public:

string smallestEquivalentString(string s1, string s2, string baseStr) {
    auto u = unionFind(26);
    for(int i=0;i<s1.size();i++){
        int a,b;
        a=(s1[i]-'a');
        b=(s2[i]-'a');
        u.unite(a,b);
    }
    string ans;
    for(char&c:baseStr){
        int x=(c-'a');
        ans+= ((char) (u.findSmallestComponentNumber(x)+((int)'a')));
    }
    return ans;
}
};
