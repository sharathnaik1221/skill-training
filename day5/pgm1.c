#include<stdio.h>
#define stack_size 1000
typedef float T;
typedef struct{
    T elements[stack_size];
    int size;
    int top;
}stack;
void stackInit(stack* stk);
void stackpush(stack* stk, T element);
int stackempty(stack* stk);
T stacktop(stack* stk);
void stackpop(stack* stk);

int main(){
    stack stk;
    stackInit(&stk);
    float salaries[]={50000,40000,48000,23000,2000};
    for(int i=0;i<5;i++){
        stackpush(&stk,salaries[i]);
    }
    printf("Salaries from stack:\n");
    while(!stackempty(&stk)){
        float sal=stacktop(&stk);
    printf("%.2f",sal);
    stackpop(&stk);
    }
    return 0;
}
void stackInit(stack* stk){
    stk->size=0;
    stk->top=-1;
}
void stackpush(stack* stk, T element){
    stk->elements[stk->size]=element;
    stk->size++;
    stk->top++;
}
int stackempty(stack* stk){
    return (stk->top==-1);
}
T stacktop(stack* stk){
    return stk->elements[stk->top];
}
void stackpop(stack* stk){
    if(stackempty(stk)){
        printf("Stack is empty.\n");
        return;
    }
    stk->size--;
    stk->top--;
}
