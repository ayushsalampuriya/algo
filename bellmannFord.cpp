#include<bits/stdc++.h>

using namespace std;
vector<int> dist(100);

void init()
{
    for(int i=0;i<100;i++)
    {
        dist[i]=INT_MAX;
    }
}

void bellmanFord(int s,vector<int> edges[],int n,int e)
{
    init();

    dist[s] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u]!=INT_MAX && (dist[u]+w<dist[v]))
            {
                dist[v] = dist[u]+w;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << "shortest distance of " << i << " from " << s << " is " << dist[i] << endl;
    }
}

int main()
{
    int n,e;
    cout << "enter number of vertices and edges" << endl;
    cin >> n >> e;

    vector<int> edges[e];
    cout << "source, destination and weight" << endl;

    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >>w;
        edges[i].push_back(s);
        edges[i].push_back(d);
        edges[i].push_back(w);
    }
    int src;
    cout << "enter source vertex" << endl;
    cin >> src;
    bellmanFord(src,edges,n,e);

    return 0;
}
