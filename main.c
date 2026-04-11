
#include <stdio.h>
#include <stdbool.h>
#include "hello.h"

int main() {
    //hello();
    //array();
    rawArrNav();
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

void p2p(void) {

}

void voidPointerCast(void) {

}