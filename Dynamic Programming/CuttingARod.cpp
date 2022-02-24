  #include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
int un_kp(int price[],int length[], int Max_len,int n )
{
    if(n==0 || Max_len==0)
        return 0;
    
    if(length[n-1]<=Max_len)
        return max(price[n-1]+un_kp(price,length,Max_len-length[n-1],n),un_kp(price,length,Max_len,n-1));
    else
        return un_kp(price,length,Max_len,n-1);
}
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
 
    // Function Call
    cout << "Maximum obtained value  is "
         << un_kp(price, length, n, Max_len) << endl;
    return 0;
}