#include "adjacency_matrix.h"

int main(int argc, char const *argv[]){
   Graph* G;
   graph_builder(&G, MATRIX_ORDER, false);
   edge_insertion(&G, 3, 2);
   edge_insertion(&G, 0, 1); 
   edge_insertion(&G, 3, 4);
   edge_insertion(&G, 2 , 2); 
   edge_insertion(&G, 4, 1); 
   matrix_display(G->adjacency_matrix, G->num_vertices, G->num_vertices);
   printf("Number of Edges: %hd\n", G->edge);
   printf("Number of vertix: %d\n", G->num_vertices);
   return 0;
}