/**
 * ADJACENCY MATRIX
 * It is also necessary to implement and adapt functions for directed graphs
*/

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATRIX_ORDER 5

typedef struct{
   short num_vertices;
   short edge;
   bool directed_graph;
   short **adjacency_matrix;   
}Graph;

short** matrix_builder(Graph** graph, short value){
   short** matrix;

   for(short i = 0; i < (*graph)->num_vertices; i++){
      matrix = malloc((*graph)->num_vertices * sizeof(short*));
      for(short j = 0; j < (*graph)->num_vertices; j++){
         matrix[j] = malloc((*graph)->num_vertices * sizeof(short));
      }

      for(short i = 0; i < (*graph)->num_vertices; i++){
         for(short j = 0; j < (*graph)->num_vertices; j++){
            matrix[i][j] = value;
         }
      }
   }
   return matrix;
}

void graph_builder(Graph** graph, short num_vertices, bool directed_graph){
   *graph= malloc(sizeof(Graph*));
   (*graph)->num_vertices = num_vertices;
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

void edge_insertion(Graph **graph, short num_vertices_a, short num_vertices_b){
   (*graph)->adjacency_matrix[num_vertices_a][num_vertices_b]++;
   (*graph)->adjacency_matrix[num_vertices_b][num_vertices_a]++;
   (*graph)->edge++;
}

void edge_removal(Graph **graph, short num_vertices_a, short num_vertices_b){
   if((*graph)->edge > 0 && (*graph)->adjacency_matrix[num_vertices_a][num_vertices_b] > 0){
      (*graph)->adjacency_matrix[num_vertices_a][num_vertices_b]--;
      (*graph)->adjacency_matrix[num_vertices_b][num_vertices_a]--;
      (*graph)->edge--;
   }else{
      fprintf(stdout,"ERROR! There is no %hd-%hd edge\n", num_vertices_a, num_vertices_b);
   }   
}

#endif