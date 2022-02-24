#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        nums1.erase(
    std::remove(nums1.begin()+m, nums1.end(), 0),
    nums1.end());
        vector<int> rs (m+n);
        int k=0;
        for (size_t i = 0; i < m; i++)
        {
            rs[k]=nums1[i];
            k++;
        }
        for (size_t i = 0; i < n; i++)
        {
            rs[k]=nums2[i];
            k++;
        }
        
        sort(rs.begin(),rs.end());
        k=0;
        for (size_t i = 0; i < m; i++)
        {
            nums1[i]=rs[k];
            k++;
        }
        for (size_t i = 0; i < n; i++)
        {
            nums2[i]=rs[k];
            k++;
        }


        //int i=0,j=0,k=m-1;
        //while (i<=k && j< n)
        //{
        //    if(nums1[i]<nums2[j])
        //    {
        //        i++;
        //    }
        //    else if(nums1[i]==0)
        //    {
        //        nums1.pop_back();
        //    }
        //    else if(nums2[j]==0)
        //    {
        //        nums2.pop_back();
        //    }
        //    else
        //    {
        //        swap(nums1[k--],nums2[j++]);
        //    }
        //}
        //sort(nums1.begin(),nums1.begin()+m);
        //sort(nums2.begin(),nums2.begin()+n);
    }
};
int main()
{
    vector<int> nums1 {1,2,3,0,0,0};
    int m = 3; 
    vector<int> nums2{2,5,6};
    int n = 3;
    Solution s;
    s.merge(nums1,m,nums2,n);

    for(int i:nums1)
    {
        cout<<i<<" ";
    }
    for(int i:nums2)
    {
        cout<<i<<" ";
    }
    ////for(int i=0;i<m;i++)
    ////{
    ////    cout<<nums1[i]<<" ";
    ////}
    ////for(int i=0;i<n;i++)
    ////{
    ////    cout<<nums2[i]<<" ";
    ////}
    return 0;
}