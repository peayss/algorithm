#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

vector<int> bubble_sort(vector<int> target) {
	int n = target.size();
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (target[j] > target[j + 1]) {
				temp = target[j];
				target[j] = target[j + 1];
				target[j + 1] = temp;
				cnt++;
			}
		}

		// i번째 정렬 결과 출력
		for (int c = 0; c < n; c++) {
			cout << target[c] << " ";
		}
		cout << endl;
	}
	return target;
}

int main(void) {
	int n = 5;
	vector<int> target = { 42, 32, 24, 60, 15, 5, 90, 45 };
	auto result = bubble_sort(target);

	// 최종 정렬 결과 출력
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << cnt << '\n';
	return 0;
}
