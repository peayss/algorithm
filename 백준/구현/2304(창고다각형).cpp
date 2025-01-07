#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
    int n;
    cin >> n;
    int end_l = -1, max_l = -1, max_h = -1, start_l = 1002;
    for (int i=0; i<n; i++){
        int l,h;
        cin >> l >> h;
        arr[l] = h;
        if (l > end_l) end_l = l; // 끝점
        if (l < start_l) start_l = l; // 시작점
        if (h > max_h) {
            max_h = h; // 최대 높이 기둥의 h
            max_l = l; // 최대 높이 기둥의 l
        }
    }

    int total = 0;
    // 시작부터 최대 높이 기둥까지
    for (int i=start_l+1; i<=max_l; i++){
        if (arr[i] < arr[i-1]) arr[i] = arr[i-1];
    }
    // 끝부터 최대 높이 기둥까지
    for (int i=end_l-1; i>max_l; i--){
        if (arr[i] < arr[i+1]) arr[i] = arr[i+1];
    }
    for (int i=start_l; i<=end_l; i++){
        total += arr[i];
    }
    cout << total;
}