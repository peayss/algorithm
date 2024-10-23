#include <bits/stdc++.h>

using namespace std;

struct tomato {
    int x, y;
};

int m, n;
int arr[1000][1000];
int dis[1000][1000];

queue<tomato> q;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int next_x, next_y;

void bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0; i<4; i++){
            next_x = x + dx[i];
            next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
                continue;
            if (arr[next_x][next_y] == 0){
                tomato next = {next_x, next_y};
                q.push(next);
                dis[next_x][next_y] = dis[x][y]+1;
                arr[next_x][next_y] = 1;
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] == 1){
                dis[i][j] = 0;
                tomato start = {i,j};
                q.push(start);
            }
        }
    }
    bfs();
    int max = dis[0][0];
    int flag = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] == 0){
                flag = 1;
            }
            else {
                if (dis[i][j] > max)
                    max = dis[i][j];
            }
        }
    }

    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    if (flag) cout << "-1";
    else cout << max;
    
}