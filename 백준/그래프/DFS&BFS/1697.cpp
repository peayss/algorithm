// 범위 체크 -> next가 음수가 되면 x, max보다 크면 x
// next가 k보다 커도 된다

#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int arr[MAX];
int visited[MAX];
int dist[MAX];
int method[3] = {0,1,2}; // 0은 -1, 1은 +1, 2는 *2

queue<int> q;
int n,k;

void bfs(){
    while (!q.empty()){
        int now = q.front(); q.pop();

        if (now == k){
            return;
        }

        for (int i = 0; i < 3; i++){
            int next;
            if (i == 0) next = now - 1;
            if (i == 1) next = now + 1;
            if (i == 2) next = now * 2;

            if (next < 0 || next > MAX) continue;
 
            if (!visited[next]){
                dist[next] = dist[now]+1;
                visited[next] = 1;
                q.push(next);                
            }
        }
    }
}

int main() {
    cin >> n >> k;

    q.push(n);
    visited[n] = 1;
    dist[n] = 0;

    bfs();

    cout << dist[k];
}