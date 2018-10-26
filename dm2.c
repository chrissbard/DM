#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main ()
    {
    printf("Give me the size of array 1: ");
    int size1 = get_int();
    printf("Give me the size of array 2: ");
    int size2 = get_int();
    int array1[100];
    int array2[100];
    //
    for(int b = 0 ; b < size1 ; b++)
{
printf("Enter element %i , array 1 : \n" , b+1);
array1[b] = get_int();
}
for(int b = 0 ; b < size2 ; b++)
{
printf("Enter element %i , array 2 : " , b+1);
array2[b] = get_int();
}
   
            // Переріз
    int a=0;
    printf("Intersection:{");
    for (int i=0; i < size1; i++){
        for(int j=0; j < size1; j++){
            if (array1[i]==array2[j]){
                printf("%d", array1[i]);
                a++;
            }
        }
    }
    printf("}\n");
  printf("Intersections power: %d\n", a);
    //об'єднання
   printf("Union: {\n");
          int m=0, n=0, l=0;
    for(int i = 0; i<size1; i++){
        printf("%d, ",array1[i]);
    }
    for(int i=0; i<size2; i++)
    {
        for(int j=0; j<size1; j++)
        {
            if(array1[i] == array2[j])
            {
            n = 1;
            }
        }
         m++;
         if(n == 0)
        {
            printf("%d, ",array2[i]);
            l++;
        }
    }
    printf("}");
    printf("Power of union array 1 and array 2: %d\n", l+m);
}
