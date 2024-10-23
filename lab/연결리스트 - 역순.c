#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;
typedef struct LinkedList{
    int length;
    ListNode* start;
}LinkedList;
ListNode* create_node(element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = NULL;
    return node;
}
LinkedList* create_list(void){
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->length = 0;
    ll->start = NULL;
    return ll;
}
int is_empty(LinkedList* list){
    if (list->length == 0)
        return 1;
    return 0;
}
void insert_first(LinkedList* list, element item){
    ListNode* newNode = create_node(item);
    if (!is_empty(list)) {
        newNode->link = list->start;
    }
    list->start = newNode;
    list->length++;
}
void print_list (LinkedList* list){
    if (is_empty(list)) {
        printf("List is empty");
        return;
    }
    ListNode* temp = list->start;
    while (temp->link != NULL) {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("%d\n", temp->data);
}
void make_reversed(LinkedList* list){
    ListNode *p = list->start; //p는 순회
    ListNode *q = NULL, *r; //q는 현재, r은 이전노드
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    list->start = q;
}
int main(void)
{
    LinkedList* myList = create_list();
    //insert(myList, 0, 10);
    insert_first(myList, 40);
    insert_first(myList, 30);
    insert_first(myList, 20);
    insert_first(myList, 10);
    print_list(myList);
    make_reversed(myList);
    print_list(myList);
}

