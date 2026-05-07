#ifndef HELLO
#define HELLO

struct animal {
    char *name;
    int leg_count;
};

struct foo {
    int a;
    char b;
    int c;
    char d;
};

/*---------- Practice ----------*/

void hello(void);

void array(void);

void *my_memcpy(void *dest, void *src, int byte_count);

void test_memcpy(void);

int compar(const void *elem1, const void *elem2);

void animal_compare(void);

void memAlloc(void);

void casting(void);

void p2p(void);

void pointerArray(void);

void paddingBytes(void);

/*------------------------------*/

/*---------- Exercises ----------*/

void rawArrNav(void);

int allocate_int(int **out, int value);

void voidPointerCast(void);

void pArithmetic(void);

struct list {
    int datum;
    struct list *next;
};

void insert_at_head(struct list **head, struct list *newNode);

struct list *create_node(int datum);

void iterate(struct list *head);

void free_all(struct list *head);

/*-------------------------------*/


#endif