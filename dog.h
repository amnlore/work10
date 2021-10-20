struct dog;
void print_dog(struct dog *d);
void print_list(struct dog *d);
struct dog *make_dog(int age, char name[100]);
struct dog *free_list(struct dog *d);
struct dog *insert_front(int age, char name[100], struct dog *next);
struct dog *remove_node(struct dog *front, int age);
