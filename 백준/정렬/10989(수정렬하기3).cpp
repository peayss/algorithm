// 계수 정렬 -> 각 숫자의 등장 횟수를 세는 알고리즘 (수의 범위를 활용)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int cnt[10001] = {0};
    int n, count;
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> count;
        cnt[count]++;
    }
    for (int i=1; i<10001; i++){
        for (int j=0; j<cnt[i]; j++)
            cout << i << '\n';
    }
}