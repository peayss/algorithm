#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
int n,m,b;
int low, high;
int highest = -1, t = INT_MAX;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			high = max(high, arr[i][j]);
			low = min(low, arr[i][j]);
		}
	}
    for (int h=low; h<=high; h++){
        int build = 0, remove = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int tmp = arr[i][j] - h;
                if (tmp > 0) remove += tmp;
                else if (tmp < 0) build -= tmp;
            }
        }
        if (remove + b >= build){
            if (t >= remove * 2 + build){
                t = remove * 2 + build;
                highest = h;
            }
        }
    }
    cout << t << " " << highest;
}