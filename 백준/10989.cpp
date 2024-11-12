//해결 x
#include <bits/stdc++.h>

using namespace std;
vector<int> target;

void bubble_sort() {
	int n = target.size();
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (target[j] > target[j + 1]) {
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        target.push_back(num);
    }
	bubble_sort();

	// 최종 정렬 결과 출력
	for (int i = 0; i < n; i++) 
		cout << target[i] << " ";
	return 0;
}
