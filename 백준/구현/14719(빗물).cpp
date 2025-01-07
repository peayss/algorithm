#include <bits/stdc++.h>
using namespace std;

int arr[501];
int rain[501];

int main(){
    int h, w, max = -1, max_idx;
    cin >> h >> w;
    for (int i=0; i<w; i++){
        cin >> arr[i];
        if (max < arr[i]) {
            max = arr[i];
            max_idx = i;
        }
    }
    for (int i=1; i<=max_idx; i++){
        if (arr[i] < arr[i-1]) {
            rain[i] = arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    for (int i=w-2; i>max_idx; i--){
        if (arr[i] < arr[i+1]) {
            rain[i] = arr[i+1] - arr[i];
            arr[i] = arr[i+1];
        }
    }
    int total = 0;
    for (int i=0; i<w; i++){
        total += rain[i];
    }
    cout << total;
}