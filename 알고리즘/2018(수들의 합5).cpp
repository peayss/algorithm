#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int start = 0, end = 1, total = 1, cnt = 0;
    while (end != num) {
        if (total == num) {
            cnt++;
            end++;
            total += end;
        }
        if (total > num) {
            total -= start;
            start++;
        }
        if (total < num) {
            end++;
            total += end;
        }
    }
    cout << cnt + 1;
}