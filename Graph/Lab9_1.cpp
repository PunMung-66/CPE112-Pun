// Punnawat Mungkalarungsi 66070503436
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void bfs(vector < vector <int> > graph, int root, int visited[]) {
    queue <int> q;
    q.push(root);
    visited[root] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(vector < vector <int> > graph, int root, int visited[]) {
    stack <int> s;
    s.push(root);
    visited[root] = 1;
    cout << root << " ";

    while (!s.empty()) {
        int u = s.top();
        int i = 0;
        while (i < graph[u].size()) {
            int v = graph[u][i];
            if (visited[v] == 0) {
                visited[v] = 1;
                cout << v << " ";
                s.push(v);
                break;
            }
            i++;
        }
        if (i == graph[u].size()) {
            s.pop();
        }
    }
}

int main ()
{
    int n_edge, n_node = 100;
    cin >> n_edge;
    vector < vector <int> > graph(n_node); // declare graph with 100 nodes
    for (int i = 1; i <= n_edge; i++) {
        int s , d; // from to
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    // for (int i = 0; i < n_edge; i++) {
    //     cout << i << " : ";
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // } // for debugging

    int visited[n_node] = {0};
    int root;
    cin >> root;
    dfs(graph, root, visited);
    cout << endl;
    for (int i = 0; i < n_node; i++) {
        visited[i] = 0;
    }
    bfs(graph, root, visited);
    return 0;
}