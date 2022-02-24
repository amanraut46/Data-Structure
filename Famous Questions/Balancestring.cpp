#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int  j=0;j<s.length();j++)
        {
            char i=s[j];
            if(i=='(' || i=='[' || i=='{')
            {
                st.push(i);
            }
            else 
            {
                if(!s.empty())
                {
                    char top=st.top();
                    if(i=='}' && top=='{'|| i==']' && top=='[' || i==')' && top=='(' ){
                        st.pop();
                    }
                    else
                    {
                    return false;
                    }
                }
                else
                {
                    return false;
                }   
            }
        }
        
        if(st.empty())
            return true;
        else 
            return false;
    }
};
int main()
{
    Solution s1;
    
    cout<<s1.isValid("[]")<<endl;
    return 0;
}