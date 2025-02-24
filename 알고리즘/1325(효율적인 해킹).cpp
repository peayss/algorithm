#include <bits/stdc++.h>
using namespace std;

int n,m,cnt=0;
vector<int>adj[100001];
priority_queue<int, vector<int>, greater<int>> pq; 
int res[100001];
int visited[100001];

void dfs(int start){
    visited[start] = 1;
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if (!visited[next]){
            visited[next] = 1;
            cnt++;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int max = 0;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++){
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        dfs(i);
        res[i] = cnt;
        if (cnt > max) max = cnt;
    }
    for (int i=1; i<=n; i++) {
        if (res[i] == max) pq.push(i);
    }
    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    } 
}