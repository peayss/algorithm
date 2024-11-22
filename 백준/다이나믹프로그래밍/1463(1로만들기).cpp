#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int arr[MAX];

int make_one(int n) {
    if (n == 1) return 0;
    if (arr[n] != 0) return arr[n];

    int result = make_one(n - 1) + 1;
    if (n % 2 == 0) result = min(result, make_one(n / 2) + 1);
    if (n % 3 == 0) result = min(result, make_one(n / 3) + 1);
    arr[n] = result;
    return result;
}
int main(){
    int n;
    cin >> n;
    cout << make_one(n);
}