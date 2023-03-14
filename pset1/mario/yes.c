#include <stdio.h>
#include <cs50.h>
int main()
{
   int i, space, rows, k = 0;
   do
   {
   printf("Height: ");
   scanf("%d", &rows);
   }
   while (rows < 1 || rows > 8);

   for (i = 1; i <= rows; ++i, k = 0)
   {
      for (space = 0; space <= rows - i; ++space)
      {
         printf("  ");
      }

      while (k != i - 1)

      {
         printf("# ");
         ++k;
      }
      
      printf("\n");
   }

   return 0;
}