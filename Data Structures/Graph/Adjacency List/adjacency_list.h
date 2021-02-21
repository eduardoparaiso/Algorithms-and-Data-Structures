#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Lists/Linked List/linked_list.h"

typedef struct{
    short num_vertices; 
    short num_edges;
    linked_list* adjacency_list;
}Graph;

void graph_builder(Graph** G, short num_vertices){
    (*G)->num_vertices = num_vertices;
    (*G)->num_edges = 0;
    (*G)->adjacency_list = malloc(num_vertices * sizeof(Graph));
    for(short i = 0; i < num_vertices; i++){
        start(&(*G)->adjacency_list[i]);
    }       
}

void vertix_incertion(Graph** G, short vertex_a, short vertex_b){
    insert_end(&(*G)->adjacency_list[vertex_a], vertex_b);
}

void vertix_removal(Graph** G, short vertex_a, short to_remove){
    Cell* i;
    short removed_position = 0;
    
    for(i = (*G)->adjacency_list[vertex_a].first->next; i != NULL; i->next, removed_position++){  
        if(i->element == to_remove){
            i = (*G)->adjacency_list[vertex_a].last;
        }
    }

    short tmp = remove_element(&(*G)->adjacency_list[vertex_a], removed_position);
}

#endif