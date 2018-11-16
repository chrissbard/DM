#include <stdio.h>
int main()
{
 printf("Give me the size of array: ");
    int size;
    scanf("%d",&size);
    int array[100];
    int i, j, k;
 while(size<0)
 {
 printf("Enter a positive value");
 scanf("%d",&size);
 }

 for(i=0; i<size; i++)
 {
      printf("Enter the column element");
 scanf("%d",&array[i]);
 }
    
 for(j=0; j<size; j++)
 {
      printf("Enter the line element");
 scanf("%d",&array[j]);
 }
 

 int matrix[size][size];
    int reflectivity = 0, antireflectivity = 0;
 for(i=0; i<size;i++)
 {
 for(j=0; j<size; j++)
 {
 matrix[i][j]=array[i]+array[j]+1>3;
 printf("%d ", matrix[i][j]);
       reflectivity=1;
 }
     printf("\n");
 }
 
 if((antireflectivity==0) && (reflectivity==1))
 {
 printf("Your matrix is no reflectible\n");
 }
 else if(reflectivity==1)
 {
 printf("Your matrix is reflectible\n");
 }
 else if(antireflectivity==1)
 {
 printf("Your matrix is anireflectible\n");
 }
 reflectivity=1;
 antireflectivity=1;
 
 int symmetry=1;
 int assymmetry=1;
 for(i=0;i<size;i++)
 {
 for(j=0;j<size;j++)
 {
 if(matrix[i][j]==matrix[j][i])
 {
 assymmetry=0;
 }
 else if(matrix[i][j] != matrix[j][i])
 {
 symmetry=0;
 }
 }
 }
 if(assymmetry==1)
 {
 printf("Your matrix is assymmetry\n");
 }
 else if(symmetry==1)
 {
 printf("Your matrix is symmetry\n");
 }
 else if((assymmetry==0) && (symmetry==0))
 {
 printf("Your matrix is not symmetric");
 }
 printf("\n");
    int transitive = 1, antitransitive = 1;
 for( j=0; j<size; j++)
 {
 for(k=0;k<size;k++)
 {
 if(matrix[i][j]==1 && matrix[j][k]==1 && matrix[i][k]==1)
 {
 antitransitive = 0;
 }
 else if (matrix[i][j]==1 && matrix[j][k]==1 && matrix[i][k]==0)
 {
 transitive = 0;
 }
 }
 }
 

 if ( transitive == 1)
 {
 printf("Your matrix is transitive\n");
 }
 else if ( antitransitive == 1)
 {
 printf("Your matrix is atransitive\n");
 }
 else if ((transitive==0) && (antitransitive==0))
 {
 printf("Your matrix is antitranstive");
 }
}
