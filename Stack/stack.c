#include "stdio.h"
#include "stdbool.h"
#define N 100 

struct stack {
   int elements[N];
   int  top;
};

typedef struct stack stack;

void push(stack* s, int val) {
   if (s->top == N - 1) {
      printf("Stack overflow\n");
      return;
   }
   s->top++;
   s->elements[s->top] = val;
}

void pop(stack* s) {
   if (s->top == -1) {
      printf("Stack underflow\n");
      return;
   }
   s->top--;
   s->elements[s->top];
}

int top(stack* s) {
   return s->elements[s->top];
}

void display(stack* s) {
   for (int i = 0; i <= s->top; i++) {
      printf("%d ", s->elements[i]);
   }
   printf("\n");
}

bool isEmpty(stack* s) {
   return s->top == -1;
}

int size(stack* s) {
   return s->top + 1;
}



int main() {
   stack s;
   s.top = -1;
   push(&s, 1);
   push(&s, 2);
   push(&s, 3);
   display(&s);

   pop(&s);

   display(&s);

   printf("%d\n", top(&s));




   return 0;
}