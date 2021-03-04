#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
public:
    int **adj_matrix;
    Graph(int V)
    {
        this->V = V;
        adj_matrix        = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adj_matrix[i] = new int[V];
            memset(adj_matrix[i], 0x3f, sizeof(int) * V);
            adj_matrix[i][i] = 0;
        }
    }
    #define Floyd_addedge(u, v, w, is_directed) addedge(u, v, w, is_directed)
    void addedge(int u, int v, int w, bool is_directed)
    {
        adj_matrix[u][v] = w;
        if (!is_directed)
            adj_matrix[v][u] = w;
    }

    void Floyd  (void)
    {
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[j][k]);
    }
};
int main(void)
{
    // freopen("data.in", "r", stdin);
    // Floyd 算法例子
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--)
    {
        int u, v, w;
	    cin >> u >> v >> w;
        g.Floyd_addedge(u, v, w, 0); // 无向边
    }
    g.Floyd();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << "(" << i << ", " << j << "): " << g.adj_matrix[i][j] << endl;
    return 0;
}
