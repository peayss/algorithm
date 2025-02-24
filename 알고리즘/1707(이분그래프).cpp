#include <bits/stdc++.h>
#define RED 1
#define BLUE 2
using namespace std;

vector<int>adj[20001];
vector<string>res;
int visited[20001];
int v,e; 

// bool check(){
//     for (int i=1; i<=v; i++){
//         for (int j=0; j<adj[i].size(); j++){
//             if (visited[i] == visited[adj[i][j]]) 
//                 return false;
//         }
//     }
//     return true;
// }
int bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start] = RED;

    while (!q.empty()){
        int now = q.front(); q.pop();
        int now_color = visited[now];
        for(int next : adj[now]){
            int next_color = visited[next];
            if (visited[next] == 0){
                q.push(next);
                if (visited[now] == RED) visited[next] = BLUE;
                else if (visited[now] == BLUE) visited[next] = RED;
            } else if (now_color == next_color) return 0;
        }
    }
    return 1;
}

int main(){
    int k; cin >> k;
    for (int i=0; i<k; i++){
        cin >> v >> e;
        for (int j=0; j<e; j++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int result;
        int flag = 0;
        for (int j=1; j<=v; j++){
            if (!visited[j]) {
                result = bfs(j);
                if (!result) {
                    flag = 1;
                    break;
                }
            } 
        }
        if (flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
        // if (check()) res.push_back("YES");
        // else res.push_back("NO");
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++) {
            adj[i].clear(); // 그래프 초기화
        }
    }
    for (int i=0; i<res.size(); i++) cout << res[i] << '\n';
}