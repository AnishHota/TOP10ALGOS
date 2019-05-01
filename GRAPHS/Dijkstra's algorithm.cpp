#include<iostream>
#include<vector>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
  int v;
  vector<pair<int,int>> *adj;
public:
  Graph(int v);
  void addEdge(int u,int v,int w);
  void dijkstra(int s);
};
Graph::Graph(int v)
{
  this->v = v;
  adj = new vector<pair<int,int>>[v];
}
void Graph::addEdge(int u,int v,int w)
{
  adj[u].push_back(make_pair(v,w));
  adj[v].push_back(make_pair(u,w));
}
void Graph::dijkstra(int s)
{
  //A set of pairs(weight,vertex) for unprocessed vertices
  set<pair<int,int>> setd;
  // A vector for distance from source
  vector<int> dist(v,INT_MAX);
  setd.insert(make_pair(0,s));
  dist[s]=0;
  while(!setd.empty())
  {
    pair<int,int> tmp = *setd.begin();
    setd.erase(setd.begin());
    int u = tmp.second;
    for(auto x:adj[u])
    {
      if(dist[x.first]>dist[u]+x.second)
      {
        if(dist[x.first]!=INT_MAX)
        {
          setd.erase(setd.find(make_pair(dist[x.first],x.first)));
        }
        dist[x.first] = dist[u]+x.second;
        setd.insert(make_pair(dist[x.first],x.first));
      }
    }
  }
  cout<<"Distance from source"<<endl;
  for(int i=0;i<v;i++)
  {
    cout<<i<<" "<<dist[i]<<endl;
  }
}
int main()
{
  int V = 9;
  Graph g(V);

    //  making above shown graph
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  g.dijkstra(0);

  return 0;
}
