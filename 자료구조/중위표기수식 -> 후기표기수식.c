#include <stdio.h>
#include <string.h>
#define MAX 10000
int prec(char op) {
    if (op == '(' || op == ')')
        return 0;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 2;
}

int main (void)
{
    char a[MAX]; //연산자 스택
    char res[MAX]; //후위 표기 수식
    int k=0; //res idx
    int top = -1;
    char arr[20] = "2+3*(4-5)";
    int len = strlen(arr);
    int flag = 1;
    
    for (int i=0; i<len; i++){
        if (arr[i] >= '0' && arr[i] <= '9'){
            res[k++] = arr[i];
        }
        else if (arr[i] == '('){
            a[++top] = arr[i];
        }
        else if (arr[i] == ')'){
            while (top > -1 && a[top] != '(') {
                res[k++] = a[top--];
            }
            top--;
        }
        else if (arr[i] == '/' || arr[i] == '*' || arr[i] == '+' || arr[i] == '-'){
            while (top > -1 && prec(arr[i]) <= prec(a[top])) {
                res[k++] = a[top--];
            }
            a[++top] = arr[i];
        }
    }
    while (top > -1) {
        res[k++] = a[top--];
    }
    printf("%s\n", res);
}


