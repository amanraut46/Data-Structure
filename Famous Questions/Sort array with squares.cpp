  #include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Solution
{
    public:
        vector<int> solve(vector<int> &A);
};
vector<int> Solution::solve(vector<int> &A) {
    
    int n=A.size();
    vector<int> vt(n);
    for(int i=0;i<n;i++)
    {
        vt[i]=A[i]*A[i];
    }
    sort(vt.begin(),vt.end());

    return vt;

}
int main()
{
    Solution s;
    vector<int> vt{-6, -3, -1, 2, 4, 5};
    for(auto i:s.solve(vt))
    {
        cout<<i<<" ";
    }
    return 0;
}