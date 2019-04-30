#include<iostream>
#include<vector>
using namespace std;
class Graph
{
  int v;
  vector<int> *adj;
  void dfsUtil(int v,bool visited[]);
  public:
    Graph(int v);
    void dfs(int v);
    void addEdge(int v,int w);
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
void Graph::dfsUtil(int v,bool visited[])
{
  visited[v] = true;
  cout<<v<<" ";
  for(auto x:adj[v])
  {
    if(!visited[x])
      dfsUtil(x,visited);
  }
}
void Graph::dfs(int v)
{
  bool *visited = new bool[v];
  for(int i=0;i<v;i++)
  {
    visited[i] = false;
  }
  dfsUtil(v,visited);
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
  cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
  g.dfs(2);
  return 0;
}
