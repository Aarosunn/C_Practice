
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hello.h"

int main() {
    //hello();
    //array();
    //rawArrNav();
    //test_memcpy();
    animal_compare();
}

void hello(void) {
    printf("Hello World!\n");
    int i = 2;
    double f = 3.14;
    char *s = "Hello, world!";
    printf("%s i = %d and f = %.2f!\n", s, i, f);

    bool x = true;

    if (x) {
        printf("x is true\n");
    }

    int y = 32;
    printf("The number %d is %s.\n", y, y % 2 == 0 ? "even": "odd");

    printf("The size of i is %zu\n", sizeof(i));

    printf("The size of a pointer is %zu\n", sizeof(int*));

    i = 10;

    printf("The address of i is %p\n", (void *)&i);

    int *p = &i;

    printf("i is %d\n", *p);
}

void array(void) {
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

void rawArrNav(void) {
    int arr[10];

    int size = sizeof arr / sizeof(int);

    for(int *ptr = arr; ptr != arr + size; ++ptr) {
        *ptr = (int)((ptr - arr) * (ptr - arr));
    }

    for(int *ptr = arr; ptr < arr + size; ++ptr) {
        printf("arr[%ld] = %d\n", ptr - arr, *ptr);
    }

}

void *my_memcpy(void *dest, void *src, int byte_count) {
    
    char *s = src, *d = dest;

    while(byte_count--) {
        *d++ = *s++;
    }

    return dest;
}

void test_memcpy() {
    char* s = "Goats!";
    char t[100];

    my_memcpy(t, s, 7);

    printf("%s\n", t);

    int a[] = {11, 22, 33};
    int b[3];

    my_memcpy(b, a, sizeof(a));

    printf("%d\n", b[1]);
}

int compar(const void *elem1, const void *elem2) {

    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;

    if(animal1->leg_count > animal2->leg_count)
        return 1;

    if(animal1->leg_count < animal2->leg_count)
        return -1;

    return 0;
}

void animal_compare() {

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

// void allocate_int(int **out, int value) {

// }

void voidPointerCast(void) {

}