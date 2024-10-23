//선형큐, 원형큐
#include <stdio.h>
#include <string.h>
#define MAX 10000
int main (void)
{
    int a[MAX];
    int num, front = -1, back = -1;
    char command[20];
    scanf("%d", &num);
    for (int i=0; i<num; i++) {
        scanf("%s", command);
        int len = strlen(command);
        if (command[0] == 'p' && len == 4 ) {
            int X;
            scanf("%d", &X);
            a[++back] = X;
        }
        else if (strcmp(command, "size") == 0) {
            if (front == back) {
                printf("0\n");
            }
            else
                printf("%d\n", back-front);
        }
        else if (strcmp(command, "empty") == 0) {
            if (front == back) {
                printf("1\n");
            }
            else
                printf("0\n");
        }
        else if (strcmp(command, "front") == 0) {
            if (front == back) {
                printf("-1\n");
            }
            else{
                printf("%d\n", a[front+1]);
            }
        }
        else if (strcmp(command, "back") == 0) {
            if (front == back) {
                printf("-1\n");
            }
            else{
                printf("%d\n", a[back]);
            }
        }
        else if (strcmp(command, "pop") == 0) {
            if (front == back) {
                printf("-1\n");
            }
            else{
                printf("%d\n", a[front+1]);
                front++;
            }
        }
    }
}

