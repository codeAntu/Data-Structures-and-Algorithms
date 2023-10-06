#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct node {
   int data;
   struct node* next;
};

typedef struct node node;

void createNode(node** headPtr, int val) {
   node* newNode = (node*)malloc(sizeof(node));
   if (newNode == NULL) {
      printf("Memory allocation failed\n");
      return;
   }
   newNode->data = val;
   newNode->next = NULL;
   *headPtr = newNode;
}

void push(node** top, int val) {
   node* newNode = (node*)malloc(sizeof(node));
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
   return top->data;
}

void display(node* top) {
   node* temp = top;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

bool isEmpty(node* top) {
   return top == NULL;
}

int size(node* top) {
   int count = 0;
   node* temp = top;
   while (temp != NULL) {
      count++;
      temp = temp->next;
   }
   return count;
}

int main() {
   node* top = NULL;
   pop(&top); // Stack underflow
   push(&top, 1);
   push(&top, 2);
   push(&top, 3);
   display(top);

   pop(&top);

   display(top);

   printf("%d\n", peek(top));


   return 0;
}

