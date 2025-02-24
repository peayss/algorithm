#include <bits/stdc++.h>
#define MAX 300001
#define INF 999999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node (int _dest, int _cost): dest(_dest), cost(_cost) {}
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};

int v,e,k;
vector<Node>adj[MAX];
priority_queue<Node> pq;
int visited[MAX], dist[MAX];

void dijkstra(int start){
    pq.push(Node(start,0));
    dist[start] = 0;

    while (!pq.empty()){
        Node now = pq.top(); pq.pop();

        if (visited[now.dest]) continue;
        visited[now.dest] = 1;
        //cout << "now.dest -> " << now.dest << '\n';
        for (int i=0; i<adj[now.dest].size(); i++){
            Node next = adj[now.dest][i];
            //cout << "next.dest -> " << next.dest << '\n';
            if (dist[next.dest] > dist[now.dest] + next.cost){
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

int main(){
    cin >> v >> e >> k;
    for (int i=0; i<e; i++){
        int s,e,v; cin >> s >> e >> v;
        adj[s].push_back(Node(e,v));
        //adj[e].push_back(Node(s,v));
    }
    for (int i=1; i<=v; i++) dist[i] = INF;   
    dijkstra(k);
    for (int i=1; i<=v; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}