#include <stdio.h>
#include <string.h>
#define MAX 10000

int main (void)
{
    int a[MAX];
    int top = -1;
    char arr[20] = "82/3-";
    int len = strlen(arr);
    int flag = 1;
    
    for (int i=0; i<len; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            a[++top] = arr[i]-'0';
        }
        else if (arr[i] == '/' || arr[i] == '*' || arr[i] == '+' || arr[i] == '-'){
            if (top < 1) {
                flag = 0;
                break;
            }
            else {
                int num1 = a[top--];
                int num2 = a[top--];
                
                if (arr[i] == '/') {
                    a[++top] = num2/num1;
                }
                else if (arr[i] == '*') {
                    a[++top] = num2*num1;
                }
                else if (arr[i] == '+') {
                    a[++top] = num2+num1;
                }
                else if (arr[i] == '-') {
                    a[++top] = num2-num1;
                }
            }
        }
        
    }
    if (flag && top == 0) {
        printf("%d\n", a[top]);
    }
}
