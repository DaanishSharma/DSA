//https://www.hackerrank.com/challenges/ctci-merge-sort/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


long merge(long i1,long j1,long i2,long j2,vector<int>& nums){
    long temp=i1;
    long rv = 0;
    vector<int>x(j2-i1+1);
    int i=0;
    while(i1<=j1&&i2<=j2){
        if(nums[i1]<=nums[i2]){
            x[i]=(nums[i1]);
            i1++;
        }
        else{
            x[i]=(nums[i2]); 
            i2++;
            rv+=(j1-i1+1);
        }
        i++;
    }
    while(i1<=j1){
        x[i]=(nums[i1]);
        i++;
        i1++;
    }
    while(i2<=j2){
        x[i]=(nums[i2]); 
        i2++;
        i++;
    }
    long x1=0;
    for(long i=temp;i<=j2;i++){
        nums[i]=x[x1];
        x1++;
    }
    return rv;
}
long sort(long i,long j,vector<int>& nums){
    if(i==j){
        return 0;    
    }
    long mid = (i+j)/2;
    long a=sort(i,mid,nums);
    long b=sort(mid+1,j,nums);
    long c=merge(i,mid,mid+1,j,nums);
    return (a+b+c);
}
long countInversions(vector<int> arr) {
  return sort(0,arr.size()-1,arr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
