#include <bits/stdc++.h>
using namespace std;
struct Node {
    int id, cost;
    Node (int _id, int _cost)
    {
        id = _id;
        cost = _cost;
    }
    bool operator>(const Node& node) const
    {
        return this->cost > node.cost;
    }
};
class Graph
{
    int V;
    vector<Node> *edges;
    int *visited;
public:
    int *Dijkstra_ans;
    Graph(int V)
    {
        this->V = V;
        edges        = new vector<Node>[V];
        visited      = new int[V];
        Dijkstra_ans = new int[V];
    }
    #define Dijkstra_addedge(u, v, w, is_directed) addedge(u, v, w, is_directed)
    void addedge (int u, int v, int w, bool is_directed)
    {
        edges[u].push_back(Node(v, w));
        if (!is_directed)
            edges[v].push_back(Node(u, w));
    }
    void Dijkstra(int src)
    {
        memset(visited, 0, sizeof(int) * V);
        memset(Dijkstra_ans, 0x7f, sizeof(int) * V);
        Dijkstra_ans[src] = 0;
        priority_queue<Node, vector<Node>, greater<Node>> edge;
        edge.push(Node(src, 0));
        while (!edge.empty())
        {
            Node Top = edge.top();
            edge.pop();
            if (visited[Top.id])
                continue;
            visited[Top.id] = 1;
            for (auto& k : edges[Top.id])
            {
                Dijkstra_ans[k.id] = min(Dijkstra_ans[k.id], Top.cost + k.cost);
                edge.push(Node(k.id, Dijkstra_ans[k.id]));
            }
        }
    }
};

int main(void)
{
    // freopen("data.in", "r", stdin);
    // Dijkstra 算法例子
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.Dijkstra_addedge(u, v, w, 0); // 无向边
    }
    g.Dijkstra(0);
    for (int i = 0; i < N; i++)
        cout << i << ": " << g.Dijkstra_ans[i] << endl;
    return 0;
}
