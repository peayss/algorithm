//해결 x
#include <stdio.h>
#include <string.h>
#define MAX 30
int main (void)
{
    char a[MAX];
    char arr[30];
    int top = -1, temp = 0;
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i=0; i<len; i++) {
        temp = 0;
        if (arr[i] == '[' || arr[i] == '(') {
            a[++top] = arr[i];
        }
        else {
            if (arr[i] == ')') {
                if (a[top] == '(') {
                    top--;
                    a[++top] = 2;
                }
                else if (a[top] == '2' || a[top] == '3'){
                    while (a[top] != '(') {
                        temp += a[top]-'0';
                        top--;
                        if (a[top] == '(') {
                            top--;
                            a[++top] = temp*2;
                        }
                    }
                }
            }
            else if (arr[i] == ']') {
                if (a[top] == '[') {
                    top--;
                    a[++top] = 3;
                }
                else if (a[top] == '2' || a[top] == '3'){
                    while (a[top] != '(') {
                        temp += a[top]-'0';
                        top--;
                        if (a[top] == '(') {
                            top--;
                            a[++top] = temp*2;
                        }
                    }
                }
            }
            else if (arr[i] >= '0' && arr[i] <= '9'){
                
            }
        }
    }
    printf("%d\n", a[top]);
}
