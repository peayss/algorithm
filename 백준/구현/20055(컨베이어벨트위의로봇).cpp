#include <bits/stdc++.h>
#define MAX 201
using namespace std;

int arr[MAX]; // 내구도 배열 
int robot[MAX]; // 로봇 배열
int n, k, cnt = 0;
int Start = 1, End;
// 회전 -> 이동 -> 올리기
void rotate(){
    Start = Start - 1 > 0 ? Start - 1 : 2 * n;
    End = End - 1 > 0 ? End - 1 : 2 * n;
    robot[End] = 0;
}
void move(){
    int c = End;
    for (int i = 0; i < n - 1; i++){
        int prev = c - 1 > 0 ? c - 1 : 2 * n;
        if (!robot[c] && arr[c]>0 && robot[prev]){
            robot[c] = 1;
            robot[prev] = 0;
            arr[c]--;
            if (arr[c] == 0) cnt++;
            robot[End] = 0;
        }
        c = prev;
    }
}
void add_robot(){
    if (arr[Start] > 0){
        robot[Start] = 1;
        arr[Start]--;
        if (arr[Start] == 0) cnt++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    End = n;
    for (int i=1; i<=2*n; i++){
        cin >> arr[i];
    }
    int level = 0;
    while (cnt < k){
        level++;
        rotate();
        if (level > 1) move();
        add_robot();
    }
    cout << level;
}