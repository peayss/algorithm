#include <bits/stdc++.h>
#define MAX 100001
#define INF 99999999
using namespace std;

struct Node {
    int dest, cost;
    Node (int _dest, int _cost){
        dest = _dest;
        cost = _cost;
    }
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};

vector<Node>adj[MAX];
priority_queue<Node>pq;
int dest[MAX], visited[MAX];

void dijkstra(int start){
    pq.push(Node(start,0));
    dest[start] = 0;

    while (!pq.empty()){
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;
        visited[now.dest] = 1;

        for (int i=0; i<adj[now.dest].size(); i++){
            Node next = adj[now.dest][i];
            if (dest[next.dest] > dest[now.dest] + next.cost){
                dest[next.dest] = dest[now.dest] + next.cost;
                pq.push(Node(next.dest, dest[next.dest]));
            }
        }
    }
    
}

int main(){
    int n,m; cin >> n >> m;
    for (int i=0; i<m; i++){
        int s,e,c; cin >> s >> e >> c;
        adj[s].push_back(Node(e,c));
    }
    int start, end; cin >> start >> end;
    for (int i=1; i<=n; i++) dest[i] = INF;
    dijkstra(start);
    cout << dest[end];
}