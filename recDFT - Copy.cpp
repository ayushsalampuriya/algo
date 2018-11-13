#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair
#define pi 3.14
#define D double
#define F first
#define S second
pdd mul(pdd p1,pdd p2)
{
	return mp(p1.F*p2.F+(-1*p1.S*p2.S),(p1.F*p2.S+p2.F*p1.S));
}
pdd find(int n)
{
	return mp(cos((2*pi)/n),sin((2*pi)/n));
}
pdd add(pdd p1,pdd p2)
{
	return mp(p1.F+p2.F,p1.S+p2.S);
}
pdd sub(pdd p1,pdd p2)
{
	return mp(p1.F-p2.F,p1.S-p2.S);
}
vector<pdd> fun(vector<int> a)
{
	int n=a.size();
	vector<pdd> y(n);
	if(n==1)
	{
		y[0]=mp(a[0],0);
		return y;
	}
	vector<int> t1(n/2),t2(n/2);
	int j1=0,j2=0;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			t1[j1]=a[i];
			j1++;
		}
		else 
		{
			t2[j2]=a[i];
			j2++;
		}
	}
	vector<pdd> y0=fun(t1),y1=fun(t2);
	pdd w=mp(1.0,0);
	pdd wn=find(n);
	for(int k=0;k<=n/2-1;k++)
	{
		y[k]=add(y0[k],mul(w,y1[k]));
		y[k+n/2]=sub(y0[k],mul(w,y1[k]));
		w=mul(w,wn);
	}
	return y;
}
int main()
{
	int n;cout<<"entre n"<<endl;
	cin>>n;
	int k=ceil((double)log2(n));
	int t=pow(2,k);
	vector<int> a(t,0);
	cout<<"enter coefficients in increasing degree"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<pdd> y=fun(a);
	for(int i=0;i<y.size();i++)
	{
		cout<<y[i].F<<"+("<<y[i].S<<"i)"<<endl;
	}
}
