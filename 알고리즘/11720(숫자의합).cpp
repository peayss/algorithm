#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[101];
    int len;
    string num;
    int total = 0;
    cin >> len;
    cin >> num;

    for (int i=0; i<len; i++){
        arr[i] = num[i]-'0';
    }
    for (int i=0; i<len; i++){
        total += arr[i];
    }
    cout << total;
}