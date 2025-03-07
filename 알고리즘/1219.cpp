// 음수, 양수사이클이 발생한 경우 = Gee
// dist[도착지] = INF인 경우 = gg
// 도착지까지 번 돈 - 사용한 돈 출력
// 자기자신 - 자기자신 처리

#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
using ll = long long;

struct Node{
    ll dest, cost;
    Node (ll _dest, ll _cost): dest(_dest), cost(_cost) {}
};

int n,m,start,arrive;
vector<Node>adj[51];
ll dist[51], cost[51];

void bellmanford(){
    for (int i=0; i<n+50; i++){
        for (int now=0; now<n; now++){
            if (dist[now] == LONG_MIN) continue;
            for (int j=0; j<adj[now].size(); j++){
                Node next = adj[now][j];
                if (dist[now] == LONG_MAX) dist[next.dest] = LONG_MAX;
                else if (dist[next.dest] > dist[now] + cost[next.dest] - next.cost){
                    dist[next.dest] = dist[now] + cost[next.dest] - next.cost;
                    if (i>=n-1) dist[next.dest] = LONG_MAX;
                }
            }
        }
    }
}
int main(){
    cin >> n >> start >> arrive >> m;
    for (int i=0; i<m; i++){
        int s,e,c; cin >> s >> e >> c;
        adj[s].push_back(Node(e,c));
    }
    for (int i=0; i<n; i++) {
        cin >> cost[i];
    }
    for (int i=0; i<n; i++) dist[i] = LONG_MIN;
    dist[start] = cost[start];
    bellmanford();
    if (dist[arrive] == LONG_MIN) cout << "gg";
    else if (dist[arrive] == LONG_MAX) cout << "Gee";
    else cout << dist[arrive];
    cout << '\n';
    for (int i=0; i<n; i++) cout << cost[i] << " ";
    cout << '\n';
    for (int i=0; i<n; i++) cout << dist[i] << " ";
}