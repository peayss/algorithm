#include <bits/stdc++.h>
using namespace std;

int N, M, x;
long long cnt[1001];
long long prefix_sum[1001];
long long sum, ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> x;
		sum += x;
		prefix_sum[i] = sum % M;
		if (prefix_sum[i] == 0) ans++;
	}
	// 1 0 0 1 0
	// 1은 1이 상쇄시켜주고
	// 0은 0이 상쇄시켜준다

	// 1. 0의 값은 이미 3으로 나눠떨어지기때문에 ans += 3
	// index = 0, 값 = 1 -> cnt[1] = 0 ? -> cnt[1]++; cnt[1] = 1; 상쇄 불가
	// index = 1, 값 = 0 -> cnt[0] = 0 ? -> cnt[0]++; cnt[0] = 1; 상쇄 불가
	// index = 2, 값 = 0 -> cnt[0] = 1 ? -> cnt[0]++; cnt[0] = 2; 상쇄 가능 ans += 1 
	// index = 3, 값 = 1 -> cnt[1] = 1 ? -> cnt[1]++; cnt[1] = 2; 상쇄 가능 ans += 1
	// index = 4, 값 = 0 -> cnt[0] = 2 ? -> cnt[0]++; cnt[0] = 3; 상쇄 가능 ans += 2

	for (int i=0; i<N; i++){
		if(cnt[prefix_sum[i]] == 0) cnt[prefix_sum[i]]++;
		else {
			ans += cnt[prefix_sum[i]];
			cnt[prefix_sum[i]]++;
		}
	}
	cout << ans;
}