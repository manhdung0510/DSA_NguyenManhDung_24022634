#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100], rnk[100];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(u == v) return;
    if(rnk[u] < rnk[v]) swap(u, v);
    parent[v] = u;
    if(rnk[u] == rnk[v]) rnk[u]++;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(int i=0;i<m;i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    for(int i=0;i<n;i++) parent[i] = i;

    int mst = 0;
    for(auto e : edges) {
        if(findSet(e.u) != findSet(e.v)) {
            mst += e.w;
            unionSet(e.u, e.v);
        }
    }

    cout << "MST = " << mst;
}

