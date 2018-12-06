#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

short ver_am = 0;
struct vert *list[20];
short veco = 0;

struct vert{ short id;
    short degr;
    short used;
    short way;
    struct vert *prev;
    struct edge *edge[10];
};

struct edge{
    short v1id;
    short v2id;
    short wght;
    short used;
    struct vert *v1pt;
    struct vert *v2pt;
};


// ---Announcement of functions--- //
struct vert *create();                                          // Function for creating vertices struct
void connection(struct vert *a, struct vert *b, short weight);  // Function for creating edges
void start(struct vert *vert);                                  // Function to choose start verticle
void dijkstra(struct vert *vert);
void way(struct vert *vert);                                    // Function that shows minimum way


// ---Main function--- //
int main(){
    // ---Create verticles--- //
    struct vert *v0 = create();     struct vert *v1 = create();     struct vert *v2 = create();
    struct vert *v3 = create();     struct vert *v4 = create();     struct vert *v5 = create();
    struct vert *v6 = create();     struct vert *v7 = create();     struct vert *v8 = create();
    struct vert *v9 = create();     struct vert *v10 = create();    struct vert *v11 = create();
    struct vert *v12 = create();    struct vert *v13 = create();    struct vert *v14 = create();
    struct vert *v15 = create();    struct vert *v16 = create();    struct vert *v17 = create();
    struct vert *v18 = create();    struct vert *v19 = create();    struct vert *v20 = create();
    struct vert *v21 = create();    struct vert *v22 = create();    struct vert *v23 = create();
    struct vert *v24 = create();    struct vert *v25 = create();    struct vert *v26 = create();
    struct vert *v27 = create();    struct vert *v28 = create();    struct vert *v29 = create();

    // ---Weight of edges---//
    connection(v0,v1,6);   connection(v0,v6,3);   connection(v1,v2,7);   connection(v1,v7,2);
    connection(v2,v3,1);   connection(v2,v8,3);   connection(v3,v4,4);   connection(v3,v9,1);
    connection(v4,v5,1);   connection(v4,v10,7);  connection(v5,v11,5);  connection(v6,v7,8);
    connection(v6,v12,7);  connection(v7,v8,1);   connection(v7,v13,3);  connection(v8,v9,8);
    connection(v8,v14,4);  connection(v9,v10,2);  connection(v9,v15,5);  connection(v10,v11,1);
    connection(v10,v16,4); connection(v11,v17,7); connection(v12,v13,1); connection(v12,v18,3);
    connection(v13,v14,3); connection(v13,v19,2); connection(v14,v15,3); connection(v14,v20,1);
    connection(v15,v16,4); connection(v15,v21,3); connection(v16,v17,2);
    connection(v16,v22,4); connection(v17,v23,5); connection(v18,v19,7); connection(v18,v24,1);
    connection(v19,v20,1); connection(v19,v25,7); connection(v20,v21,5); connection(v20,v26,3);
    connection(v21,v22,3); connection(v21,v27,8); connection(v22,v28,1); connection(v22,v23,8);
    connection(v23,v29,7); connection(v24,v25,4); connection(v25,v26,2); connection(v26,v27,3);
    connection(v27,v28,7); connection(v28,v29,6);

    start(v0);
    printf("\n"); way(v29);
    printf("The shortest way is \x1b[32m%i\x1b[0m\n\n", v29->way);
}


struct vert *create(){
    struct vert *vert = (struct vert*)
    malloc(sizeof(struct vert));
    vert->id = ver_am; vert->degr = 0;
    vert->used = 0;
    vert->way = SHRT_MAX;
    ver_am++;
    return vert;
}

//function for creating edges
void connection(struct vert *a, struct vert *b, short weight){
    struct edge *edge = (struct edge*) malloc(sizeof(struct edge));
    edge->v1id = a->id; edge->v2id = b->id; edge->wght = weight;
    edge->v1pt = a; edge->v2pt = b;
    a->edge[a->degr] = edge; a->degr++;
    b->edge[b->degr] = edge; b->degr++;
}

void start(struct vert *vert){
    vert->way = 0; vert->prev = NULL; dijkstra(vert) ;
}

void dijkstra(struct vert *vert){
    list[veco] = vert; vert->used = 1; veco++;
    for (short j = 0; j < veco; j++){
        for (short i = 0; i < list[j]->degr; i++){
            if (list[j]->way + list[j]->edge[i]->wght < list[j]->edge[i]->v2pt->way){
                list[j]->edge[i]->v2pt->prev = list[j];
                list[j]->edge[i]->v2pt->way = list[j]->way + list[j]->edge[i]->wght;
            }
            if (list[j]->way + list[j]->edge[i]->wght < list[j]->edge[i]->v1pt->way){
                list[j]->edge[i]->v1pt->prev = list[j];
                list[j]->edge[i]->v1pt->way = list[j]->way + list[j]->edge[i]->wght;
            }
        }
        for (short i = 0; i < list[j]->degr; i++){
            if (list[j]->edge[i]->v2pt->used == 0) dijkstra(list[j]->edge[i]->v2pt); if (list[j]->edge[i]->v1pt->used == 0) dijkstra(list[j]->edge[i]->v1pt);
        }
    }
}

void way(struct vert *vert){
    if (vert->prev != NULL){
        printf("v%d <-- ", vert->id);
        way(vert->prev);
    }
    else if (vert->prev == NULL)
        printf("v%d\n", vert->id);
}