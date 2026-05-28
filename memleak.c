#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCS 256
#define TRACKED_MALLOC(size) tracked_malloc(size, __FILE__, __LINE__)
#define TRACKED_FREE(ptr) tracked_free(ptr)
struct alloc_rec 
{
    void *address;
    size_t size_req;
    int line_num;
    char *filename;
    int freed;
};


struct alloc_rec record[MAX_ALLOCS];
int record_count = 0;


void *tracked_malloc(size_t size, char* file, int line) 
{
    void *m = malloc(size);
    record[record_count].address = m; 
    record[record_count].size_req = size; 
    record[record_count].line_num = line; 
    record[record_count].filename = file; 
    ++record_count;
    return m;
}


void tracked_free(void *m)
{
    free(m);
    for (int i = 0; i < record_count; ++i) 
        if (record[i].address == m)
            record[i].freed = 1;
}


void mem_report()
{
    for (int i = 0; i < record_count; ++i)
        if(!record[i].freed)
            printf("Unfreed: in %s line %d, size of %zu at address %p\n",
                    record[i].filename, record[i].line_num,
                    record[i].size_req, record[i].address);
}

struct my_data {
    char* name;
    int age;
};

int main() 
{
    int *age = TRACKED_MALLOC(sizeof(int));
    char **name = TRACKED_MALLOC(5);

    *age = 19;
    *name = "Aaron";

    struct my_data *data = TRACKED_MALLOC(sizeof(struct my_data));
    data->age = *age;
    data->name = *name;

    printf("%s is %d years old\n", data->name, data->age);

    mem_report();

    printf("Free struct\n");
    TRACKED_FREE(data);
    mem_report();

    printf("Free rest\n");
    TRACKED_FREE(age);
    TRACKED_FREE(name);
    mem_report();
}