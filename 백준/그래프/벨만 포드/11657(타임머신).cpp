#include <bits/stdc++.h>
#define MAX 501
#define INF 999999999999

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

vector<Node> adj[MAX];
long long dist[MAX];
int n,m;
bool cycle;

void bellmanFord(){
    for (int i=1; i<=n; i++)
        dist[i] = INF;

    dist[1] = 0;
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++) {
            for (int j=0; j<adj[i].size(); j++){
                int next = adj[i][j].dest;
                int nextcost = adj[i][j].cost;
                
                if (dist[i]!=INF && dist[next]>dist[i]+nextcost){
                    dist[next] = dist[i]+nextcost;
                    if (k==n) cycle = true;
                }
            }
        }   
    }
    if (cycle) cout << -1;
    else{
        for(int i=2; i<=n; i++){
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);            

    cin >> n >> m;
    for (int i=0; i<m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start].push_back(Node(end,cost));
    }
    bellmanFord();
}