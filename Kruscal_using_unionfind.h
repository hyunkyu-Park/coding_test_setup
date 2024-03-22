#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

int V; // 정점의 수
vector<int> parent; // 각 정점의 부모를 저장하는 배열

// 부모를 찾는 함수 (Union-Find)
int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

// 두 정점을 합치는 함수 (Union)
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[v] = u;
}

// Kruskal 알고리즘
vector<Edge> kruskal(vector<Edge>& edges) {
    parent.resize(V);
    for (int i = 0; i < V; ++i) parent[i] = i;

    vector<Edge> result;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (find(u) != find(v)) {
            merge(u, v);
            result.push_back(edge);
        }
    }

    return result;
}

int main() {
    // 입력 받기
    int E; // 간선의 수
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Kruskal 알고리즘 실행
    vector<Edge> minimumSpanningTree = kruskal(edges);

    // 최소 신장 트리 출력
    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    return 0;
}
