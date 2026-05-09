#ifndef HELLO
#define HELLO

#include <stddef.h>
#include <stdint.h>

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

enum resource {
    SHEEP,
    WHEAT,
    WOOD,
    BRICK,
    ORE
};

void enumTypes(void);

int add(int a, int b);
int mult(int a, int b);
void print_math(int (*op)(int, int), int x, int y);

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

void test_list(void);

void set_bit(uint64_t *bm, int n);

void clear_bit(uint64_t *bm, int n);

int test_bit(uint64_t bm, int n);

int find_first_free(uint64_t bm);

void test_bitmap(void);

enum flags {
    BLOCK_ALLOCATED     = 1,
    BLOCK_PINNED        = 2,
    BLOCK_DIRTY         = 4,
    BLOCK_COMPRESSED    = 8
};

void set_flag(uint32_t *flags, uint32_t flag);
void clear_flag(uint32_t *flags, uint32_t flag);
void toggle_flag(uint32_t *flags, uint32_t flag);
int test_flag(uint32_t flags, uint32_t flag);

struct callback {
    int a;
    int b;
};

void int_callback(void *i);
void struct_callback(void *ptr);
void foreach(void * arr, size_t elts, size_t elt_size, void (*callback)(void *));
void test_foreach(void);

/*-------------------------------*/


#endif