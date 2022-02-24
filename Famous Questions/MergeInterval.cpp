#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<vector<int>> interval{{3,5},{1,2},{4,7},{6,8},{9,10}};

    vector<vector<int>> sortedinterval=interval;
    vector<vector<int>*> mergeinterval;
     cout<<"------------------------------------"<<endl;
    for (auto i: sortedinterval)
    {
        for(int j:i)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
    sort(sortedinterval.begin(),sortedinterval.end());
    cout<<"------------------------------------"<<endl;
    for (auto i: sortedinterval)
    {
        for(int j:i)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
    vector<int> *curr=&sortedinterval[0];

    mergeinterval.push_back(curr);
    cout<<"------------------------------------"<<endl;
    for(auto &nextinterval:sortedinterval)
    {
        int currentrvalend=curr->at(1);
        int nextintervalstart=nextinterval[0];
        int nextintervalend=nextinterval[1];

        if(currentrvalend >= nextintervalstart)
        {
            curr->at(1)=max(currentrvalend,nextintervalend);
            cout<<"In if"<<endl;
            
            
        }
        else
        {
            cout<<"In else"<<endl;
            curr=&nextinterval;
           
            mergeinterval.push_back(curr);
        }
    }
    cout<<"------------------------------------"<<endl;
    vector<vector<int>> mergeintervalcopy;
    for (auto i: mergeinterval)
    {
        
        mergeintervalcopy.push_back(*i);
    }

    for(auto i:mergeintervalcopy)
    {
        for(int j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}