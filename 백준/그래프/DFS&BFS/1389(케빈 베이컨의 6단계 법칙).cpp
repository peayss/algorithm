// res, visited 배열 초기화 필수 !!!
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int visited[MAX];
int n, m, total, result, min_total = 9999999;

queue<int> q;
vector<int> adj[MAX]; // 친구 관계 배열
int res[MAX]; // 거리 저장 배열

int bfs(int start){
    total = 0;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()){
        int now = q.front(); q.pop();

        for (int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i];
            if (!visited[next]){
                q.push(next);
                visited[next] = 1;
                res[next] = res[now] + 1;
                total += res[next];
            }
        }
    }
    return total;
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        int t = bfs(i);

        if (t < min_total){
            min_total = t;
            result = i;
        }
        memset(visited, 0, sizeof(visited));
        memset(res, 0, sizeof(res));
    }
    cout << result;
}