#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include "../../../../Algorithms-and-Data-Structures/Data Structures/Graph/Adjacency List/adjacency_list.h"
#include "../../../../Algorithms-and-Data-Structures/Data Structures/Queue/queue.h"


/*
static FIFO_queue queue;
static short num[1000];

BSF(Graph* G, FIFO_queue *queue, short vertix){
    short count = 0;
    for(short i = 0; i < G->num_vertices ; ++i){
        num[i] = -1;    
    }

    num[vertix] = count++;
    enqueue(queue, vertix);
    
    while(!is_empty(queue)){
        short vertix_queue = dequeue(queue);
        for(Cell* i = G->adjacency_list[vertix_queue].first->next; i != NULL; i = i->next){
            if(num[i->element] == -1){
                num[i->element] = count++;
                enqueue(queue, i->element);
            }
        }
    }
    //queue free

}

*/
#endif
