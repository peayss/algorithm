#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int arr[MAX][MAX];

int main(){
    int c,r,k;
    cin >> c >> r;
    cin >> k;
    
    if (k > c*r) {
        cout << "0";
        return 0;
    }
    
    int temp_c = 1;
    int temp_r = 1;
    int answer = 0;

    while (answer != c*r)
    {
        // 위로 이동
        for (int i=r; i>0; i--){
            if (temp_r == 1 && arr[i][temp_r] == 0){
                arr[i][temp_r] = ++answer;
            } else if (temp_r != 1 && arr[i][temp_r] == 0){
                arr[i][temp_r] = ++answer;
                temp_c--;
            }
            
        }
        // 오른쪽으로 이동
        for (int i=1; i<=c; i++){
            if (temp_c == 1 && arr[temp_c][i] == 0) {
                arr[temp_c][i] = ++answer;
                temp_r++;
            }
            else if (temp_c != 1 && arr[temp_c][i] == 0) {
                arr[temp_c][i] = ++answer;
                temp_r++;
            }
        }
        // 아래로 이동
        for (int i=1; i<=r; i++){
            if (arr[i][temp_r] == 0) {
                arr[i][temp_r] = ++answer;
                temp_c++;
            }
        }
        // 왼쪽으로 이동
        for (int i=c; i>0; i--){
            if (arr[temp_c][i] == 0) {
                arr[temp_c][i] = ++answer;
                temp_r--;
            }
        }
    }
    int x, y;
    for (int i=1; i<=r; i++){
        for (int j=1; j<=c; j++){
            if (arr[i][j] == k){
                x = i, y = j;
            }
        }
    }
    cout << y << " " << r - x + 1;
}