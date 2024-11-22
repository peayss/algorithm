#include <bits/stdc++.h>
#define MAX 11
using namespace std;

long long F[MAX];

int main(){
    vector<int> num;
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n;
        cin >> n;
        num.push_back(n);
    }

    F[1] = 1; F[2] = 2; F[3] = 4;
    for (int i=4; i<=MAX; i++){
        F[i] = F[i-1] + F[i-2] + F[i-3];
    }

    for (int i=0; i<t; i++){
        int n = num[i];
        cout << F[n] << '\n';
    }

}