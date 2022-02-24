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
int editDist(string s1,string s2,int i,int j){

    if(i==0)
        return j;
    if(j==0)
        return i;

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        
        if(s1[i-1]==s2[j-1])
            return dp[i-1][j-1]=editDist(s1,s2,i-1,j-1);
    
        return dp[i][j]=1+min(editDist(s1,s2,i,j-1),min(editDist(s1,s2,i-1,j),editDist(s1,s2,i-1,j-1)));
    }
    
    
}
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
    intit();
    cout << editDist(str1, str2, str1.length(),
                     str2.length());
 
    return 0;
    
}