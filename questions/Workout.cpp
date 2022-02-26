// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
// Google Kickstart 2020 A Workout
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, k;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> k;
        vector<int> a(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        int l = 1;
        int r = a[n-1]-a[0];
        int mid,diff;
        int ans = INT_MAX; 
        while(l<=r){
            int need = 0;
            mid = (l+r)/2;
            for(int j=0;j<n-1;j++){
                diff = a[j+1]-a[j];
                if((diff)%mid==0){
                    need += ((diff)/mid)-1;
                }
                else{
                    need += ((diff)/mid);
                }
            }
            if(need<=k){
                 r = mid - 1;
                 ans = min(ans,mid);
            }
            else{
                l = mid + 1;
            }
        } 
        cout << "Case #" << (i + 1) << ": " << ans << endl;
    }
    return 0;
}
