#include <stdio.h>
#include <string.h>
#define MAX 50
int main (void)
{
    int N;
    scanf("%d", &N);
    
    int arr[MAX];
    int nge[MAX];
    int stack[MAX];
    int top = -1;

    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<N; i++) {
        while (top != -1 && arr[stack[top]] < arr[i]) {
                    nge[stack[top]] = arr[i];
                    top--;
                }
            stack[++top] = i;
    }
        
    while (top != -1) {
        nge[stack[top]] = -1;
        top--;
    }
    for (int i=0; i<N; i++) {
        printf("%d ", nge[i]);
    }
    printf("\n");
}
