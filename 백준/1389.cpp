#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int visited[MAX];
int n, m, total, result, min_total = 999;

queue<int> q;
vector<int> adj[MAX]; // 친구 관계 배열
int res[MAX][MAX];
int dist[101];

void bfs(){
    while (!q.empty()){
        int now = q.front(); 
        q.pop();

        for(int i=0; i<adj[now].size(); i++){
            int next = adj[now][i+1];
            if (visited[next] == 0){
                q.push(next);
                visited[next] = 1;
                res[i][next] = res[i][now] + 1;
                res[next][i] = res[now][i] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=1; i<=n; i++){
        total = 0;
        int now = i;
        q.push(now);
        visited[now] = 1;
        bfs();

        for (int j=1; j<=n; j++){
            total += res[now][j];
        }

        if (total < min_total){
            min_total = total;
            result = i;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            cout << res[i][j];
        cout << '\n';
    }
    cout << result;
    
}