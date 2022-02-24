#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    int solve(vector<string> &A);
};
int Solution::solve(vector<string> &A) {
    unordered_map<char,int> mp;
    for(int i='a';i<='z';i++){
        mp[i]=0;
    }
    for(string a:A)
    {
        for(char i:a)
        {
            if(mp.find(i)!=mp.end())
            {
                mp[i]++;
            }
        }
    }
    for(auto i:mp){
    
        if(i.second==0)
            return 0;
    }
    return 1;
}
int main()
{
    vector<string> st{"interviewbit", "scaler"};
    Solution s;
    cout<<s.solve(st);
    return 0;
}