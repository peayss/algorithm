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
    printf("%d->NULL\n", temp->data);
}
ListNode* search_list(LinkedList* list, element x) {
    ListNode* temp = list->start;
    while (temp->link != NULL) {
        if (temp->data == x) {
            return temp;
        }
        temp = temp->link;
    }
    return NULL;
}
int main(void){
    LinkedList* myList = create_list();
    insert_first(myList, 10);
    print_list(myList);
    insert_first(myList, 20);
    print_list(myList);
    insert_first(myList, 30);
    print_list(myList);
    if (search_list(myList, 30) != NULL) {
        printf("리스트에서 30을 찾았습니다. \n");
    }
    else
        printf("리스트에서 30을 찾지 못했습니다. \n");
}


