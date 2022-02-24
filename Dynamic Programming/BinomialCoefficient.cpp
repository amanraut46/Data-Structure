  #include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
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
int binomialCoeff(int n,int k){

    if(k>n)
        return 0;
    if(k==0 || k==n)
        return 1;
    
    if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    return dp[n][k]=binomialCoeff(n-1,k-1)+binomialCoeff(n-1,k);
}
int main()
{
    int n = 5, k = 2;
    intit();
    cout << "Value of C(" << n << ", " << k << ") is "
         << binomialCoeff(n, k);
    return 0;
}