#include<iostream>
#include <cstring>
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
int lcs(char x[],char y[],int i,int j){

    if(i==0 || j==0)
        return 0;
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        if(x[i-1]==y[j-1])
          return dp[i-1][j-1]=1+lcs(x,y,i-1,j-1);
        else
          return dp[i][j]=max(lcs(x,y,i,j-1),lcs(x,y,i-1,j));
    }
    
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int m = strlen(X);
    int n = strlen(Y);
    intit();
    cout<<"Length of LCS is "<< lcs( X, Y, m, n) ;
     
    return 0;
}