#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

typedef struct {
    void *data;
    size_t elem_size;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *v, size_t elem_size) {
    v->data = NULL;
    v->elem_size = elem_size;
    v->size = 0;
    v->capacity = 0;
}

void vector_append(Vector *v, const void *elem) {
    if (v->size == v->capacity) {
        size_t new_capacity = v->capacity ? v->capacity * 2 : 4;
        void *new_data = realloc(v->data, new_capacity * v->elem_size);
        if (!new_data) {
            perror("realloc");
            exit(1);
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    memcpy((char *)v->data + v->size * v->elem_size, elem, v->elem_size);
    v->size++;
}

void vector_remove_at(Vector *v, size_t index) {
    if (index >= v->size) return;

    void *dst = (char *)v->data + index * v->elem_size;
    void *src = (char *)dst + v->elem_size;
    size_t bytes = (v->size - index - 1) * v->elem_size;

    memmove(dst, src, bytes);
    v->size--;
}

void *vector_get(Vector *v, size_t index) {
    if (index >= v->size) return NULL;
    return (char *)v->data + index * v->elem_size;
}

void vector_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->elem_size = 0;
}

typedef struct point {
    long int x;
    long int y;
    long int z;
} Point;


long distance(Point *a, Point *b) {
    return pow((a->x - b->x),2) + pow((a->y - b->y),2) + pow((a->z - b->z),2);
}

int point_eq(Point *a, Point *b) {
    //printf("left: %ld %ld %ld right: %ld %ld %ld\n", a->x , b->x , a->y , b->y , a->z , b->z);
    return a->x == b->x && a->y == b->y && a->z == b->z;
}

typedef struct pair {
    Point a;
    Point b;
    long distance;
} Pair;


void merge(Vector *grid, int left_i, int right_i) {
    if (left_i == right_i) return;

    Vector **left  = (Vector **)vector_get(grid, left_i);
    Vector **right = (Vector **)vector_get(grid, right_i); 

    // append all points from right to left
    for (size_t k = 0; k < (*right)->size; k++) {
        Point *p = (Point *)vector_get(*right, k);
        vector_append(*left, p);
    }

    vector_free(*right); 
    free(*right); 
    vector_remove_at(grid, right_i);
}

int comp_pair (const void *left, const void *right) {
    long da = ((Pair *)left)->distance;
    long db = ((Pair *)right)->distance;
    if (da < db) return -1;
    else if (da > db) return 1;
    return 0;

}

int comp_circuit(const void *left, const void *right) {
    int rs = (*(Vector **)right)->size;
    int ls = (*(Vector **)left)->size;
    if (rs < ls) return -1;
    else if (rs > ls) return 1;
    return 0;

}

int main() {

    long int x,y,z,iter=0;
    char buffer[64];

    Vector grid;
    vector_init(&grid, sizeof(Vector *));

    while(fgets(buffer, sizeof(buffer), stdin)) { 
        sscanf(buffer, "%ld,%ld,%ld", &x, &y, &z);

        Vector *circuit = malloc(sizeof(Vector));
        vector_init(circuit, sizeof(Point)); 

        Point p = {x,y,z};
        vector_append(circuit, &p);
        vector_append(&grid, &circuit);
        iter++;
    }
    Vector pairs;
    vector_init(&pairs, sizeof(Pair));


    for (int i =0; i< grid.size; i++) {
        for (int j = i + 1; j<grid.size; j++) {
            Pair pr;
            Vector *v_a = *(Vector **)vector_get(&grid, i);
            Vector *v_b = *(Vector **)vector_get(&grid, j);

            pr.a = *(Point *)vector_get(v_a, 0);
            pr.b = *(Point *)vector_get(v_b, 0);

            pr.distance = distance(&pr.a, &pr.b);
            vector_append(&pairs, &pr);
        }

    }

    qsort(pairs.data, pairs.size,sizeof(Pair), &comp_pair);

    // for(int k =0;k<pairs.size;k++){
    //     Pair *ab = (Pair*)vector_get(&pairs,k);
    //     printf("a: (%ld,%ld,%ld) b: (%ld,%ld,%ld) distance: %ld\n", ab->a.x, ab->a.y, ab->a.z, ab->b.x, ab->b.y, ab->b.z, ab->distance);
    // }

    
    for(int pair_i = 0; pair_i < pairs.size; pair_i++) {
        printf("grid size %zu\n", grid.size);
        if (grid.size == 1) {
            break;
        }
        assert(pairs.size > 10);
        int left_j = -1, right_j = -1;
        Pair *s = (Pair*)vector_get(&pairs,pair_i);


        // left
        for(int j=0; j< grid.size; j++){
            Vector *v = *(Vector **)vector_get(&grid, j);
            for(int k=0; k< v->size; k++){ 
                Point *p = (Point *)vector_get(v, k);
                // find which circuit the points are in
                if (point_eq(p, &s->a)) left_j = j;
                if (point_eq(p, &s->b)) right_j = j;

            }
            
            // if not already merged
            if (left_j >= 0 && right_j >= 0 && left_j != right_j) {
                printf("a: (%ld,%ld,%ld) b: (%ld,%ld,%ld)\n", s->a.x, s->a.y, s->a.z, s->b.x, s->b.y, s->b.z);
                printf("total %ld\n", s->a.x*s->b.x);
                if (left_j < right_j) {
                    merge(&grid, left_j, right_j);
                } else {
                    merge(&grid, right_j, left_j);
                }
                break;
            }
            
        }
        
    }

    qsort(grid.data, grid.size,sizeof(Vector *), &comp_circuit);


    // for (int i = 0; i < grid.size; i++) {
    //     Vector *v = *(Vector **)vector_get(&grid, i); 
    //     printf("Circuit %d: ", i);
    //     for (int k = 0; k < v->size; k++) {
    //         Point *p = (Point *)vector_get(v, k);
    //         printf("(%ld,%ld,%ld) ", p->x, p->y, p->z);
    //     }
    //     printf("\n");
    // } 
    
    vector_free(&pairs);
    vector_free(&grid);

    return 0;
}

/**
a - b 

a - c - d

----
a - b 

b - c - d

----
a - b 

a - b - c - d

*/