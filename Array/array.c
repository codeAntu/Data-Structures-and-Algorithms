#include "stdio.h"
#include "stdio.h"



void printArr(int* arr, int len) {
   int i;
   for (int i = 0; i < len; i++) {
      printf("%d ", arr[i]);
   }
}

void insertAtEnd(int* arr, int len, int element) {
   if (len >= sizeof(arr)) {
      printf("Array is full");
      return;
   }
   arr[len] = element;
   len++;
}

int main() {

   int arr[10] = { 1,2,3,4,5 };
   int len = 5;

   insertAtEnd(arr, len, 6);
   printArr(arr, 6);

   return 0;
}