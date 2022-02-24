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

int count(int arr[],int m,int n){

    if(n==0)
        return 1;
    
    if(n<0)
        return 0;

    if(m<=0 && n>=1)
        return 0;
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    return dp[m][n]=count(arr,m-1,n)+count(arr,m,n-arr[m-1]);
}
int main()
{
    int i, j;
    int arr[] = { 1, 2, 3 };
    int m = sizeof(arr) / sizeof(arr[0]);
    intit();
    cout << " " << count(arr, m, 4);
    return 0;
}