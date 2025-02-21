#include<stdio.h>
#include<stdlib.h>
typedef float t;
struct node_t {
    t element;
    struct node_t* next;
    struct node_t* prev;
};
typedef struct node_t Node;

typedef struct{
    Node *head;
    Node *tail;
    int _size;
}List;

void listinit(List* list);
Node *createnode(t element);
void listpushfront(List* list,t element);
void listpushback(List* list,t element);
int listempty(List* list);
t listfront(List* list);
t listback(List* list);
void listpopfront(List* list);
void listpopback(List* list);

int main(){
    float salaries[] = {50000, 40000, 40000, 23000, 2000};
    List list;
    listinit(&list);
    for(int i = 0;i<5;i++){
        listpushback(&list,salaries[i]);
    }
    
    printf("Salaries:\n");
    for(Node* node = list.head; node !=NULL; node = node->next){
        printf("%.2f ",node->element);
    }
    return 0;
}

void listinit(List* list){
    list->head = NULL;
    list->tail = NULL;
    list->_size = 0;
}
Node *createnode(t element){
    Node *node = (Node*)malloc(sizeof(Node));
    node->element = element;
    node->prev = NULL;
    node->next = NULL;
}
void listpushfront(List* list,t element){
    
}
void listpushback(List* list,t element){ 
     Node *node = createnode(element);
     if(list->head == NULL){
         list->head = node;
         list->tail = node;
     }else{
         list->tail->next = node;
         node->prev = list->tail;
         list->tail = node;
     }
}
int listempty(List* list){
    
}
t listfront(List* list){
    
}
t listback(List* list){
    
}
void listpopfront(List* list){
    
}
void listpopback(List* list){
    
}
