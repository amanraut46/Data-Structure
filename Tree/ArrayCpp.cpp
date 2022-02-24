#include<iostream>

using namespace std;

main()
{
    int arr[10];
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (i = 0; i < 10; i++)
    {
        cout << arr[i]<<" ";
    }
    return 1;
}