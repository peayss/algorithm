#include <bits/stdc++.h>
using namespace std;

int arr[20][20];
// 가로
bool horizontal(int color, int x, int y){
    int cnt = 1;
    for (int i=y+1; i<=19; i++){
        if (arr[x][i] == color) cnt++;
        else break;
    }
    for (int i=y-1; i>=1; i--){
        if (arr[x][i] == color) cnt++;
        else break;
    }
    if (cnt == 5) return true;
    return false;
}
// 세로
bool vertical(int color, int x, int y){
    int cnt = 1;
    for (int i=x+1; i<=19; i++){
        if (arr[i][y] == color) cnt++;
        else break;
    }
    for (int i=x-1; i>=1; i--){
        if (arr[i][y] == color) cnt++;
        else break;
    }
    if (cnt == 5) return true;
    return false;
}
// 오른쪽 위로 대각선
bool diagonal_right(int color, int x, int y){
    int cnt = 1;
    int nx = x - 1, ny = y + 1;
    for (int i=ny; i<=19; i++){
        if (nx >= 1 && arr[nx][i] == color) {
            cnt++;
            nx--;
        }
        else break;
    }
    nx = x + 1, ny = y - 1;
    for (int i=ny; i>=1; i--){
        if (nx <= 19 && arr[nx][i] == color) {
            cnt++;
            nx++;
        }
        else break;
    }
    if (cnt == 5) return true;
    return false;
}
// 오른쪽 아래로 대각선
bool diagonal_right_down(int color, int x, int y){
    int cnt = 1;
    int nx = x + 1, ny = y + 1;
    for (int i=ny; i<=19; i++){
        if (nx <= 19 && arr[nx][i] == color) {
            cnt++;
            nx++;
        }
        else break;
    }
    nx = x - 1, ny = y - 1;
    for (int i=ny; i>=1; i--){
        if (nx >= 1 && arr[nx][i] == color){
            cnt++;
            nx--;
        }
        else break;
    }
    if (cnt == 5) return true;
    return false;
}

int main(){
    for (int i=1; i<=19; i++){
        for (int j=1; j<=19; j++){
            cin >> arr[i][j];
        }
    }
    int color;
    for (int j=1; j<=19; j++){
        for (int i=1; i<=19; i++){
            if (arr[i][j] == 0) continue;
            color = arr[i][j];
            
            if (horizontal(color, i, j) || vertical(color, i, j) || diagonal_right(color, i, j) || diagonal_right_down(color, i, j)){
                cout << color << '\n';
                cout << i << " " << j;
                return 0;
            } 
        }  
    }
    cout << 0;
    return 0;
}