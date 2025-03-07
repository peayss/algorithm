#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
using ll = long long;

struct Node{
    ll dest, cost;
    Node (ll _dest, ll _cost): dest(_dest), cost(_cost) {}
};
ll n,m;
ll dist[501];
vector<Node>adj[501];

int bellmanford(){
    bool isUpdated;
    for (int i=1; i<=n; i++){
        isUpdated = false;
        for (int now=1; now<=n; now++){
            if (dist[now] == INF) continue;
            for (int j=0; j<adj[now].size(); j++){
                Node next = adj[now][j];
                if (dist[next.dest] > dist[now] + next.cost){
                    dist[next.dest] = dist[now] + next.cost;
                    isUpdated = true;
                }
            }
        }
        if (!isUpdated) return 0;
    }
    return 1;
}
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        ll a,b,c; cin >> a >> b >> c;
        adj[a].push_back(Node(b,c));
    }
    for (int i=1; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    if (!bellmanford()){
        for (int i=2; i<=n; i++){
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    } else cout << -1;
}