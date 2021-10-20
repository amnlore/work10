#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dog {int a; char n[100]; struct dog *next;};

void print_dog(struct dog *d) {
    printf("This dog is called %s and they are %d years old\n", d->n, d->a);
}

void print_list(struct dog *d) {
    while (d) {
        print_dog(d);
        d = d->next;
    }
}

struct dog *make_dog(int age, char name[100]) {
    struct dog *d = malloc(sizeof(struct dog));
    strncpy(d->n, name, sizeof(d->n));
    d->a = age;

    return d;
}

struct dog *free_list(struct dog *d) {

  struct dog *temp;

  while (d) {
    temp = d;
    d = d->next;
    print_dog(temp);
    free(temp);
  }

  return d;

}

struct dog *insert_front(int age, char name[100], struct dog *next) {
    struct dog *front = make_dog(age, name);
    front->next = next;
    return front;
}

struct dog *remove_node(struct dog *front, int age) {
    if (front == 0) {
        return NULL;
    }
    if (front->a == age) {
        struct dog *next1 = front->next;
        free(front);
        return next1;
    }

    struct dog *temp = front;
    struct dog *dug = front;

    while (front) {
        if (front->a == age) {
            temp->next = front->next;
            free(front);
        }
        temp = front;
        front = front->next;
    }

    return dug;
}
