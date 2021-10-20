#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dog.h"

int main() {
    srand(time(NULL));

    int age_jacob = rand() % 25 + 1;
    int age_john = rand() % 25 + 1;

    printf("insert_front\n");
    struct dog *list = NULL;
    list = insert_front(age_jacob, "Jacob", list);
    list = insert_front(age_john, "John", list);
    print_list(list);

    printf("free_list\n");
    list = free_list(list);
    print_list(list);

    list = insert_front(age_jacob, "Jacob", list);
    list = insert_front(age_john, "John", list);
    print_list(list);

    printf("remove_node\n");
    list = remove_node(list, age_john);
    print_list(list);

    list = remove_node(list, age_jacob);
    print_list(list);

    list = remove_node(list, 27);
    print_list(list);
}
