#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
        int left[n];
        int right[n];
        
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i],right[i])-height[i];
        }
        return ans; 
    }
};
int main()
{
    vector<int>height {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s1;
    cout<<s1.trap(height)<<endl;
    return 0;
}