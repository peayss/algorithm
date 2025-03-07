#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

struct Node{
    int dest, cost;
    Node (int _dest, int _cost) : dest(_dest), cost(_cost) {}
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};
vector<Node>adj[10001];
priority_queue<Node>pq;
int visited[10001], dist[10001];
int last;

void dijkstra(int start){
    pq.push(Node(start,0));
    dist[start] = 0;
    while (!pq.empty()){
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;
        visited[now.dest] = 1;
        last = now.dest;
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
    int t; cin >> t;
    for (int i=0; i<t; i++){
        int n,d,c; 
        cin >> n >> d >> c;
        int cnt = 0;
        for (int i=1; i<=n; i++) {
            dist[i] = INF;
            visited[i] = 0;
            adj[i].clear();
        }
        for (int j=0; j<d; j++){
            int a,b,s; 
            cin >> a >> b >> s;
            adj[b].push_back(Node(a,s));
        }
        memset(visited, 0, sizeof(visited));
        for (int i=1; i<=n; i++) dist[i] = INF;
        dijkstra(c);
        for (int i=1; i<=n; i++) {
            if (dist[i] != INF) cnt++;
        }
        //for (int i=1; i<=n; i++) cout << dist[i] << '\n';
        cout << cnt << " " << dist[last] << '\n';
    }
}