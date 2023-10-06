#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct node {
   int data;
   struct node* next;
};


typedef struct node node;


void push(node** top, int val) {
   node* newNode = (node*)malloc(sizeof(node));
   if (newNode == NULL) {
      printf("Memory allocation failed\n");
      return;
   }
   newNode->data = val;
   newNode->next = *top;
   *top = newNode;
}

void pop(node** top) {
   if (*top == NULL) {
      printf("Stack underflow\n");
      return;
   }
   node* temp = *top;
   *top = (*top)->next;
   free(temp);
}

int peek(node* top) {
   if (top == NULL) {
      return 0;
   }
   return top->data;
}

void display(node* top) {
   node* temp = top;
   while (temp != NULL) {
      printf("%c ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

bool isEmpty(node* top) {
   return top == NULL;
}

bool chechParantheses(char* exp) {
   node* stack = NULL;
   for (int i = 0; exp[i] != '\0'; i++) {
      if (exp[i] == '(')
         push(&stack, exp[i]);
      else if (!isEmpty(stack) && exp[i] == ')' && peek(stack) == '(')
         pop(&stack);
      else if (exp[i] == ')')
         push(&stack, exp[i]);
      display(stack);

   }
   return isEmpty(stack);
}


int main() {

   char exp[] = "((a+b))*(c-d)())";
   if (chechParantheses(exp))
      printf("Balanced\n");
   else
      printf("Not balanced\n");



   return 0;
}
