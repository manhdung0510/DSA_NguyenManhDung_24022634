#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;   

int main() {
    int n, m;
    cin >> n >> m;

    int a[100][100];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = INF;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }

    int visited[100] = {0};
    int d[100];
    int parent[100];

    for(int i = 0; i < n; i++) d[i] = INF;
    d[0] = 0;

    int mst = 0;

    for(int i = 0; i < n; i++) {

        int u = -1;
        for(int j = 0; j < n; j++)
            if(!visited[j] && (u == -1 || d[j] < d[u]))
                u = j;

        visited[u] = 1;
        mst += d[u];

        for(int v = 0; v < n; v++)
            if(a[u][v] < d[v] && !visited[v]) {
                d[v] = a[u][v];
                parent[v] = u;
            }
    }

    cout << "MST = " << mst;
}

