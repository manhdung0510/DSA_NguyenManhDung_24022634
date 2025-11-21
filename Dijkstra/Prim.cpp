#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    int a[100][100];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = INF;

    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        // a[v][u] = w;
    }

    int dist[100], visited[100]={0};

    for(int i=0;i<n;i++) dist[i] = INF;
    dist[s] = 0;

    for(int i=0;i<n;i++) {
        int u = -1;
        for(int j=0;j<n;j++)
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        visited[u] = 1;

        for(int v=0;v<n;v++)
            if(dist[v] > dist[u] + a[u][v])
                dist[v] = dist[u] + a[u][v];
    }

    for(int i=0;i<n;i++)
        cout << "dist[" << i << "] = " << dist[i] << "\n";
}

