#include <bits/stdc++.h>
#define MAX 50001
#define INF 999999999
using namespace std;

int n,m;

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

void dijkstra(int start){
    
    pq.push(Node(start, 0));
    dist[start] = 0;

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();

        if (visited[now.dest]) continue;
        visited[now.dest] = 1;
        
        for (int i=0; i<adj[now.dest].size(); i++){
            Node next = adj[now.dest][i];
            if (dist[next.dest] > dist[now.dest] + next.cost){
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start].push_back(Node(end, cost));
        adj[end].push_back(Node(start, cost));
    }
    
    for (int i=1; i<=n; i++)
        dist[i] = INF;

    dijkstra(1);
    cout << dist[n];
}