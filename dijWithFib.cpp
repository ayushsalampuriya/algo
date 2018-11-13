#include <iostream>

using namespace std;

void Print(int** arr,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void arrange(int** arr,int n,int m)
{
	if(m==0)
	{
		Print(arr,n);
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	int arr[n][n];
	
	arrage(arr,0,m);	

	return 0;
}
