#include <bits/stdc++.h>
using namespace std;

vector<int>adj[200001];
vector<string>res;

int visited[200001];

void dfs(int start){
    visited[start] = 1;
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if (!visited[next]){
            visited[next] = 1;
            dfs(next);
        }
    }
}

int main(){
    int k,v,e,cnt=0,flag=0;
    cin >> k;
    for (int i=0; i<k; i++){
        flag=0;
        cin >> v >> e;
        for (int j=0; j<e; j++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int z=1; z<v; z++){
            dfs(z);
            cnt++;
            if (cnt == 2) {
                res.push_back("YES");
                // cout << "YES" << '\n';
                flag = 1;
                continue;
            }
        }
        if (!flag) res.push_back("NO");
        memset(visited, 0, sizeof(visited));
        memset(adj, 0, sizeof(adj));
    }
    for (int i=0; i<res.size(); i++){
        cout << res[i] << '\n';
    }
}