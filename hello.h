#ifndef HELLO
#define HELLO

struct animal {
    char *name;
    int leg_count;
};

void hello(void);

void array(void);

void rawArrNav(void);

void *my_memcpy(void *dest, void *src, int byte_count);

void test_memcpy(void);

int compar(const void *elem1, const void *elem2);

void allocate_int(int **out, int value);

void voidPointerCast(void);


#endif