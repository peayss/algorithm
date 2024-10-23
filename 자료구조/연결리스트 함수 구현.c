//p177
#include <stdio.h>
#include <stdlib.h>
#define ERR -9999999

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

typedef struct LinkedList{
    int length;
    ListNode* start;
}LinkedList;

ListNode* create_node(element data);
LinkedList* create_list(void);
void insert(LinkedList* list, int pos, element item);
void insert_last(LinkedList* list, element item);
void insert_first(LinkedList* list, element item);
void print_list(LinkedList* list);
element get_entry(LinkedList* list, int pos);
int get_length(LinkedList* list);
int is_empty(LinkedList* list);
void delete(LinkedList* list, int pos);
void delete_first(LinkedList* list);
void delete_last(LinkedList* list);
//void clear_list(LinkedList* list);

int main (void)
{
    LinkedList* myList = create_list();
    insert_first(myList, 10);
    insert_first(myList, 20);
    insert_first(myList, 30);
    insert(myList, 2, 40);
    insert_last(myList, 50);
    printf("%d\n", get_entry(myList, 3));
    print_list(myList);
    delete(myList, 1);
    print_list(myList);
    delete_first(myList);
    print_list(myList);
    delete_last(myList);
    print_list(myList);
}

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
void insert(LinkedList* list, int pos, element item){
    ListNode* newNode = create_node(item);
    ListNode* temp = list->start;

    for (int i=1; i<pos-1; i++) {
        temp = temp->link;
    }
    // temp 2
    // temp->link 3
    newNode->link = temp->link;
    temp->link = newNode;
    list->length++;
}
void insert_last(LinkedList* list, element item){
    ListNode* newNode = create_node(item);
    ListNode* temp = list->start;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    list->length++;
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
element get_entry(LinkedList* list, int pos){
    if (get_length(list) < pos) {
        return ERR;
    }
    ListNode* temp = list->start;
    for (int i=1; i<pos; i++) {
        temp = temp->link;
    }
    return temp->data;
}
int get_length(LinkedList* list){
    return list->length;
}
int is_empty(LinkedList* list){
    if (list->length == 0)
        return 1;
    return 0;
}
void delete(LinkedList* list, int pos){
    ListNode* a = list->start;
    for (int i=1; i<pos-1; i++) {
        a = a->link;
    }
    ListNode* temp = a->link; // 삭제할 노드를 임시 포인터 temp에 저장
    a->link = temp->link; // 이전 노드의 링크를 삭제할 노드의 다음 노드로 설정
    list->length--;
    free(temp);
}
void delete_first(LinkedList* list){
    if (is_empty(list)) {
        printf("List is empty\n");
        return;
    }
    ListNode* temp = list->start;
    list->start = temp->link;
    list->length--;
    free(temp);
}
void delete_last(LinkedList* list){
    if (is_empty(list)) {
        printf("List is empty\n");
        return;
    }
    ListNode* temp = list->start;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    //
    //
    //
    //
}
void clear_list(LinkedList* list){
    ListNode* temp = list->start;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp = list->
}
