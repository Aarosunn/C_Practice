#ifndef HELLO
#define HELLO

#include <stddef.h>

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

void *my_memcpy(void *dest, void *src, size_t byte_count);

void test_memcpy(void);

int compar(const void *elem1, const void *elem2);

void animal_compare(void);

void memAlloc(void);

void casting(void);

void p2p(void);

void pointerArray(void);

void paddingBytes(void);

struct passenger {
    char *name;
    int covid_vaccinated;
};

#define MAX_PASSENGERS 8

typedef struct spaceship {
    char *manufacturer;
    struct passenger passenger[MAX_PASSENGERS];
} spaceship;

void nestedStructs(void);

struct len_string {
    int length;
    char data[];
};

struct len_string *len_string_from_c_string(char *s);

void flex_arr_member(void);

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
struct block {
    int size;
    char data[];
};

/*-------------------------------*/


#endif