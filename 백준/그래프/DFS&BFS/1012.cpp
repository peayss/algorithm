#include <bits/stdc++.h>

using namespace std;
int T, N, M, K;
int arr[50][50];
int visited[50][50];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int next_x, next_y, cnt;

void dfs(int x, int y){
    for (int i=0; i<4; i++){
        next_x = x + dr[i];
        next_y = y + dc[i];

        if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N ) continue;

        if (arr[next_x][next_y] == 1 && visited[next_x][next_y] == 0) {
            visited[next_x][next_y] = 1;
            dfs(next_x, next_y);
        }
    }
}

int main(){
    cin >> T;
    for (int z=0; z<T; z++){
        cin >> M >> N >> K;
        cnt = 0;
        for (int i=0; i<K; i++){
            int x,y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (arr[i][j] == 1 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
    }
}