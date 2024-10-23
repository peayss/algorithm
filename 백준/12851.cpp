// visited[MAX] 배열에 수를 증가시키면 안되는 이유? 
// -> 특정 시간에 도달하는 지 알 수 없음 
// 왜 cnt[next] = cnt[now];? 
// 왜 cnt[next] += cnt[now];?

#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int arr[MAX];
int visited[MAX];
int dist[MAX];
int cnt[MAX];
int method[3] = {0,1,2}; // 0은 -1, 1은 +1, 2는 *2

queue<int> q;
int n,k,c;

void bfs(){
    while (!q.empty()){
        int now = q.front(); q.pop();

        for (int i = 0; i < 3; i++){
            int next;
            if (i == 0) next = now - 1;
            if (i == 1) next = now + 1;
            if (i == 2) next = now * 2;

            if (next < 0 || next > MAX) continue;
            //if (next == k && visited[next] == 1 && dist[next] == dist[now]+1) c++;
            
            if (visited[next] == 0){
                dist[next] = dist[now]+1;
                cnt[next] = cnt[now];
                visited[next] = 1;
                q.push(next);                
            } else {
                if (dist[next] == dist[now]+1)
                    cnt[next] += cnt[now];
            }
        }
    }
}

int main() {
    cin >> n >> k;

    q.push(n);
    visited[n] = 1;
    dist[n] = 0; // 시작 위치에서 걸린 시간은 0초
    cnt[n] = 1; // 시작 위치에 도달하는 방법은 1가지

    bfs();

    cout << dist[k] << '\n';
    cout << cnt[k] << '\n';

    for (int i=n; i<=k; i++){
        cout << dist[i] << " ";
    }
    cout << '\n';
    for (int i=n; i<=k; i++){
        cout << cnt[i] << " ";
    }
    //cout << c << "\n";
}