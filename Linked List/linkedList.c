#include "stdio.h"
#include "stdlib.h"

struct node {
   int val;
   struct node* next;
};

struct node* createNode(int val) {
   struct node* newNode = (struct node*)malloc(sizeof(struct node));
   if (newNode == NULL) {
      printf("Memory not allocated");
      return NULL;
   }
   newNode->val = val;
   newNode->next = NULL;
   return newNode;
}

int countList(struct node* head) {
   int count = 0;
   while (head != NULL) {
      count++;
      head = head->next;
   }
   return count;
}

struct Nosd* print(struct node* head) {
   struct node* temp = head;
   while (temp != NULL) {
      printf("%d ", temp->val);
      temp = temp->next;
   }
   printf("\n");
}

void insertBeginnig(struct node** head, int val) {
   struct node* newNode = createNode(val);
   newNode->next = *head;
   *head = newNode;
}

void insertEnd(struct node** head, int val) {
   struct node* newNode = createNode(val);
   if (*head == NULL) {
      *head = newNode;
   } else {
      struct node* curr = *head;
      while (curr->next != NULL) {
         curr = curr->next;
      }
      curr->next = newNode;
   }
}

void insertAtIndex(struct node** head, int val, int index) {
   int count = countList(*head);
   if (index > count) {
      printf("Index out of range");
      return;
   }
   if (index == 0) {
      insertBeginnig(head, val);
   } else if (index == count) {
      insertEnd(head, val);
   } else {
      struct node* newNode = createNode(val);
      struct node* curr = *head;
      for (int i = 0; i < index - 1; i++) {
         curr = curr->next;
      }
      newNode->next = curr->next;
      curr->next = newNode;
   }
}

void deletFirst(struct node** head) {
   if (*head != NULL) {
      struct node* temp = *head;
      *head = (*head)->next;
      free(temp);
      printf("Deleted\n");
   }
}

void deletLast(struct node** head) {
   if (*head != NULL) {
      struct node* curr = *head;
      while (curr->next->next != NULL) {
         curr = curr->next;
      }
      struct node* temp = curr->next;
      curr->next = NULL;
      free(temp);
      printf("Deleted\n");
   }
}

void deletINdex(struct  node** head, int index) {
   if (*head != NULL) {
      struct node* curr = *head;
      if (index == 0) {
         deletFirst(head);
         return;
      }
      if (index == countList(*head) - 1) {
         deletLast(head);
         return;
      }
      for (int i = 0; i < index - 1; i++) {
         if (curr->next == NULL) {
            printf("Index out of range \n");
            return;
         }
         curr = curr->next;
      }
      struct node* temp = curr->next;
      int x = curr->val;
      curr->next = curr->next->next;
      free(temp);
   }
}

void revrces(struct node** head) {
   struct node* curr = *head, * next, * pre;
   pre = NULL;
   while (curr != NULL) {
      next = curr->next;
      curr->next = pre;
      pre = curr;
      curr = next;
   }
   *head = pre;
}

int main() {

   struct node* head = createNode(1);
   insertBeginnig(&head, 2);
   insertEnd(&head, 4);
   insertEnd(&head, 5);
   insertAtIndex(&head, 3, 2);
   insertBeginnig(&head, 0);
   insertEnd(&head, 6);


   print(head);

   deletFirst(&head);
   print(head);
   deletLast(&head);
   print(head);
   deletINdex(&head, 0);
   print(head);

   revrces(&head);
   print(head);


   return 0;
}