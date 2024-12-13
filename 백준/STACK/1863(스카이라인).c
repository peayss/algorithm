#include <stdio.h>
#define MAX 50000
int main (void)
{
    int n;
    int arr[MAX][2];
    int stack[MAX];
    int top = -1;
    int count = 0; //집 개수
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    
    for (int i=0; i<n; i++) {
        while (top != -1 && stack[top] > arr[i][1]) {
            count++;
            top--;
        }
        if (top==-1 || (top!=-1 &&stack[top]<arr[i][1])) {
            if (arr[i][1] != 0) {
                stack[++top] = arr[i][1];
            }
        }
    }
    printf("%d\n", count+(top+1));
    
}


