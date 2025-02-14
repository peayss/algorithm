// 2 3 5 7

// 2로 시작하는 소수 -> dfs -> 출력
// 3로 시작하는 소수 -> dfs -> 출력
// 5로 시작하는 소수 -> dfs -> 출력
// 7로 시작하는 소수 -> dfs -> 출력

#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;

int is_prime(int num){
    for (int i = 2; i < num; i++) {
		if (num%i == 0) {
			return 0;
		}
	}
	return 1;
}
void dfs(int start, int cnt){
    if (is_prime(start) && cnt == n) {
        cout << start << '\n';
        return;
    }
    for (int i=1; i<=9; i++){
        if (i%2 == 0) continue;
        if (is_prime(start*10+i) && cnt <= n){
            //cout << start*10+i << '\n';
            dfs(start*10+i, cnt+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}