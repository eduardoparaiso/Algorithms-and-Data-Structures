#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>

typedef struct Cell{
    short element;
    struct Cell* next;
}Cell;

Cell* newCell(short value){
    Cell* new = malloc(sizeof(Cell));
    new->element = value;
    new->next = NULL;
    return new;
}

typedef struct FIFO_queue{
    Cell* first;
    Cell* last;
}FIFO_queue;

void start(FIFO_queue* queue){
    (*queue).first = newCell(0);
    (*queue).last = (*queue).first;
}

void enqueue(FIFO_queue* queue, short value){
   (*queue).last->next = newCell(value);
   (*queue).last = (*queue).last->next;
}

short dequeue(FIFO_queue* queue){
    if((*queue).first == (*queue).last){
        errx(1, "ERROR! Empty queue");
    }

    Cell *tmp = (*queue).first;
    (*queue).first = (*queue).first->next;
    short element_removed = (*queue).first->element;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;

    return element_removed;
}

void show_queue(FIFO_queue* queue){
    fprintf(stdout,"[ ");
    Cell *i;
    for(i = (*queue).first->next; i != NULL; i = i->next){
        fprintf(stdout, "%d ", i->element);
    }
    fprintf(stdout, "]\n");
}

bool search(FIFO_queue *queue, short element){
    bool result = false;
    Cell* i;
    for(i = (*queue).first->next; i != NULL; i = i->next){
        if(i->element == element){
            result = true;
            i = (*queue).last;
        }
    }

    return result;
}

bool is_empty(FIFO_queue *queue){
    if((*queue).first == (*queue).last){
        return true;
    }else{
        return false;
    }
}

#endif