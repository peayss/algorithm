#include <bits/stdc++.h>
#define MAX 51
using namespace std;

struct body{
    int x, y;  
    body (int _x, int _y){
        x = _x;
        y = _y;
    }
};
vector<body>arr;
int score[MAX];

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        arr.push_back(body(x,y));
    }
    
    for (int i=0; i<n; i++){
        int cnt = 0;
        for (int j=0; j<n; j++){
            if (i != j && arr[i].x < arr[j].x && arr[i].y < arr[j].y){
                cnt++;
            }
        }
        score[i] = cnt + 1;
    }
    
    for (int i=0; i<n; i++){
        if (score[i] == 0)
            score[i] = 1;
    }
    
    for (int i=0; i<n; i++){
        cout << score[i] << " ";
    }
}