#include <stdio.h>
#include <string.h>
#define MAX 5001
int main (void)
{
    int a[MAX];
    int res[MAX];
    int N,K;
    int k=0,l=0;
    int front = 0, back = 0;
    scanf("%d %d", &N, &K);
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        a[++back] = i; //back = 7, front = 0인 상태
    }
    while (front != back) {
        if (k==K-1) {
            front = (front+1)%(N+1);
            res[l++] = a[front];
            k=0;
            continue;
        }
        front = (front+1)%(N+1);
        back = (back+1)%(N+1);
        a[back] = a[front];
        k++;
    }
    printf("<");
    for (int i=0; i<N; i++) {
        if (i == N-1) {
            printf("%d>\n", res[i]);
            break;
        }
        printf("%d, ", res[i]);
    }
}


