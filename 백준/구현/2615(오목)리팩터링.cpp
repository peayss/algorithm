// 오목 리펙터링
// 내 위치 이후 5개 보고
// 내 위치 이전 2개 보기
#include <bits/stdc++.h>
#define MAX 
using namespace std;

int dx[4] = {0,1,-1,1}; // 오른쪽, 아래, 오른쪽 위, 오른쪽 아래
int dy[4] = {1,0,1,1};

int arr[20][20];
bool search(int color, int x, int y, int nx, int ny){
    int cnt = 1;
    int tx = x, ty = y;

    for (int i=0; i<5; i++){
        tx += nx;
        ty += ny;
        if (arr[tx][ty] == color) cnt++;
        else break;
    }
    tx = x, ty = y;
    for (int i=0; i<5; i++){
        tx -= nx;
        ty -= ny;
        if (arr[tx][ty] == color) cnt++;
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
    for (int j=1; j<=19; j++){
        for (int i=1; i<=19; i++){ 
            if (arr[i][j] == 0) continue;
            int now = arr[i][j];

            for (int t=0; t<4; t++){
                int nx = dx[t];
                int ny = dy[t];
                if (search(now,i,j,nx,ny)) {
                    cout << now << '\n';
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}