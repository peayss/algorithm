#include <stdio.h>
#define MAX 300

int main(void) {
    int N;
    scanf("%d", &N);

    int arr[MAX];   // 탑의 높이를 저장할 배열
    int stack[MAX]; // 스택 (인덱스를 저장)
    int res[MAX];   // 결과를 저장할 배열
    int top = -1;   // 스택의 꼭대기를 나타내는 변수

    // 탑의 높이를 입력받음
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 레이저 신호 수신 처리
    for (int i = 0; i < N; i++) {
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            top--; // 스택에서 높이가 더 낮거나 같은 탑을 제거
        }

        if (top == -1) {
            res[i] = 0;  // 수신할 탑이 없으면 0
        } else {
            res[i] = stack[top] + 1;  // 가장 가까운 높은 탑의 인덱스 (1-based index)
        }

        stack[++top] = i; // 현재 탑의 인덱스를 스택에 추가
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}

/*#include <stdio.h>
#define MAX 300
int main (void)
{
    int N;
    scanf("%d", &N);
    int arr[MAX];
    int stack[MAX];
    int res[MAX];
    int top = -1;
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<N; i++) {
        if (arr[stack[top]] < arr[i]){
            if (top == -1) {
                res[stack[top]] = 0;
                top--; //6을 뺀다
            }
            else {
                while (top != -1 && arr[stack[top]] > arr[i]) {
                    res[i] = stack[top]+1;
                    top--;
                }
            }
            stack[++top] = i;
        }
        else if (arr[stack[top]] > arr[i]){
            res[i] = stack[top]+1;
            stack[++top] = i;
        }
    }
    while (top != -1) {
        res[stack[top]] = 0;
        top--;
    }
    for (int i=0; i<N; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
}
*/
