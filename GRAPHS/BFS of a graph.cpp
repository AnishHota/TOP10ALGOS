#include<iostream>
#include<vector>
using namespace std;
class Graph
{
  int v;
  vector<int> *adj;
public:
  Graph(int v);
  void addEdge(int v,int w);
  void bfs(int v);
};
Graph::Graph(int v)
{
  this->v = v;
  adj = new vector<int>[v];
}
void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
}
void Graph::bfs(int v)
{
  bool visited[v];
  for(int i=0;i<v;i++)
  {
    visited[i]=false;
  }
  vector<int> que;
  que.push_back(v);
  int s;
  visited[v]=true;
  while(!que.empty())
  {
    s = que[0];
    cout<<s<<" ";
    que.erase(que.begin());
    for(auto x:adj[s])
    {
      if(!visited[x])
      {
        que.push_back(x);
        visited[x]=true;
      }
    }
  }
}
int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.bfs(0);
  return 0;
}
