#include <stdio.h>
#include <string.h>
#define MAX 10000
int main(void)
{
    char a[MAX];
    char arr[50];
    int num;
    scanf("%d", &num);
    for (int j=0; j<num; j++){
        scanf("%s", arr);
        int len = strlen(arr);
        int top = -1;
        int flag = 1;

        for (int i=0; i<len; i++) {
            if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[') {
                a[++top] = arr[i];
            }
            else if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']'){
                if (top == -1) {
                    flag = 0;
                    break;
                }
                else{
                    if ((arr[i] == '}' && a[top] == '{') || (arr[i] == ']' && a[top] == '[') || (arr[i] == ')' && a[top] == '(')) {
                        top--;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (top != -1) {
            flag = 0;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

