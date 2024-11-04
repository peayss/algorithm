#include <bits/stdc++.h>
#define MAX 1001
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

int n,m,x;
vector<Node> adj[MAX];
priority_queue<Node> pq;

int visited[MAX], dist[MAX];

void dijkstra(int start){

    for (int i=0; i<=n; i++){
        dist[i] = INF;
    }

    memset(visited, 0, sizeof(visited));

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
    
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(nullptr);            // 입출력 묶음 해제

    cin >> n >> m >> x;
    for (int i=0; i<m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start].push_back(Node(end,cost));
    }
    for (int i=1; i<=n; i++)
        dist[i] = INF;

    int res[n];

    for (int i=1; i<=n; i++){
        dijkstra(i); // 1번 마을 
        res[i] = dist[x]; // 1번 -> 2번 마을까지의 최단 거리
    }

    dijkstra(x); // 2번 마을 -> 각자 집으로 가는 최단 거리
    for (int i=1; i<=n; i++){
        res[i] += dist[i];
    }

    int max = res[1];
    for (int i=1; i<=n; i++){
        if (res[i] > max)
            max = res[i];
    }

    cout << max;
}