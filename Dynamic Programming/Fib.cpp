#include<iostream>
#include<vector>

using namespace std;
#define MAX 100

int dp[MAX];

void Initilization()
{
    for (int i = 0; i <MAX ; i++)
    {
        dp[i]=-1;
    }
    
}
int fib(int n)
{

    if(dp[n]==-1){
        if(n<=1)
            dp[n]=n;
        else
            dp[n]=fib(n-1)+fib(n-2);
    }
    return dp[n];
}
int fib1(int n)
{
    int lookup[n+1];
    int i;
    lookup[0]=0;
    lookup[1]=1;

    for (i = 2; i <=n; i++)
    {
        lookup[i]=lookup[i-1]+lookup[i-2];
    }
    return lookup[n];
}
int main()
{
    int n;
    cin>>n;
    Initilization();
    for (size_t i = 1; i < n; i++)
    {
        cout<<fib1(i)<<" ";
    }  
}