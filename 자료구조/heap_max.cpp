//max
#include <iostream>
#define MAX 200
using namespace std;

int heap[MAX] = {0,9,7,6,5,4,3,2,2,1,3};
int heap_size = 10;

void push(int n){
    heap[++heap_size] = n;    
    int child = heap_size;
    int parent = child/2;

    while (child > 1 && heap[child] > heap[parent]){

        int temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        child = parent;
        parent = child/2;
    }
}
void pop(){ //최대값 삭제

    int temp = heap[1]; // root
    heap[1] = heap[heap_size];
    // heap[heap_size] = temp;

    heap_size--;

    int parent = 1;
    int child = parent * 2;

    if (heap[child] < heap[child+1]) 
        child += 1;

    while (heap[child] > heap[parent]){
        
            int temp = heap[child];
            heap[child] = heap[parent];
            heap[parent] = temp;

            parent = child;
            child = parent * 2;

            if (heap[child] < heap[child+1]) 
                child += 1;
        
    }
}
int main(){
    
    push(8);

    for (int i = 1; i <= heap_size; i++)
        cout << heap[i] << " ";
    
    cout << '\n';

    pop();
    for (int i = 1; i <= heap_size; i++)
        cout << heap[i] << " ";
}