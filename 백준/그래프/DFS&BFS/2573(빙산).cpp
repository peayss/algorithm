#include <bits/stdc++.h>
#define MAX 301
using namespace std;
int n, m;
int arr[MAX][MAX];
int ocean[MAX][MAX]; // 바다(0)의 개수
int visited[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int next_x, next_y;
vector<int> v;

void print(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << ocean[i][j]<< " ";
        }
        cout << '\n';
    }
}

void count_ocean(int x, int y){
    for (int i = 0; i < 4; i++){
        next_x = x + dr[i];
        next_y = y + dc[i];

        if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
        if (arr[next_x][next_y] == 0){
            ocean[x][y]++;
        }
    }
}

void dfs(int x, int y){
    for (int i = 0; i < 4; i++){
        next_x = x + dr[i];
        next_y = y + dc[i];

        if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;

        if (arr[next_x][next_y] > 0 && !visited[next_x][next_y]){
            visited[next_x][next_y] = 1;
            dfs(next_x, next_y);
        }
    }
}

int main(){
    cin >> n >> m;
    int cnt = 0;
    int year = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    while(1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] > 0)
                    count_ocean(i,j);
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (ocean[i][j] > 0){
                    arr[i][j] -= ocean[i][j];
                    if (arr[i][j] < 0){
                        arr[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] > 0 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        year++;

        int flag = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] != 0) flag = 1;
            }
        }

        if(!flag && cnt <= 1) {
            year = 0;
            break;
        }

        if (cnt > 1) break;
        else cnt = 0;

        memset(visited, 0, sizeof(visited));
        memset(ocean, 0, sizeof(ocean));
    }
    cout << year;
}