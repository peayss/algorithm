#include <bits/stdc++.h>

using namespace std;
int w, h;
int arr[50][50];
int visited[50][50];
int dr[8] = {-1,0,1,0,1,1,-1,-1};
int dc[8] = {0,1,0,-1,1,-1,1,-1};
int next_x, next_y, cnt;
vector<int> v;

void dfs(int x, int y){
    for (int i=0; i<8; i++){
        next_x = x + dr[i];
        next_y = y + dc[i];

        if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w ) continue;

        if (arr[next_x][next_y] == 1 && visited[next_x][next_y] == 0) {
            visited[next_x][next_y] = 1;
            dfs(next_x, next_y);
        }
    }
}

int main(){
    cin >> w >> h;
    while (w!=0 && h!=0) {
        cnt = 0;
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        }
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                if (arr[i][j] == 1 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    dfs(i,j);
                    //cout << i << " " << j << '\n';
                    cnt++;
                }
            }
        }
        v.push_back(cnt);
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        cin >> w >> h;
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}