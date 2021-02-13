#include <bits/stdc++.h>
using namespace std;

struct Edge
{
  int to;
  long long cost;
  long long cap;
  int rev;
  bool isRev;
};

struct Graph
{
  vector<vector<Edge>> graph;

  Graph(int n)
  {
    graph.resize(n);
  }

  int size()
  {
    return graph.size();
  }

  vector<Edge> &at(int n)
  {
    return graph.at(n);
  }

  void addEdge(int from, int to, long long cost, long long cap)
  {
    graph[from].push_back(Edge{to, cost, cap, (int)graph[to].size(), false});
    graph[to].push_back(Edge{from, -cost, 0, (int)graph[from].size() - 1, true});
  }
};

class BusackerGowen
{
private:
  vector<long long> potential, minCost;
  vector<int> prevE, prevV;

public:
  long long minCostFlow(Graph &graph, int start, int goal, long long flow)
  {
    int n = graph.size();
    long long ret = 0;
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    potential.assign(n, 0);
    prevE.assign(n, -1);
    prevV.assign(n, -1);

    while (flow > 0)
    {
      minCost.assign(n, LONG_MAX);
      pq.emplace(0, start);
      minCost.at(start) = 0;
      while (pq.size())
      {
        long long cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        if (minCost.at(cur) < cost)
        {
          continue;
        }
        for (int i = 0; i < graph.at(cur).size(); i++)
        {
          auto &e = graph.at(cur).at(i);
          auto nextCost = minCost.at(cur) + e.cost + potential.at(cur) - potential.at(e.to);
          if (e.cap > 0 && minCost.at(e.to) > nextCost)
          {
            minCost.at(e.to) = nextCost;
            prevV.at(e.to) = cur, prevE.at(e.to) = i;
            pq.emplace(minCost.at(e.to), e.to);
          }
        }
      }
      if (minCost.at(goal) == LONG_MAX)
      {
        return -1;
      }
      for (int v = 0; v < n; v++)
      {
        potential.at(v) += minCost.at(v);
      }
      long long addedFlow = flow;
      for (int v = goal; v != start; v = prevV.at(v))
      {
        addedFlow = min(addedFlow, graph.at(prevV.at(v)).at(prevE.at(v)).cap);
      }
      flow -= addedFlow;
      ret += addedFlow * potential.at(goal);
      for (int v = goal; v != start; v = prevV.at(v))
      {
        auto &e = graph.at(prevV.at(v)).at(prevE.at(v));
        e.cap -= addedFlow;
        graph.at(v).at(e.rev).cap += addedFlow;
      }
    }
    return ret;
  }
};

int main()
{
  long long v, e, f;
  cin >> v >> e >> f;
  Graph graph(v);
  for (int i = 0; i < e; i++)
  {
    long long from, to, cap, cost;
    cin >> from >> to >> cap >> cost;
    graph.addEdge(from, to, cost, cap);
  }
  BusackerGowen bg;
  cout << bg.minCostFlow(graph, 0, v - 1, f) << endl;
}
