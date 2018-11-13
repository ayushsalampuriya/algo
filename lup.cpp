#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter Dimension of Matrix : ";
	cin >> n;
	int i,j,k;
	float a[n][n],b[n],x[n],y[n],l[n][n],u[n][n];
	memset(l,0,sizeof(l));
	memset(u,0,sizeof(u));
	cout << "Enter Coefficient Matrix : " << endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin >> a[i][j];
	cout << "Enter Constant Vector : " << endl;
	for(i=0;i<n;i++)
		cin >> b[i];
	for(k=0;k<n;k++) // LU DECOMPOSITION
	{
		u[k][k] = a[k][k];
		for(i=k+1;i<n;i++)
		{
			l[i][k] = a[i][k]/u[k][k];
			u[k][i] = a[k][i];
		}
		for(i=k+1;i<n;i++)
		{
			for(j=k+1;j<n;j++)
				a[i][j] = a[i][j] - l[i][k]*u[k][j];
		}
	}
	for(i=0;i<n;i++)
		l[i][i] = 1;
	for(i=0;i<n;i++) // Y CALCULATION
	{
		float sum=0;
		for(j=0;j<i;j++)
			sum += l[i][j]*y[j];
		y[i] = b[i] - sum;
	}
	for(i=n-1;i>=0;i--) // X CALCULATION
	{
		float sum=0;
		for(j=i+1;j<n;j++)
			sum += u[i][j]*x[j];
		x[i] = (y[i] - sum)/u[i][i];
	}
	cout << "L Matrix : " << endl; // L PRINTING
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout << l[i][j] << "  ";
		cout << endl;
	}
	cout << "U Matrix : " << endl; // U PRINTING
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout << u[i][j] << "  ";
		cout << endl;
	}
	cout << "Y Vector : " << endl; // Y PRINTING
	for(i=0;i<n;i++)
		cout << y[i] << "  ";
	cout << endl;
	cout << "X Vector : " << endl; // X PRINTING
	for(i=0;i<n;i++)
		cout << x[i] << "  ";
	cout << endl;
	return 0;
}
