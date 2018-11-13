#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ex(ll a,ll b,ll c)
{
	ll ans=1,p=a;
	while(b>0)
	{
		cout<<"curr_val= "<<ans<<" curr_multiplier="<<p<<endl;
		if(b%2==1)
		{
			ans=(ans*p)%c;
		}
		p=(p*p)%c;
		b/=2;
	}
	return ans;
} 
int main()
{
	int t;
	cout<<"enter no of tests"<<endl;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<"ans= "<<ex(a,b,c)<<endl;	
	}
}
