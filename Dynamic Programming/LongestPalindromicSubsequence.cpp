#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
#include<cstring>
using namespace std;
int getLongPal(char s[],int i,int j)
{
   
    if(i==j)
    {
        return  1;
    }
    if(s[i]==s[j] && i+1==j)
    {
        return 2;
    }

    if(s[i]==s[j]){
        return  getLongPal(s,i+1,j-1)+2;
    }

    return max(getLongPal(s,i+1,j),getLongPal(s,i,j-1));
    
}
int main()
{
    char s[]={'G','E','E','K','S','F','O','R','G','E','E','K','S'};
    int i=0;
    int j = strlen(s);
    cout<<getLongPal(s,i,j-1);
    return 0;
}