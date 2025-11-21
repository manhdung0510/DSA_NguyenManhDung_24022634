#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main() {
    int n, m;
    cin >> n >> m;

    int a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }

    int comp[100];
    for (int i = 0; i < n; i++)
        comp[i] = i;

    int mst = 0;
    int edges = 0;

    while (edges < n - 1) {

        int min_w = INF;
        int u_best = -1, v_best = -1;

        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (a[u][v] < min_w && comp[u] != comp[v]) {
                    min_w = a[u][v];
                    u_best = u;
                    v_best = v;
                }
            }
        }
        mst += min_w;
        edges++;

        int old_comp = comp[v_best];
        int new_comp = comp[u_best];

        for (int i = 0; i < n; i++)
            if (comp[i] == old_comp)
                comp[i] = new_comp;
    }

    cout << "MST = " << mst;
}
