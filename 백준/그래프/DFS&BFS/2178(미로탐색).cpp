#include <bits/stdc++.h>

using namespace std;

struct maze {
    int x, y;
};

int m, n;
int visited[100][100];
int dis[100][100];
int arr[100][100];
queue<maze> q;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int next_x, next_y;

void bfs(int r, int c){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i=0; i<4; i++){
            next_x = x + dx[i];
            next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) 
            continue;
            if (visited[next_x][next_y] == 0 && arr[next_x][next_y] == 1){
                maze next = {next_x, next_y};
                q.push(next);
                dis[next_x][next_y] = dis[x][y] + 1;
                visited[next_x][next_y] = 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            if (s[j] == '1') arr[i][j] = 1;
        }
    }

    visited[0][0] = 1;
    maze start = {0,0};
    q.push(start);
    dis[0][0] = 1;
    bfs(0, 0);
   
    cout << dis[n-1][m-1];
}