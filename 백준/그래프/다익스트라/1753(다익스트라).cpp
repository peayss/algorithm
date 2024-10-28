#include <bits/stdc++.h>
#define MAX 20001
#define INF 999999
using namespace std;

struct Node {
    int dest;
    int cost;
    Node (int _dest, int _cost){
        dest = _dest;
        cost = _cost;
    }
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};

priority_queue<Node> pq;
vector<Node> adj[MAX];

int visited[MAX], dist[MAX];
int v,e,start;

void dijkstra(int start){
    pq.push(Node(start, 0));
    dist[start] = 0;

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();

        if (visited[now.dest]) continue;
        visited[now.dest] = 1;

        for (int i=0; i<adj[now.dest].size(); i++){
            Node next = adj[now.dest][i];
            if (dist[next.dest] > (dist[now.dest] + next.cost)) {
                dist[next.dest] = (dist[now.dest] + next.cost);
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

int main(){
    cin >> v >> e;
    cin >> start;
    for (int i=0; i<e; i++){
        int u,v_,w;
        cin >> u >> v_ >> w;
        adj[u].push_back(Node(v_,w));
    }
    for (int i=1; i<=v; i++)
        dist[i] = INF;

    dijkstra(start);

    for (int i=1; i<=v; i++){
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}