#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000001];
priority_queue<int, vector<int>, greater<int>> res;
queue<int> q;
int dist[1000001];

int n,m,k,x,cnt;

void bfs(){
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<adj[now].size(); i++){
            int next = adj[now][i];
            if (dist[next] == -1){
                q.push(next);
                dist[next] = dist[now] + 1;
                if (dist[next] == k) {
                    res.push(next);
                    cnt++;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k >> x;
    for (int i=0; i<m; i++){
        int s,e; cin >> s >> e;
        adj[s].push_back(e);
    }
    memset(dist, -1, sizeof(dist));
    dist[x] = 0;
    q.push(x);
    bfs();
    if (!cnt) cout << -1;
    else {
        while (!res.empty())
        {
            cout << res.top() << '\n';
            res.pop();
        }
    }
}