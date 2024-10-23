#include <stdio.h>
#include <stdlib.h>
#define ERR -9999999

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *llink;
    struct ListNode *rlink;
}ListNode;

typedef struct DoubleLinkedList{
    int length;
    ListNode* start;
    ListNode* end;
}DoubleLinkedList;


ListNode* create_node(element data);
DoubleLinkedList* create_list(void);
void dinsert(DoubleLinkedList* dll, int pos, element item);
void print_list (DoubleLinkedList* list);
element get_entry(ListNode* head, int pos);
int get_length(ListNode* head);
int is_empty(DoubleLinkedList* list);
void ddelete(DoubleLinkedList* dll, int pos);

int main (void)
{
    DoubleLinkedList* dll = create_list();
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    
    // 노드 삽입
    dinsert(dll, 1, 1);
    dinsert(dll, 2, 2);
    dinsert(dll, 3, 3);
    dinsert(dll, 4, 4);

    printf("리스트 초기 상태: \n");
    print_list(dll);
    
    ddelete(dll, 2);
    print_list(dll);
    free(node);
}

ListNode* create_node(element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->llink = NULL;
    node->rlink = NULL;
    return node;
}
DoubleLinkedList* create_list(void){
    // init
    DoubleLinkedList* dll = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    dll->length = 0;
    dll->start = (ListNode*)malloc(sizeof(ListNode));
    dll->end = (ListNode*)malloc(sizeof(ListNode));
    dll->start->rlink = dll->end;
    dll->end->llink = dll->start;
    return dll;
}
void dinsert(DoubleLinkedList* dll, int pos, element item){
    ListNode* newNode = create_node(item);
    ListNode* temp = dll->start;
    if (pos < 1 || pos > dll->length + 1) {
        printf("Invalid position\n");
        return;
    }

    for (int i=1; i<pos; i++) {
        temp = temp->rlink;
    }
    newNode->rlink = temp->rlink;
    newNode->llink = temp;
    temp->rlink->llink = newNode;
    temp->rlink = newNode;
    dll->length++;
}
void print_list (DoubleLinkedList* list){
    if (is_empty(list)) {
        printf("List is empty\n");
        return;
    }
    ListNode* temp = list->start->rlink;
    while (temp->rlink != NULL) {
        printf("%d->", temp->data);
        temp = temp->rlink;
    }
    printf("NULL\n");
}
element get_entry(ListNode* head, int pos){
    if (get_length(head) < pos) {
        return ERR;
    }
    ListNode* temp = head->rlink;
    for (int i=1; i<pos; i++) {
        temp = temp->rlink;
    }
    return temp->data;
}
int get_length(ListNode* head){
    int count = 0;
    ListNode* p = head->rlink;
    while (p != head) {
        count++;
        p = p->rlink;
    }
    return count;
}
void ddelete(DoubleLinkedList* dll, int pos){
    ListNode* a = dll->start;
    for (int i=1; i<pos; i++) {
        a = a->rlink;
    }
    ListNode* temp = a->rlink; // 삭제할 노드를 임시 포인터 temp에 저장
    a->rlink = temp->rlink; // 이전 노드의 링크를 삭제할 노드의 다음 노드로 설정
    temp->rlink->llink= a;
    free(temp);
    dll->length--;
}
int is_empty(DoubleLinkedList* list){
    if (list->length == 0)
        return 1;
    return 0;
}

