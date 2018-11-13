#include<bits/stdc++.h>
using namespace std;
int rev(int a,int t)
{
	//we could have used swapping
	int ans=0;
	int j=0;
    cout<<"a="<<a<<endl;
	for(int i=t;i>=0;i--)
	{
		int x=1<<i;
        cout<<"a="<<a<<" x="<<x<<endl;
		int check= a&x;
        cout<<"check="<<check<<endl;
		if(check)
		{
			ans+=( 1<<j );
		}
        cout<<"ans="<<ans<<endl;
		j++;
	}
	return ans;
}
int main()
{
    cout<<rev(0,1)<<endl;
    cout<<rev(1,1)<<endl;
    cout<<rev(2,1)<<endl;
    cout<<rev(3,1)<<endl;
}