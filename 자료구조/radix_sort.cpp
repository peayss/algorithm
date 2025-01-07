// 얻어 내고자 하는 값 = (원래의 값 / 얻어 내고자 하는 자리수) % 10
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int arr[MAX];
queue<int> q[10];

void Radix_Sort(int n, int max_value) {
    for (int i = 1; max_value / i > 0; i *= 10) { // 자리수별 반복
        for (int j = 0; j < n; j++) { // 입력된 배열 크기만큼 반복
            int k = (arr[j] / i) % 10; // 현재 자리수 추출
            q[k].push(arr[j]);
        }

        int idx = 0;
        for (int j = 0; j < 10; j++) {
            while (!q[j].empty()) {
                arr[idx++] = q[j].front();
                q[j].pop();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int max_value = 0; // 최대값 초기화
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_value = max(max_value, arr[i]); // 배열 최대값 갱신
    }

    Radix_Sort(n, max_value);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
