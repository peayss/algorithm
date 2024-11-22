//해결x
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

struct stuff{
    int weight, value;
    stuff (int _weight, int _value){
        weight = _weight;
        value = _value;
    }
};

int n,k;
vector<stuff>v;
int main(){
    cin >> n >> k;
    for (int i=0; i<n; i++){
        int weight, value;
        cin >> weight >> value;
        v.push_back(stuff(weight,value));
    }
    int now_weight, total_value, max=0;
    for(int i=0; i<n; i++){
        now_weight = v[i].weight;
        total_value = 0;
        for(int j=0; j<n; j++){
            if (i!=j && now_weight + v[j].weight == k){
                total_value = v[i].value + v[j].value;
            }
            if (total_value > max) max = total_value;
        }
    }
    cout << max;
}