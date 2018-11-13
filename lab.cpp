#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair
#define pi 3.14
#define D double
#define F first
#define S second
#define pb push_back
stack<int> ans;
bool vis[100];
vector<int> a[100];
int n;
void topo(int x)
{
  // ans.pb(x);
   vis[x]=1;
   for(int i=0;i<a[x].size();i++)
   {
       if(vis[a[x][i]]==0)
       topo(a[x][i]);
   }
   ans.push(x);
}
int main()
{
    int e;
    cin>>n>>e;
    while(e--)
    {
        int p,q;
        cin>>p>>q;
        a[p].pb(q);
    }
    for(int i=0;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            topo(i);
        }
    }
    /*for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;*/
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}