#include"stdio.h"

int main() {
   float total = 60000, sum = 0;
   for (int i = 0; i < 24;i++) {
      float per = total * 22.95 * 7 / (100 * 365);
      total += per - 770;
      printf("%f   %f  \n", total, per);
      sum += per;
   }
   printf("%d    %f ", 770 * 24, sum);
   return 0;
}