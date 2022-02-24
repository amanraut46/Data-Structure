  #include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i; j < n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }   
        }

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n/2; j++)
            {
                swap(matrix[i][j],matrix[i][n-j-1]);
            }   
        }
        
        
    }
};
int main()
{
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};
    Solution s1;
    s1.rotate(matrix);
    for (auto i:matrix)
    {
        /* code */
        for (auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}