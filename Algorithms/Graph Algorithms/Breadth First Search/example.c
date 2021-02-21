#include "breadth_first_search.h"

int main(int argc, char const *argv[]){
   // start(&queue);
    Graph* G;
    graph_builder(&G, 5);


    vertix_incertion(&G, 1, 1);
    vertix_incertion(&G, 1, 2);
    vertix_incertion(&G, 1, 3);
    vertix_incertion(&G, 3, 4);
    vertix_incertion(&G, 3, 5);

    for(short i = 0; i < G->num_vertices; i++){
        fprintf(stdout, "[%hd] ", i);
        show_list(&G->adjacency_list[i]);
    }

    



    return 0;
}
