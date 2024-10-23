#include <stdio.h>
#include <string.h>
#define MAX 10000
int main(void)
{
    char a[MAX];
    int top = -1;
    char arr[20] = "{ A[(i+1)]=0; }";
    int len = strlen(arr);
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
        if (flag)
            printf("%s 괄호검사성공\n", arr);
        else
            printf("%s 괄호검사실패\n", arr);
        
}

