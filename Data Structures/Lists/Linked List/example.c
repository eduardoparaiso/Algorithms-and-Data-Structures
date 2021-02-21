#include "linked_list.h"

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