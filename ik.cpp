// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000943934
#include <bits/stdc++.h>
using namespace std;
int dp(int i,int p,int cost,string s,set<string> forbidden_orders,vector<int>pen){
    if(forbidden_orders.find(s)==forbidden_orders.end()){
        return cost;
    }
    else if((i>=p)){
        return INT_MAX;
    }
    string temp = s;
    if(temp[i]=='0'){
        temp[i]='1';
    }    
    else{
        temp[i]='0';
    }    
    return min(dp(i+1,p,cost+pen[i],temp,forbidden_orders,pen),dp(i+1,p,cost,s,forbidden_orders,pen));
}
int GetMinimumNumberOfComplaints(vector<string> friend_orders,set<string> forbidden_orders, int options)
{
    int minimum_number_of_complaints=0;
    int n = friend_orders.size();
    vector<int>v(options,0);
    vector<int>p(options,0);
    string s;
    for(int i=0;i<n;i++){
        for(int j=0;j<options;j++){
            v[j]+=int(int(friend_orders[i][j])-int('0'));
        }
    }
    for(int i=0;i<options;i++){
        // zeros > ones
        if(n-v[i]>v[i]){
            s+="0";
            p[i]=(n-2*v[i]);
            minimum_number_of_complaints+=(v[i]);
        }
        // ones > zeros
        else{
            s+="1";
            p[i]=(2*v[i]-n);
            minimum_number_of_complaints+=(n-v[i]);
        }
    }
    if(forbidden_orders.find(s)==forbidden_orders.end()){
        return minimum_number_of_complaints;
    }

    // TODO: Complete this function to get the minimum number of complaints.
    return dp(0,options,minimum_number_of_complaints,s,forbidden_orders,p);
}

int main()
{
    int t;
    // 't' refers to number of test cases.
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // 'n' refers to preferences of friends.
        // 'm' refers to number of prohibited milk teas.
        // 'p' refers to binary options available at the tea shop.
        int n, m, p;
        cin >> n;
        cin >> m;
        cin >> p;
        vector<string> friend_orders(n);
        set<string> forbidden_orders;
        for (int i = 0; i < n; ++i)
        {
            cin >> friend_orders[i];
        }
        for (int i = 0; i < m; ++i)
        {
            string temp;
            cin >> temp;
            forbidden_orders.insert(temp);
        }
        cout << "Case #" << tc << ": "
             << GetMinimumNumberOfComplaints(friend_orders, forbidden_orders, p)
             << endl;
    }
    return 0;
}
