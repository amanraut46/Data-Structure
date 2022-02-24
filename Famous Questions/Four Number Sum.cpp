#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> array{7, 6, 4, -1, 1, 2};
    int targetsum = 16;
    int n = array.size();
    unordered_map<int, vector<vector<int>>> mp;
    vector<vector<int>> rs;
    for (size_t i = 1; i < n - 1; i++)
    {
        for (size_t j = i; j < n; i++)
        {
            int totsum = array[i] + array[j];
            int diff = targetsum - totsum;

            if (mp.find(diff) != mp.end())
            {
                for (vector<int> pair : mp[diff])
                {
                    pair.push_back(array[i]);
                    pair.push_back(array[j]);
                    rs.push_back(pair);
                }
            }
        }

        for (size_t k = 0; k < i; k++)
        {
            int sum = array[k] + array[i];
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = vector<vector<int>>{{array[k], array[i]}};
            }
            else
            {
                vector<int> vt = {array[k], array[i]};
                mp[sum].push_back(vt);
            }
        }
    }
    for(auto i:rs)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
