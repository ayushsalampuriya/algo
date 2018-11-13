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
vector<int> g[100];
vector<int> gt[100];
int n;
void topo(int x)
{
  // ans.pb(x);
   vis[x]=1;
   for(int i=0;i<g[x].size();i++)
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
        g[p].pb(q);
        gt[q].pb(p);
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
        scc 1 2 3 4
    }cout<<endl;*/
    stack<int> s=ans;
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        g[i]=gt[i];
    }
    while(!s.empty())
    {
        cout<<s.top()<<":-";
        if(!vis[s.top()])
        topo(s.top());
        while(!ans.empty())
        {
            cout<<ans.top()<<" ";
            ans.pop();
        }cout<<endl;
        s.pop();
    }
    //run topo on reversed graph
    //in order of toopo
    
}