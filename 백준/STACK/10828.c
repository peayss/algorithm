#include <stdio.h>
#include <string.h>
#define MAX 10000
int main(void)
{
    int a[MAX];
    int top = -1;
    char command[20];
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%s", command);
        int len = strlen(command);
        if (command[0] == 'p' && len == 4 ) {
            int X;
            scanf("%d", &X);
//            int num = 0;
//            for (int i=5; i<len; i ++) {
//                num *= 10;
//                num += (command[i]-'0');
//            }
            a[++top] = X;
        }
        else if (strcmp(command, "top") == 0) {
            if (top == -1) {
                printf("-1\n");
            }
            else printf("%d\n", a[top]);
        }
        else if (strcmp(command, "size") == 0) {
            if (top == -1) {
                printf("0\n");
            }
            else
                printf("%d\n", top+1);
        }
        else if (strcmp(command, "empty") == 0) {
            if (top == -1) {
                printf("1\n");
            }
            else
                printf("0\n");
        }
        else if (strcmp(command, "pop") == 0) {
            if (top == -1) {
                printf("-1\n");
            }
            else{
                printf("%d\n", a[top--]);
            }
        }
        
    }
    
}
