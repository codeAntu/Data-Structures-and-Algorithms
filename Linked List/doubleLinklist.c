#include "stdio.h"
#include "stdlib.h"

typedef struct node {
   int val;
   struct node* next;
   struct node* prev;
} node;

node* createNode(int val) {
   node* newNode = (node*)malloc(sizeof(node));
   if (newNode == NULL) {
      printf("Error creating a new node.\n");
      exit(1);
   }
   newNode->val = val;
   newNode->next = NULL;
   newNode->prev = NULL;
   return newNode;
}

int countNode(node* head) {
   node* temp = head;
   int count = 0;
   while (temp != NULL) {
      count++;
      temp = temp->next;
   }
   return count;
}

void printNode(node* head) {
   node* temp = head;
   while (temp != NULL) {
      printf("%d ", temp->val);
      temp = temp->next;
   }
   printf("\n");
}

void printNodeRev(node* head) {
   node* curr = head;
   while (curr->next != NULL) {
      curr = curr->next;
   }
   while (curr != NULL)
   {
      printf("%d ", curr->val);
      curr = curr->prev;
   }
   printf("\n");
}


void insertBeginning(node** headPtr, int val) {
   node* newNode = createNode(val);
   if (*headPtr == NULL) {
      *headPtr = newNode;
      return;
   }
   newNode->next = *headPtr;
   (*headPtr)->prev = newNode;
   *headPtr = newNode;

}

void insertEnd(node** headPtr, int val) {
   node* newNode = createNode(val);
   if (*headPtr == NULL) {
      *headPtr = newNode;
      return;
   }
   node* curr = *headPtr;
   while (curr->next != NULL) {
      curr = curr->next;
   }
   curr->next = newNode;
   newNode->prev = curr;


}

void insertInd(node** headPtr, int val, int index) {
   node* newNode = createNode(val);
   if (*headPtr == NULL) {
      *headPtr = newNode;
      return;
   }
   if (index == 0) {
      insertBeginning(headPtr, val);
      return;
   }
   index--;
   node* curr = *headPtr;
   while (index--) {
      if (curr == NULL) {
         printf("Index out of bound.\n");
         return;
      }
      curr = curr->next;
   }
   newNode->next = curr->next;
   curr->next->prev = newNode;
   curr->next = newNode;
   newNode->prev = curr;
   return;

}

void deleteBeginning(node** headPtr) {
   if (*headPtr == NULL) {
      printf("List is empty.\n");
      return;
   }
   node* temp = *headPtr;
   *headPtr = (*headPtr)->next;
   (*headPtr)->prev = NULL;
   free(temp);

}

void deleteEnd(node** headPtr) {
   if (*headPtr == NULL) {
      printf("List is empty.\n");
      return;
   }
   node* temp = *headPtr;
   while (temp->next != NULL) {
      temp = temp->next;
   }
   temp->prev->next = NULL;
   free(temp);

}

void deleteInd(node** headPtr, int ind) {
   if (*headPtr == NULL) {
      printf("List is empty.\n");
      return;
   }
   if (ind == 0)
   {
      deleteBeginning(headPtr);
      return;
   }
   if (countNode(*headPtr) - 1 == ind) {
      deleteEnd(headPtr);
   }
   if (ind > countNode(*headPtr) - 1) {
      printf("Index out of bound.\n");
      return;
   }
   ind--;
   node* curr = *headPtr;
   while (ind--) {
      curr = curr->next;
   }
   node* temp = curr->next;
   curr->next = curr->next->next;
   curr->next->prev = curr;
   free(temp);
   return;

}

void deleteVal(node** headPtr, int val) {
   if (*headPtr == NULL) {
      printf("List is empty.\n");
      return;
   }
   if ((*headPtr)->val == val) {
      deleteBeginning(headPtr);
      return;
   }
   node* curr = *headPtr;
   while (curr->next != NULL && curr->next->val != val) {
      curr = curr->next;
   }
   if (curr->next == NULL) {
      printf("Value not found.\n");
      return;
   }
   if (curr->next->next == NULL) {
      deleteEnd(headPtr);
      return;
   }
   node* temp = curr->next;
   curr->next = curr->next->next;
   curr->next->prev = curr;
   free(temp);
   return;
}
int main() {
   // check every function 

   node* head = createNode(5);
   insertBeginning(&head, 4);
   insertBeginning(&head, 3);
   insertBeginning(&head, 1);
   insertEnd(&head, 6);
   insertEnd(&head, 7);
   insertInd(&head, 2, 1);

   insertInd(&head, 8, 10);
   printNode(head);
   printNodeRev(head);

   deleteBeginning(&head);
   deleteEnd(&head);
   deleteInd(&head, 2);
   deleteVal(&head, 5);

   deleteInd(&head, 10);
   printNode(head);
   printNodeRev(head);


   return 0;
}