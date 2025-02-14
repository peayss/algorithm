#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int visited[1001];

int n,m,u,v,cnt=0;

void dfs(int start){
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if (!visited[next]){
            visited[next] = 1;
            dfs(next);
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}