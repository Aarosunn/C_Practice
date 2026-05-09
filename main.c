
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

#include "hello.h"


int main() {
    //hello();
    //array();
    //test_memcpy();
    //animal_compare();
    //memAlloc();
    //casting();
    //p2p();

    //rawArrNav();

    // int *ptr;
    // allocate_int(&ptr, 7);

    // printf("%d\n", *ptr);

    // free(ptr);

    //voidPointerCast();

    //pointerArray();

    //pArithmetic();

    //paddingBytes();

    //nestedStructs();

    //flex_arr_member();

    //test_bitmap();

    //enumTypes();

    // print_math(add, 7, 10);
    // print_math(mult, 7, 10);

    test_foreach();
}

/*---------- Practice ----------*/

void hello() 
{
    int i = 2;
    float f = 3.14f;
    char* s = "Hello World!";

    printf("%s\n", s);
    printf("%s i = %d and f = %.2f!\n", s, i, f);

    bool x = true;

    if(x)
        printf("x is true\n");


    int num = 32;
    printf("The number %d is %s\n", num, num % 2 == 0 ? "even" : "odd");
    printf("The size of num is %zu\n", sizeof(num));

    int *ptr = &num;
    printf("The size of a pointer is %zu\n", sizeof(ptr));

    printf("The address of i is %p\n", (void *)&i);
    printf("num is %d\n", *ptr);
}

void array() 
{
    int nums[4];

    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;

    for(int i = 0; i < 4; ++i) {
        printf("%d\n", nums[i]);
    }

    printf("size of x is %zu total bytes\n", sizeof nums);
    printf("%zu bytes per int\n", sizeof(int));

    printf("array size is %zu\n", sizeof(nums) / sizeof(int));

    printf("%zu\n", sizeof(double [8]));

    int a[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };

    for(int row = 0; row < 2; ++row) {
        for(int col = 0; col < 5; ++col) {
            printf("(%d,%d) = %d\n", row, col, a[row][col]);
        }
    }

    int *p = nums;
    printf("%d\n", *p);

    int test[5] = {1, 2, 3, 4, 5};

    printf("%d\n", 2[test]);
}

void *my_memcpy(void *dest, void *src, size_t byte_count) 
{
    char *s = src, *d = dest;

    while(byte_count--) {
        *d++ = *s++;
    }

    return dest;
}

void test_memcpy() 
{
    char* s = "Goats!";
    char t[100];

    my_memcpy(t, s, 7);

    printf("%s\n", t);

    int a[] = {11, 22, 33};
    int b[3];

    my_memcpy(b, a, sizeof(a));

    printf("%d\n", b[1]);
}

int compar(const void *elem1, const void *elem2) 
{

    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;

    if(animal1->leg_count > animal2->leg_count)
        return 1;

    if(animal1->leg_count < animal2->leg_count)
        return -1;

    return 0;
}

void animal_compare() 
{

    struct animal a[4] = {
        {.name="Dog", .leg_count=4},
        {.name="Monkey", .leg_count=2},
        {.name="Antelope", .leg_count=4},
        {.name="Snake", .leg_count=0}
    };

    qsort(a, 4, sizeof(struct animal), compar);

    printf("size of animal: %zu\n", sizeof(struct animal));

    for(int i = 0; i < 4; ++i) {
        printf("%d: %s\n", a[i].leg_count, a[i].name);
    }
}

void memAlloc() 
{

    int *p = malloc(sizeof(int));

    *p = 12;

    printf("%d\n", *p);

    free(p);

}

void casting() 
{
    int x = 10;

    long long y = (long long)x + 12;

    printf("%zu\n", sizeof(y));
}

void p2p() 
{
    int x = 6767;
    int *p = &x;

    printf("%p\n", (void *)&p);

    int **q = &p;

    printf("value: %d\n", **q);
}

void pointerArray() 
{
    int a[] = {11, 22, 33, 44, 55};

    int *p = a;

    for(int i = 0; i < 5; ++i) 
        printf("%d\n", a[i]);

    printf("\n");

    for(int i = 0; i < 5; ++i) 
        printf("%d\n", p[i]);

    printf("\n");

    for(int i = 0; i < 5; ++i)
        printf("%d\n", *(a + i));

    printf("\n");

    for(int i = 0; i < 5; ++i)
        printf("%d\n", *(p + i));

    printf("\n");

    for(int i = 0; i < 5; ++i)
        printf("%d\n", *(p++));
}

void paddingBytes() 
{
    printf("%zu\n", sizeof(struct foo));

    printf("%zu\n", offsetof(struct foo, a));
    printf("%zu\n", offsetof(struct foo, b));
    printf("%zu\n", offsetof(struct foo, c));
    printf("%zu\n", offsetof(struct foo, d));
}

void nestedStructs()
{
    spaceship s = {
        .manufacturer = "General products",
        .passenger = {
            [0] = {.name="Brown, Teela",    .covid_vaccinated=1},
            [1] = {.name="Sun, Aaron",      .covid_vaccinated=0},
            [2] = {.name="Zheng, Michael",  .covid_vaccinated=1},
            [3] = {.name="Kim, Like",       .covid_vaccinated=0},
            [4] = {.name="Chang, Lian",     .covid_vaccinated=1},
            [5] = {.name="Hsu, HC",         .covid_vaccinated=0},
            [6] = {.name="Short, Quincy",   .covid_vaccinated=1},
            [7] = {.name="Madhav, Ayush",   .covid_vaccinated=0},
        }
    };

    printf("Passengers for %s ship:\n", s.manufacturer);

    for (int i = 0; i < MAX_PASSENGERS; ++i)
        if  (s.passenger[i].name != NULL)
            printf("\t %s (%svaccinated)\n", 
                s.passenger[i].name, 
                s.passenger[i].covid_vaccinated ? "" : "not ");
}

void enumTypes() {
    enum resource r = BRICK;

    if(r == BRICK)
        printf("I'll trade you a brick for two sheep\n");
}

int add(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

void print_math(int (*op)(int, int), int x, int y)
{
    int result = op(x, y);

    printf("%d\n", result);
}

/*------------------------------*/

/*---------- Exercises ----------*/

void rawArrNav() 
{
    int arr[10];

    int size = sizeof arr / sizeof(int);

    for(int *ptr = arr; ptr != arr + size; ++ptr) {
        *ptr = (int)((ptr - arr) * (ptr - arr));
    }

    for(int *ptr = arr; ptr < arr + size; ++ptr) {
        printf("arr[%ld] = %d\n", ptr - arr, *ptr);
    }

}

int allocate_int(int **out, int value) 
{
    *out = malloc(sizeof(int));
    if (*out == NULL) return -1;
    **out = value;
    return 0;
}

void voidPointerCast() 
{
    void *buffer = malloc(64);

    int *intByte = (int *)buffer;
    char *charByte = (char *)buffer + 4;
    float *floatByte = (float *)((char *)buffer + 8);

    *intByte = 67;
    *charByte = 's';
    *floatByte = 3.14f;

    printf("int byte: %d\nchar byte: %c\nfloat byte: %0.2f\n",
            *intByte, *charByte, *floatByte);

    free(buffer);
}

void pArithmetic()
{
    void *buffer = malloc(64);

    char *cptr = buffer;
    int *iptr = buffer;

    printf("address of char: %p\naddress of int:  %p\n\n", 
        (void *)cptr, (void *)iptr);

    cptr++, iptr++;

    printf("address of char: %p\naddress of int:  %p\n",
        (void *)cptr, (void *)iptr);

    free(buffer);

}

void insert_at_head(struct list **head, struct list *newNode)
{
    newNode->next = *head;
    *head = newNode;
}

struct list *create_node(int datum)
{
    struct list *node = malloc(sizeof(struct list));
    if (node == NULL) return NULL;
    node->datum = datum;
    node->next = NULL;
    return node;
}

void iterate(struct list *head)
{
    for(struct list *curr = head; curr != NULL; curr = curr->next)
        printf("%d -> ", curr->datum);
    printf("NULL\n");
}

void free_all(struct list *head)
{
    while(head) {
        struct list *dummy = head;
        head = head->next;
        free(dummy);
    }
        
}

void test_list()
{
    struct list *head = NULL;

    insert_at_head(&head, create_node(1));
    insert_at_head(&head, create_node(2));
    insert_at_head(&head, create_node(0));
    insert_at_head(&head, create_node(3));
    insert_at_head(&head, create_node(7));

    iterate(head);
    free_all(head);
}

struct len_string *len_string_from_c_string(char *s) 
{
    size_t len = strlen(s);

    struct len_string *ls = malloc(sizeof *ls + len);

    ls->length = (int) len;

    //memcpy(ls->data, s, len);
    my_memcpy(ls->data, s, len);

    return ls;
}

void flex_arr_member() {
    char *s = "Aaron is cool\n";

    struct len_string *lstr = len_string_from_c_string(s);

    printf("You are storing a flexible string of length %d in this struct:\n", lstr->length);

    for(int i = 0 ; i < lstr->length; ++i)
        printf("%c", lstr->data[i]);

    free(lstr);
}

void set_bit(uint64_t *bm, int n)
{
    *bm |= (1UL << n);
}

void clear_bit(uint64_t *bm, int n)
{
    *bm &= ~(1UL << n);
}

int test_bit(uint64_t bm, int n)
{
    return (bm >> n) & 1;
}

int find_first_free(uint64_t bm) 
{
    if (bm == UINT64_MAX) return -1;
    return __builtin_ctzll(~bm);
}

void test_bitmap() 
{
    uint64_t val = 0;
    uint64_t *bit = &val;
    printf("%" PRIu64 "\n", *bit);
    set_bit(bit, 2);
    printf("%" PRIu64 "\n", *bit);
    set_bit(bit, 1);
    printf("%" PRIu64 "\n", *bit);
    set_bit(bit, 0);
    printf("%" PRIu64 "\n", *bit);
    set_bit(bit, 0);
    set_bit(bit, 1);
    set_bit(bit, 2);
    printf("%" PRIu64 "\n", *bit);
    printf("%d\n", find_first_free(*bit));
    clear_bit(bit, 1);
    printf("%" PRIu64 "\n", *bit);
    clear_bit(bit, 2);
    clear_bit(bit, 0);
    printf("%" PRIu64 "\n", *bit);

    printf("%d\n", test_bit(*bit, 10));
    set_bit(bit, 10);
    printf("%d\n", test_bit(*bit, 10));
}

void set_flag(uint32_t *flags, uint32_t flag)
{
    *flags |= flag;
}

void clear_flag(uint32_t *flags, uint32_t flag)
{
    *flags &= ~flag;
}

void toggle_flag(uint32_t *flags, uint32_t flag)
{
    *flags ^= flag;
}

int test_flag(uint32_t flags, uint32_t flag)
{
    if (flags & flag) 
        return 1;
    return 0;
}

void int_callback(void *i) 
{
    printf("%d\n", *(int *)i);
}
void struct_callback(void *ptr)
{
    struct callback *c = (struct callback *)ptr;
    printf("%d\n", c->a + c->b);
}

void foreach(void *arr, size_t elts, size_t elt_size, void (*callback)(void *))
{
    char *end = (char *) arr + (elts * elt_size);
    for(char *start = (char *) arr; start != end; start += elt_size)
        callback(start);
}

void test_foreach()
{
    int int_arr[5] = {1, 2, 3, 4, 5}; 
    foreach(int_arr, 5, sizeof(int_arr[0]), int_callback);

    struct callback c_arr[5] = {
        {.a = 1, .b = 2},
        {.a = 3, .b = 4},
        {.a = 5, .b = 6},
        {.a = 7, .b = 8},
        {.a = 9, .b = 10},
    };

    printf("\n");
    foreach(c_arr, 5, sizeof(c_arr[0]), struct_callback);
}



// void foreach(void (*arr))

/*-------------------------------*/