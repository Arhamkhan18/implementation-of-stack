#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char category[50];
    char name[50];
    char seller[50];
    double price;
    double rating;
} Product;

typedef struct {
    int *indices;
    int size;
} IndirectArray;

IndirectArray createIndirectArray(int size) {
    IndirectArray indirectArray;
    indirectArray.size = size;
    indirectArray.indices = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
        indirectArray.indices[i] = i;
    return indirectArray;
}

void sortProductsByCategory(int *indices, Product *products, int size) {
    qsort(indices, size, sizeof(int), 
          (int (*)(const void *, const void *)) 
          (int (*)(const void *, const void *)) 
          [products](const void *a, const void *b) {
            return strcmp(products[*(int *)a].category, 
                          products[*(int *)b].category);
          });
}

void sortProductsByName(int *indices, Product *products, int size) {
    qsort(indices, size, sizeof(int), 
          (int (*)(const void *, const void *)) 
          (int (*)(const void *, const void *)) 
          [products](const void *a, const void *b) {
            return strcmp(products[*(int *)a].name, 
                          products[*(int *)b].name);
          });
}

void sortProductsBySeller(int *indices, Product *products, int size) {
    qsort(indices, size, sizeof(int), 
          (int (*)(const void *, const void *)) 
          (int (*)(const void *, const void *)) 
          [products](const void *a, const void *b) {
            return strcmp(products[*(int *)a].seller, 
                          products[*(int *)b].seller);
          });
}

void sortProductsByPrice(int *indices, Product *products, int size) {
    qsort(indices, size, sizeof(int), 
          (int (*)(const void *, const void *)) 
          (int (*)(const void *, const void *)) 
          [products](const void *a, const void *b) {
            return (products[*(int *)a].price > products[*(int *)b].price) ? 1 : -1;
          });
}

void sortProductsByRating(int *indices, Product *products, int size) {
    qsort(indices, size, sizeof(int), 
          (int (*)(const void *, const void *)) 
          (int (*)(const void *, const void *)) 
          [products](const void *a, const void *b) {
            return (products[*(int *)a].rating < products[*(int *)b].rating) ? 1 : -1;
          });
}

int getProductAtIndex(int index, int *indices, Product *products) {
    return indices[index];
}

int main() {
    Product products[] = {
        {"Electronics", "Laptop", "ABC Electronics", 1200.0, 4.5},
        {"Clothing", "T-Shirt", "XYZ Clothing", 25.0, 4.0},
        {"Electronics", "Smartphone", "PQR Electronics", 800.0, 4.2}
    };

    int size = sizeof(products) / sizeof(products[0]);
    IndirectArray indirectArray = createIndirectArray(size);

    sortProductsByCategory(indirectArray.indices, products, size);
    sortProductsByName(indirectArray.indices, products, size);
    sortProductsBySeller(indirectArray.indices, products, size);
    sortProductsByPrice(indirectArray.indices, products, size);
    sortProductsByRating(indirectArray.indices, products, size);

    printf("Sorted indices:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", getProductAtIndex(i, indirectArray.indices, products));
    }
    printf("\n");

    free(indirectArray.indices);

    return 0;
}
