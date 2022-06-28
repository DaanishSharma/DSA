#define ll long long
//https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/
ll count(ll gap,vector<int>p){ //return max no.of balls that can be stored if min gap=gap  
    ll cnt=1;
    ll prev = p[0];
    for(ll i=1;i<p.size();i++){
        if(p[i]-prev>=gap){
            cnt+=1;
            prev = p[i];
        }   
    }
    // cout<<gap<<"---"<<cnt<<endl;
    return cnt;
}
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {      
    sort(position.begin(),position.end());
    ll l=0;
    ll r=position.back();
    ll mid = l+(r-l)/2;
    while(r-l>1){
        mid = l+(r-l)/2;
        // cout<<l<<" "<<r<<endl;
        if(count(mid,position)>=m){
            l=mid; 
        }
        else{
            r=mid;
        }
    }    
    return l;  
    }
};
