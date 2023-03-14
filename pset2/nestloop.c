#include <stdio.h>
#include <string.h>

int n;// variable declaration
int main()
{

       printf("Enter the value of n :");
       scanf("%d", &n);
       // Displaying the n tables.
       for(int i=1;i<=n;i++)  // outer loop
       {
              for(int j=1;j<=10;j++)  // inner loop
              {
                     printf("%d\t",(i*j)); // printing the value.  d and \t
              }
       printf("\n");
       }
}

