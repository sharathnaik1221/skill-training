#include<stdio.h>
#define QUEUE_SIZE 1000
typedef float t;
typedef struct{
    t elements[QUEUE_SIZE];
    int _size;
    int _front;
    int _back;
}queue;
void queueinit(queue* stk);
void queuepush(queue* stk,t elements);
int queueempty(queue* stk);
t queuefront(queue* stk);
t queueback(queue* stk);
void queuepop(queue* stk);
int main() {
    
    float salaries[] = {50000, 40000, 40000, 23000, 2000};
    queue stk;
    queueinit(&stk);
    for(int i=0;i<5;i++){
        queuepush(&stk,salaries[i]);
    }
    printf("Salaries from stack:\n");
    while(!queueempty(&stk)) {
        float sal = queuefront(&stk);
        printf("%.2f ",sal);
        queuepop(&stk);
    }
    return 0;
}
void queueinit(queue* stk){
    stk->_size = 0;
    stk->_front = -1;
     stk->_back = -1;
}
void queuepush(queue* stk,t element){
    stk->_back++;
    stk->elements[stk->_back] = element;
    stk->_size++;
    if(stk->_front == -1){
        stk->_front == 0;
    }
}
int queueempty(queue* stk){
    return(stk->_front == -1);
}
t queuefront(queue* stk){
    return stk->elements[stk->_front];
}
t queueback(queue* stk){
     return stk->elements[stk->_back];
}
void queuepop(queue* stk){
    if(queueempty(stk)){
        printf("queue is empty.\n");
        return;
    }
    if(stk->_front == stk->_back) {
        stk->_front = -1;
        stk->_back = -1;
        stk->_size = 0;
    }
    else{
         stk->_front++;
    }
}
