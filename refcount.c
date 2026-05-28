#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct refCount
{
    int refNum;
};

struct my_data 
{
    char *name;
    int age;
    struct refCount rc;
};

void ref(struct refCount *rc) 
{
    ++rc->refNum;
}

int unref(struct refCount *rc) 
{
    assert(rc->refNum > 0);
    if (--rc->refNum == 0)
        return 1;
    return 0;
}

void ref_init(struct refCount *rc)
{
    rc->refNum = 1;
}

void data_stuff(struct my_data *data) {
    struct my_data *data_ptr2 = data;
    ref(&data_ptr2->rc);
    // BLAH BLAH BLAH
    printf("%s is %d years old\n", 
           data_ptr2->name, data_ptr2->age);
    if (unref(&data_ptr2->rc)) free(data_ptr2);
}

int main() {
    struct my_data *data;
    data = malloc(sizeof(*data));
    ref_init(&data->rc);
    data->name = "Aaron";
    data->age = 16;

    struct my_data *data_ptr1 = data;
    ref(&data_ptr1->rc);

    data_ptr1->age++;

    data_stuff(data);

    if (unref(&data_ptr1->rc)) free(data_ptr1);
    if (unref(&data->rc)) free(data);
}