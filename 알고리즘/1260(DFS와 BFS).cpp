#include <bits/stdc++.h>
using namespace std;

int n,m,v;
vector<int>adj[1001];
queue<int> q;
int visited[1001];

void dfs(int start){
    cout << start << " ";
    visited[start] = 1;
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if (!visited[next]){
            visited[next] = 1;
            dfs(next);
        }
    }
}
void bfs(int start){
    cout << '\n' << start << " ";
    q.push(start);
    visited[start] = 1;

    while (!q.empty()){
        int now = q.front(); q.pop();

        for (int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i];
            if (!visited[next]){
                q.push(next);
                visited[next] = 1;
                cout << next << " ";
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> v;
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    memset(visited, 0, sizeof(visited));
    bfs(v);
}