#include <bits/stdc++.h>
using namespace std;
#define Node pair<int, int>
#define cost first
#define to   second
class Graph
{
    int V;
    vector<vector<Node>> edges;
    unordered_set<int>   visited;
    vector<int>          Dijkstra_ans;
public:
    Graph(int V)
    {
        this->V = V;
        edges.resize(V);
        Dijkstra_ans.resize(V);
    }
	#define Dijkstra_addedge(u, v, w, is_directed) addedge(u, v, w, is_directed)
    void addedge (int u, int v, int w, bool is_directed)
    {
		edges[u].push_back({w, v});
        if (!is_directed)
			edges[v].push_back({w, u});
    }
    void Dijkstra(int src)
    {
        visited.clear();
        for (int i = 0; i < V; i++)
            Dijkstra_ans[i] = 0x3f3f3f3f;
        Dijkstra_ans[src] = 0;
        priority_queue<Node, vector<Node>, greater<Node>> edge;
        edge.push({0, src});
        while (!edge.empty())
        {
            Node Top = edge.top();
            edge.pop();
            if (visited.find(Top.to) != visited.end())
                continue;
            visited.insert(Top.to);
            for (auto& k : edges[Top.to])
            {
                Dijkstra_ans[k.to] = min(Dijkstra_ans[k.to], Top.cost + k.cost);
                edge.push({Dijkstra_ans[k.to], k.to});
            }
        }
    }
    int get_ans(int des)
    {
        return Dijkstra_ans[des];
    }
};

int main(void)
{
#ifdef __DEBUG__
	freopen("data.in", "r", stdin);
#endif
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.Dijkstra_addedge(u, v, w, 0); // 无向边
        // g.Dijkstra_addedge(u, v, w, 1); // 有向边
    }
    g.Dijkstra(0);
    for (int i = 0; i < N; i++)
        cout << i << ": " << g.get_ans(i) << endl;
    return 0;
}
