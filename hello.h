#ifndef HELLO
#define HELLO

struct animal {
    char *name;
    int leg_count;
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

/*------------------------------*/

/*---------- Exercises ----------*/

void rawArrNav(void);

int allocate_int(int **out, int value);

void voidPointerCast(void);

/*-------------------------------*/


#endif