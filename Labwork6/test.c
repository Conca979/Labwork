#include <stdio.h>
#include <stdlib.h>

typedef struct Edge { int to; int w; struct Edge* next; } Edge;

#define N 8
Edge* adj[N];

void add_edge(int u,int v,int w){
    Edge* e = malloc(sizeof(Edge));
    e->to = v; e->w = w; e->next = adj[u]; adj[u]=e;
}

int main(){
    add_edge(0,1,4); add_edge(0,2,3);
    add_edge(1,2,1); add_edge(1,3,2); add_edge(1,6,7);
    add_edge(2,3,4); add_edge(2,4,2);
    add_edge(3,5,1);
    add_edge(4,5,3); add_edge(4,7,5);
    add_edge(5,6,2);
    add_edge(6,7,1);

    // print adjacency list
    for(int i=0;i<N;i++){
        printf("%d:", i);
        for(Edge* e = adj[i]; e; e = e->next) printf(" (%d,%d)", e->to, e->w);
        printf("\n");
    }
    return 0;
}
