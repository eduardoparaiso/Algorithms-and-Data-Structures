#include "queue.h"

int main(int argc, char const *argv[]){
    short removed_1, removed_2, removed_3;
    FIFO_queue queue;
    start(&queue);

    enqueue(&queue, 8);
    enqueue(&queue, 5);
    enqueue(&queue, 4);  
    enqueue(&queue, 1);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    show_queue(&queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    show_queue(&queue);

    return 0;
}