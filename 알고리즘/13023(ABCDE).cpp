#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[2001];
int visited[2001];
int cnt = 1;

void dfs(int start){
    if (cnt >= 5) {
        cout << 1;
        exit(0);
    }
    visited[start] = 1;
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        cout << "start : " << start << "\n";
        cout << "next : " << next << "\n";
        if (!visited[next]){
            cnt++;
            cout << "방문할 노드는 : " << next << '\n';
            cout << "cnt : " << cnt << '\n';
            visited[next] = 1;
            dfs(next);
        }
    }
    visited[start] = 0;
    cnt--;
}
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; i++){
        cout << "adj[" << i << "] = ";
        for (int j=0; j<adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i=0; i<n; i++){
        cnt = 1;
        memset(visited, 0, sizeof(visited));
        dfs(i);
        cout << "i가 " << i << " 일 때 -> cnt : " << cnt << '\n';
    }
    cout << 0;
}
