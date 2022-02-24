#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minvalue=prices[0];
        int maxprofit=0;
        
        for(int i=1;i<prices.size();i++)
        {
            minvalue=min(minvalue,prices[i]);
            int profit=prices[i]-minvalue;
            
            maxprofit=max(maxprofit,profit);
        }
        
        return maxprofit;
    }
};
int main()
{
    vector<int> prices {7,1,5,3,6,4};
    Solution s1;
    cout<<s1.maxProfit(prices)<<endl;
    return 0;
}