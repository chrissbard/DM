#include<stdio.h>
#include<stdlib.h>
#define size 11

int main()
{
    int wght =0;
    int graph[size][size] = {
     { 0, 1, 2, 4, 0, 0, 0, 0, 0, 0, 0 },
     { 1, 0, 0, 0, 3, 0, 2, 0, 0, 0, 0 },
     { 2, 0, 0, 0, 7, 6, 0, 0, 0, 0, 0 },
     { 4, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0 },
     { 0, 3, 7, 0, 0, 0, 0, 7, 5, 0, 0 },
     { 0, 0, 6, 2, 0, 0, 0, 7, 0, 3, 0 },
     { 0, 2, 0, 3, 0, 0, 0, 0, 5, 4, 0 },
     { 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 4 },
     { 0, 0, 0, 0, 5, 0, 5, 0, 0, 0, 1 },
     { 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 4 },
     { 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0 }
    };
    int visit[size] = {0};
    int i, j, p=0, q=0;
    int arr[size]={1,2,3,4,5,6,7,8,9,10,11};
    int min;
    int flag=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(flag ==0 && graph[i][j]!=0){
                flag=1;
                p=i;
                q=j;
                min=graph[p][q];
            }
            else if(flag == 1 && graph[i][j]<min && graph[i][j]!=0){
                    p=i;
                    q=j;
                    min = graph[i][j];
            }
        }
    }
    visit[p]=1;
    visit[q]=1;
    int flag1=0;
    int p1,q1,min1,qq=0;
    printf("Ribs included i the minimum span tree \n");
    printf("%d-(%d - weight of the rib)-%d ", arr[p], graph[p][q], arr[q]);
    do{
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(visit[i]==1 && visit[j]==0 && graph[i][j]!=0){
                    if(flag1==0){
                        flag1 = 1;
                        p1 = i;
                        q1 = j;
                        min1=graph[i][j];
                    }
                    else if(flag1 == 1 && graph[i][j]< min1){
                        p1 = i;
                        q1 = j;
                        min1 = graph[i][j];
                    }
                }
            }
        }
        visit[q1]=1;
        flag1=0;
        printf("\n%d-(%d - weight of the rib)-%d", arr[p1], graph[p1][q1], arr[q1]);
        qq++;
        wght = wght+graph[p1][q1];
    }while(qq < size-2);
    printf("\n%d\n", wght);
    return 0;
}