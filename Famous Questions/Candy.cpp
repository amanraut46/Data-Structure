#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        int sum=0;
        int n=ratings.size();
        vector<int> a(n);
        fill(a.begin(),a.end(),1);
        
        for(int i=0;i< n-1;i++)
        {
            if(ratings[i+1]>ratings[i])
            {
                a[i+1]=a[i]+1;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                if(a[i-1]<(a[i]+1))
                {
                    a[i-1]=a[i]+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        return sum;

        ////int n=rating.size() - 1;;
        ////vector<int> a(n);
        ////
        ////fill(a.begin(),a.end(),1);
        ////
        ////for(int i=1;i<n;i++)
        ////{
        ////    if(rating[i-1]>rating[i])
        ////    {
        ////        rating[i-1]=rating[i]+1;
        ////    }
        ////}
        ////for(int i=n-1;i>=0;i--)
        ////{
        ////    if(rating[i-1]>rating[i]){
        ////        if(a[i-1]<a[i]+1){
        ////            a[i-1]=a[i]+1;
        ////        }
        ////    }
        ////}
        ////int ans=0;
        ////for(auto i:a)
        ////{
        ////    ans+=i;
        ////}
        ////return ans;
    }
};
int main()
{
    vector<int>  ratings {1,0,2};
    Solution s;
    cout<<s.candy(ratings)<<endl;
    return 0;
}