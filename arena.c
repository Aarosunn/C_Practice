
#include <stdlib.h>
#include<stddef.h>

struct arena {
    void *start_ptr;
    void *bump_ptr;
    size_t capacity;
};

struct arena *initialize_arena();
void *allocate(struct arena *a, size_t N);
void reset(struct arena *a);

int main()
{
    struct arena *a = initialize_arena();
    int *i = (int *)allocate(a, 4);
    *i = 86;

    free(a->start_ptr);
    free(a);
}


struct arena *initialize_arena() 
{
    struct arena *a = malloc(sizeof(struct arena));
    if(a == NULL) return NULL;
    a->start_ptr = malloc(4096);
    a->bump_ptr = a->start_ptr;
    a->capacity = 4096;
    return a;
}

void *allocate(struct arena *a, size_t N)
{
    if ((size_t)((char *)a->bump_ptr - (char *)a->start_ptr) + N > a->capacity) return NULL;
    void *curr_ptr = a->bump_ptr;
    size_t aligned_size = ((size_t)N + 7) & ~(size_t)7;
    a->bump_ptr = (char *)a->bump_ptr + aligned_size;
    return curr_ptr;
}

void reset(struct arena *a)
{
    a->bump_ptr = a->start_ptr;
}

