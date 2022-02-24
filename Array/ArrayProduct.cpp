#include<iostream>


using namespace std;


int main()
{
	int vt[]={5, 1, 4, 2};
	int n = 4;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		int product = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j) {
				product *= vt[j];
			}
		}
		arr[i] = product;
	}
	for (auto i: arr)
	{
		cout << i << " ";
	}
}