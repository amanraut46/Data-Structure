#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
#define R 3
#define C 3

#define maxsize 10000
int dp[maxsize][maxsize];

void intit()
{
    for (size_t i = 0; i < maxsize; i++)
    {
        for (size_t j = 0; j < maxsize; j++)
        {
            dp[i][j]=-1;
        }
        
    }
    
}
int minCost(int cost[R][C],int m,int n)
{
    if(n< 0 || m<0)
        return INT32_MAX;
    
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(m==0 && n==0)
        return dp[m][n]=cost[m][n];

    return dp[m][n]=cost[m][n]+min(minCost(cost,m-1,n),min(minCost(cost,m,n-1),minCost(cost,m-1,n-1)));
}
int main()
{
    int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
                      intit();
    cout<<minCost(cost, 2, 2);
   
    return 0;
}