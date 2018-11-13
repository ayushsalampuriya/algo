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
int rev(int a,int t)
{
	//we could have used swapping
	int ans=0;
	int j=0;
	for(int i=t;i>=0;i--)
	{
		int x=1<<i;
		int check=a&x;
		if(check)
		{
			ans+=( 1<<j );
		}
		j++;
	}
	return ans;
}
vector<pdd> fun(vector<int> a)
{
	int n=a.size();
	int t=log2(n);
	vector<pdd> ans(n);
	for(int i=0;i<n;i++)
	{
		ans[i]=mp(a[rev(i,t-1)],0);
	}//n=1
	for(int s=1;s<=t;s++)
	{
		int m=(pow(2,s)+0.5);
		for(int i=0;i<n;i+=m)
		{
			pdd wm=find(m),w=mp(1,0);
			for(int j=i;j<i+m/2;j++)
			{
				pdd temp1=ans[j],temp2=ans[j+m/2],tf=mul(temp2,w);
				ans[j]=add(temp1,tf);
				ans[j+m/2]=sub(temp1,tf);
				w=mul(w,wm);
			}
		}
	}
	return ans;
}
int main()
{
	int n;cout<<"enter n"<<endl;
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
		cout<<y[i].F<<"+"<<y[i].S<<"i"<<endl;
	}
}
