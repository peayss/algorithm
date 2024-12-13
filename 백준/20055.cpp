#include <bits/stdc++.h>
#define MAX 201
using namespace std;

vector<int>arr={-1};
vector<int>robot={-1};

int n,k;
int start, end, cnt;
// 회전 -> 이동 -> 올리기
void rotate(){ 
    int end = arr[2*n];
    
    for (int i=2*n; i>1; i--){
        arr[i] = arr[i-1];
        robot[i] = robot[i-1];
        if (i == n && robot[i]){
            robot[i] = 0;
        }
    }
    arr[1] = end;
}
void move_robot(){
    for (int i=n; i>1; i--){
        if (!robot[i] && arr[i]>0 && robot[i-1]){
            robot[i] = 1;
            robot[i-1] = 0;
            arr[i]--;
            if (arr[i] == 0) cnt++;
        }
        if (i == n && robot[n]){
            robot[i] = 0;
        }
    }
}
void add_robot(){
    if (!robot[1] && arr[1] > 0){
        robot[1] = 1;
        arr[1]--;
        if (arr[1] == 0) cnt++;
    }
}
int main(){
    cin >> n >> k;
    for (int i=1; i<=2*n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
        robot.push_back(0);
    }
    int level = 0;
    while (cnt != k){
        level++;
        rotate();
        move_robot();
        add_robot();
        // for(int i=1; i<=robot.size(); i++){
        //     cout << robot[i] << " ";
        // }
        // cout << '\n';
    }
    cout << level;
}