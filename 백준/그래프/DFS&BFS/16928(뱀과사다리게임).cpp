#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int arr[101];
int visited[101];
int n, m, start = 1;

queue<int> q;
int dist[101];

void bfs(){
    while (!q.empty()){
        int now = q.front();
        q.pop();

        if (now == 100){
            cout << dist[100];
            return;
        }

        for (int i = 1; i <= 6; i++){
            int next = now + i;
            if (next > 100) continue;
            if (arr[next]!=0)
                next = arr[next];
            if (arr[next]==0 &&!visited[next]){
                dist[next] = dist[now]+1;
                visited[next] = 1;
                q.push(next);                
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    int now = 1;
    q.push(now);
    visited[1] = 1;
    dist[1] = 0;
    bfs();
}