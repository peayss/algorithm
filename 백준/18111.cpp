// 인벤토리에 블록 X -> 높은 블록 모두 제거
// 인벤토리에 블록 O -> 낮은 블록 인벤토리에서 채워넣기

// 함수화
// 인벤토리에 블록 여부 확인 함수 -> 필요 없음
// 다른 블록 찾는 함수
// 없다면 -> 가장 낮은 블록 높이 찾고 그 높이로 맞추기
// 있다면 -> 가장 낮은 블록 개수 찾고 -> 개수가 충족된다면 -> 채우기

#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
int n,m,b;
int lowest_count, highest_count;
int lowest, highest;

// 낮은 블록, 높은 블록 개수 세기
void search_block(){
    lowest = 257, highest = -1;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] < lowest) lowest = arr[i][j];
            if (arr[i][j] > highest) highest = arr[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] == lowest) lowest_count++;
            if (arr[i][j] == highest) highest_count++;
        }
    }
}
// 채우는 함수
int fill_block(int block){
    int time = 0;
    if (b >= block) {
        time += block;
        return time;
    }
    return 0;
}
// 지우는 함수
int remove_block(int block){
    int time = 2 * block;
    return time;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> b;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    search_block();
    // cout << "lowest : " << lowest << '\n';
    // cout << "highest : "  << highest << '\n';
    // cout << "lowest count : " << lowest_count << '\n';
    // cout << "highest count : " << highest_count << '\n';
    if (fill_block(lowest_count) == 0){
        cout << remove_block(highest_count) << " " << lowest;     
    } else if (fill_block(lowest_count) < remove_block(highest_count)){
        cout << fill_block(lowest_count) << " " << highest;
    } else if (fill_block(lowest_count) == remove_block(highest_count)){
        cout << remove_block(highest_count) << " " << highest;
    } else cout << remove_block(highest_count) << " " << lowest;
}