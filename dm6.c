#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void permutations (int n, int r)
{
    int a[r];
    for (int i=0;i<r;i++){
             a[i]=1;
    }

    for (int i=0;i<=pow(n,r)-1;i++)
    {
        printf(" (");

        for(int j=0;j<r;j++)
        printf(" %d ",a[j]);

        printf(")");
        if(a[r-1]==n){
            printf("\n");
        }
        a[r-1]++;

        for(int k=r-1;k>=0;k--)
        if(a[k]==n+1)
        {
            if(k>0)a[k-1]++;
            a[k]=1;
        }
    }
}

int fact(int n)
{
    int f=1;
    for (int i=1;i<=n;i++)
    f*=i;
    return f;
}
int comb(int n,int k)
{
    int c;
    c=fact(n)/(fact(n-k)*fact(k));
    return c;
}

void roz_Binom (int k)
{
    printf("\n (");
    for (int i=0;i<=k;i++)
    {
        if(i==0)printf("  %d*x^%d  ",comb(k,i),k-i);
        if(i==k)printf("  %d*y^%d  ",comb(k,i),i);
        if (i!=0 && i!=k)printf("  %d*x^%d*y^%d  ",comb(k,i),k-i,i);
        if (i!=k) printf("-");
    }
    printf(")\n");
}

int main(void)
{
    int n=0, r=0;
    printf("Input the n of (1, 2... n): ");
    scanf("%d",&n);
    printf("Input the r of (1, 2... n): ");
    scanf("%d",&r);
    permutations(n, r);
    printf("The power of (x+y) equal 12 ");
    roz_Binom(12);
}