#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main (void)
{
    int N, M; //나무의 수, 나무의 길이
    ll low, high, sum, middle, result, max=-1;
    scanf("%d %d", &N, &M);
    ll *arr = (ll*)malloc(N*sizeof(ll)); //나무 높이 배열

    for (int i=0; i<N; i++){
        scanf("%lld", &arr[i]);
        if (arr[i] > max)  max = arr[i];         
    }

    low = 0, high = max;
    
    while (low <= high) { //low와 high가 같을때까지만 반복
        sum = 0;
		middle = (low + high) / 2;
		
        for (int i = 0; i < N; i++)
        {
            if (arr[i] - middle > 0)
                sum += arr[i]-middle;
        }
        if (sum < M)
            high = middle-1;
        else if (sum >= M){
            result = middle;
            low = middle+1;
        }
	}
    printf("%lld\n", result);
    free(arr);
}