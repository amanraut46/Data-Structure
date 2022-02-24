#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int mx=INT32_MIN;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            mx=max(mx,curr);
            if(curr<0)
            {
                curr=0;
            }
            
        }
        return mx;
    }
};
int main()
{
    vector<int> vs{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maxSubArray(vs);
    return 0;
}