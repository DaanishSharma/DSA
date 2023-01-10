#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    for(long long i=0;i<t;i++){
        long long x,y;
        cin>>x>>y;
        long long ans;
        long long mx = max(x,y);
        if(mx%2){
            // odd hai
            if(mx==x){
                //row pe hai
                ans=(mx-1)*(mx-1)+y;
            }
            else{
                // col pe hai
                ans=(mx)*(mx)-x+1;
            }
        }
        else{
            //even hai
            if(mx==x){
                //row pe hai
                ans=(mx)*(mx)-y+1;   
            }
            else{
                // col pe hai
                ans=(mx-1)*(mx-1)+x;
            }
        }
        cout<<ans<<endl;
    }
}