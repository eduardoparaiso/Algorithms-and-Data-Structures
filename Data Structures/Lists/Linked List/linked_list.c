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

typedef struct linked_list{
    Cell* first;
    Cell* last;
}linked_list;

void start(linked_list* list){
    (*list).first = newCell(0);
    (*list).last = (*list).first;
}

void insert_beginning(linked_list* list, short value){
    Cell* tmp = newCell(value);    
    tmp->next = (*list).first->next;

    (*list).first->next = tmp;

    if((*list).first == (*list).last){
        (*list).last = tmp;
    }
    tmp = NULL;
}

void insert_end(linked_list* list, short value){
   (*list).last->next = newCell(value);
   (*list).last = (*list).last->next;
}

short remove_beginning(linked_list* list){
    if((*list).first == (*list).last){
        errx(1, "ERROR! Empty List");
    }

    Cell *tmp = (*list).first;
    (*list).first = (*list).first->next;
    short element_removed = (*list).first->element;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;

    return element_removed;
}

short remove_end(linked_list* list){
    if((*list).first == (*list).last){
        errx(1, "ERROR! Empty List");
    }

    Cell* i;
    for(i = (*list).first; i->next != (*list).last; i = i->next);
    short element_removed = (*list).last->element;

    (*list).last = i;
    free((*list).last->next);
    i = (*list).last->next = NULL;

    return element_removed;
}

short length(linked_list* list){
    short length = 0;
    Cell* i;
    
    for(i = (*list).first; i != (*list).last; i = i->next){
        length++;
    }

    return length;
}

void insert(linked_list* list, short value, short position){
    short len = length(list);

    if(position < 0 || position > len){
        errx(1, "ERROR! The position %d is invalid", position);
    }else if(position == 0){
        insert_beginning(list, value);
    }else if(position == len){
        insert_end(list, value);
    }else{
        short i;
        Cell* tmp = list->first;

        for(i=0; i < position; i++){
            tmp= tmp->next;
        }
        
        Cell* tmp2 = newCell(value);
        tmp2->next = tmp->next;
        tmp->next = tmp2;
        tmp2 = tmp = NULL;
    }
}

short remove_element(linked_list* list, short position){
    short element_removed;
    short len = length(list);

    if(list->first == list->last){
        errx(1,"ERROR! Empty List");
    }else if(position < 0 || position >= len){
        errx(1, "ERROR! The position %d is invalid", position);
    }else if(position == 0){
        element_removed = remove_beginning(list);
    }else if(position == len-1){
        element_removed == remove_end(list);
    }else{
        Cell* tmp = list->first;
        short i;
        for(i = 0; i < position; i++){
            tmp = tmp->next;
        }
        Cell* tmp2 = tmp->next;
        element_removed = tmp2->element;
        tmp->next = tmp2->next;
        tmp2->next = NULL;
        free(tmp2);
        tmp = tmp2 = NULL;
    }

    return element_removed;
}

void show_list(linked_list* list){
    fprintf(stdout,"[ ");
    Cell *i;
    for(i = (*list).first->next; i != NULL; i = i->next){
        fprintf(stdout, "%d ", i->element);
    }
    fprintf(stdout, "]\n");
}

bool search(linked_list *list, short element){
    bool result = false;
    Cell* i;
    for(i = (*list).first->next; i != NULL; i = i->next){
        if(i->element == element){
            result = true;
            i = (*list).last;
        }
    }

    return result;
}

int main(int argc, char const *argv[]){
    short removed_1, removed_2, removed_3;
    linked_list list;
    start(&list);

    insert_end(&list, 8);
    insert_beginning(&list, 5);
    insert_beginning(&list, 4);
    insert(&list, 3, 2);
    insert(&list, 2, 1);
    insert_beginning(&list, 1);
    insert_end(&list, 6);
    insert_end(&list, 7);
    show_list(&list);

    remove_beginning(&list);
    remove_beginning(&list);
    remove_end(&list);
    remove_end(&list);
    remove_element(&list, 1);
    remove_element(&list, 1);
    show_list(&list);

    return 0;
}