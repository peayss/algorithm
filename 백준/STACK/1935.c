//해결 x
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
    char arr[20]; int n;
    char alpha_arr[26];
    scanf("%d", &n);
    scanf("%s", arr);
    int len = strlen(arr);
    int flag = 1;
    
    for (int i=0; i<n; i++) {
        scanf("%s", &alpha_arr[i]);
    }
    
    for (int i=0; i<len; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            a[++top] = alpha_arr[k];
            k++;
        }
        else
            a[++top] = arr[i];
    }
    
    //    for (int i=0; i<len; i++) {
    //        printf("%c ", a[i]);
    //    }
    
    for (int i=0; i<len; i++) {
        if (arr[i] == '/' || arr[i] == '*' || arr[i] == '+' || arr[i] == '-'){
            if (top < 1) {
                flag = 0;
                break;
            }
            else {
                double num1 = a[top--];
                double num2 = a[top--];
                
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
        printf("%d\n", a[top]-'0');
    }
    
    
}


