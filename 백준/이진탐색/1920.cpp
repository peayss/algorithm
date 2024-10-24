#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

vector<int> arr;
int n, m;

void binarySearch(int key){
    int max = arr.size() - 1;
    int min = 0;

    while ( min <= max ){
        int mid = (min + max) / 2; // 중앙 값

        if (arr[mid] == key){ // key 값을 찾았을 때
            cout << 1 << '\n'; 
            return;
        }else if (arr[mid] > key) // key 값이 mid의 값보다 작을때 (왼쪽으로)
            max = mid - 1;
        else // key 값이 mid의 값보다 클 때(오른쪽으로)
            min = mid + 1;
    }
    cout << 0 << '\n';
}

int main(){
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(nullptr);            // 입출력 묶음 해제
    
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        binarySearch(a);
    }
}
