// 수 정렬하기
// // 1. sort 내장함수
// #include <bits/stdc++.h>
// using namespace std;

// vector<int>arr;

// int main(){
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++){
//         int num;
//         cin >> num;
//         arr.push_back(num);
//     }
//     sort(arr.begin(), arr.end());
//     for (int i=0; i<n; i++){
//         cout << arr[i] << '\n';
//     }
// }
 // // 2. 퀵 정렬
#include <bits/stdc++.h>
using namespace std;

vector<int>arr;

void quickSort(int start, int end) {
  if (start >= end) return;

  int pivot = start;
  int i = start + 1;
  int j = end;

  while (i <= j) {
    while (arr[i] <= arr[pivot] && i <= end) i++;
    while (arr[j] >= arr[pivot] && j > start) j--;
    if (i > j){ //현재 엇갈린 상태면 pivot 값 교체
        swap(arr[pivot], arr[j]);
    } else {
        swap(arr[i], arr[j]);
    }
    quickSort(start, j - 1);
    quickSort(j + 1, end);
  }
}

int main() {
  int len;
  cin >> len;
  for (int i=0; i<len; i++){
    int num;
    cin >> num;
    arr.push_back(num);
  }
  quickSort(0, len - 1);

  for (int i = 0; i < len; i++) cout << arr[i] << '\n';
  return 0;
}