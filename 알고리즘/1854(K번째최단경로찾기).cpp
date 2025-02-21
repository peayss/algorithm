#include <bits/stdc++.h>
#define MAX 250001
#define INF 999999999
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

int n,m,k;
vector<Node>adj[MAX];
priority_queue<int> res[MAX];
priority_queue<Node>pq;
int dest[MAX];

void dijkstra(int start){
    pq.push(Node(start, 0));
    res[start].push(0);

    while (!pq.empty()){
        Node now = pq.top(); pq.pop();

        for (int i=0; i<adj[now.dest].size(); i++){
            Node next = adj[now.dest][i];
            int next_cost = now.cost + next.cost;
            
            if (res[next.dest].size() < k) {
                res[next.dest].push(next_cost);
                pq.push(Node(next.dest, next_cost));
            } else if (res[next.dest].top() > next_cost) {
                res[next.dest].pop();
                res[next.dest].push(next_cost);
                pq.push(Node(next.dest, next_cost));
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for (int i=0; i<m; i++){
        int s,e,c; cin >> s >> e >> c;
        adj[s].push_back(Node(e,c));
    }
    for (int i=1; i<=n; i++) dest[i] = INF;

    dijkstra(1);
    
    for (int i=1; i<=n; i++){
        if (res[i].size() < k) cout << "-1\n";
        else cout << res[i].top() << '\n';
    }
}