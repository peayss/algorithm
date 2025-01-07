#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> arr; // 2차원 벡터 선언
vector<char> shortcut; // 단축키 배열
// bool arr[26];
// 'a' 'a' - 97
// set or map
int n;

// 대소문자 구분 x -> 검사할 때 모두 소문자로 변환

// 첫번째 단어가 단축키인지 확인
int check(char key){
    for (int s=0; s<shortcut.size(); s++){
        if (key == shortcut[s]) return 0;
    }
    return 1;
}
// 단축키 함수
void search_shortcut(){ 
    for (int i = 0; i < arr.size(); i++) {
        bool found = false;
        for (int j = 0; j < arr[i].size(); j++) {
            char key = tolower(arr[i][j][0]); // 첫 글자(소문자로 변환)
            if (check(key)) { // 단축키가 없다면
                shortcut.push_back(key); // 첫번째 단어의 첫번째 알파벳이 단축키로
                arr[i][j] = "[" + arr[i][j].substr(0, 1) + "]" + arr[i][j].substr(1);
                found = true;
                break;
            }
        }
        if (!found) { // 모든 단어 첫글자가 단축키라면
            for (int j = 0; j < arr[i].size(); j++) {
                for (int k = 0; k < arr[i][j].size(); k++) {
                    char key = tolower(arr[i][j][k]); // 첫 글자(소문자로 변환)
                    if (check(key)){
                        shortcut.push_back(key);
                        arr[i][j] = arr[i][j].substr(0, k) + "[" + arr[i][j][k] + "]" + arr[i][j].substr(k + 1);
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
    }
}

// 출력 함수
void print(){
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    cin >> n;
    cin.ignore(); // 버퍼에 남은 개행 문자 제거

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s); // 한 줄 입력받음
        stringstream ss(s); // 공백 기준으로 단어를 나누기 위해 stringstream 사용
        vector<string> words; // 단어들을 저장할 벡터

        string word;
        while (ss >> word) { // 공백으로 구분된 단어 추출
            words.push_back(word);
        }

        arr.push_back(words); // 단어 벡터를 2차원 벡터에 추가
    }

    search_shortcut();
    print();

    return 0;
}