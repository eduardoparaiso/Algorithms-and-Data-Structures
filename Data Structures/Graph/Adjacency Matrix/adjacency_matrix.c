/**
 * ADJACENCY MATRIX
 * It is also necessary to implement and adapt functions for directed graphs
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATRIX_ORDER 5

typedef struct{
   short vertex;
   short edge;
   bool directed_graph;
   short **adjacency_matrix;   
}Graph;

short** matrix_builder(Graph** graph, short value){
   short** matrix;

   for(short i = 0; i < (*graph)->vertex; i++){
      matrix = malloc((*graph)->vertex * sizeof(short*));
      for(short j = 0; j < (*graph)->vertex; j++){
         matrix[j] = malloc((*graph)->vertex * sizeof(short));
      }

      for(short i = 0; i < (*graph)->vertex; i++){
         for(short j = 0; j < (*graph)->vertex; j++){
            matrix[i][j] = value;
         }
      }
   }
   return matrix;
}

void graph_builder(Graph** graph, short vertex, bool directed_graph){
   *graph= malloc(sizeof(Graph*));
   (*graph)->vertex = vertex;
   (*graph)->edge = 0;
   (*graph)->directed_graph = directed_graph;
   (*graph)->adjacency_matrix = matrix_builder(&(*graph), 0);    
}

void matrix_display(short **matrix, short rows, short columns){
   for(short i = 0; i < rows; i++){
      for(short j = 0; j < columns; j++){
         printf("%hd ", matrix[i][j]);
      }
      printf("\n");
   }
}

void edge_insertion(Graph **graph, short vertex_a, short vertex_b){
   (*graph)->adjacency_matrix[vertex_a][vertex_b]++;
   (*graph)->adjacency_matrix[vertex_b][vertex_a]++;
   (*graph)->edge++;
}

void edge_removal(Graph **graph, short vertex_a, short vertex_b){
   if((*graph)->edge > 0 && (*graph)->adjacency_matrix[vertex_a][vertex_b] > 0){
      (*graph)->adjacency_matrix[vertex_a][vertex_b]--;
      (*graph)->adjacency_matrix[vertex_b][vertex_a]--;
      (*graph)->edge--;
   }else{
      fprintf(stdout,"ERROR! There is no %hd-%hd edge\n", vertex_a, vertex_b);
   }   
}

int main(int argc, char const *argv[]){
   Graph* G;
   graph_builder(&G, MATRIX_ORDER, false);
   edge_insertion(&G, 3, 2);
   edge_insertion(&G, 0, 1); 
   edge_insertion(&G, 3, 4);
   edge_insertion(&G, 2 , 2); 
   edge_insertion(&G, 4, 1); 
   matrix_display(G->adjacency_matrix, G->vertex, G->vertex);
   printf("Number of Edges: %hd\n", G->edge);
   printf("Number of vertix: %d\n", G->vertex);
   return 0;
}
