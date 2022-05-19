#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv) {
    clock_t begin = clock();
    srand(time(NULL));
    int n;
    n = atoi(argv[1]);
    int *x = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *mat = (int *)malloc(n * n * sizeof(int));
    int i, j;

    for (i = 0; i < n; i++) {
        x[i] = rand();
        for (j = 0; j < n; j++) {
            mat[i * n + j] = rand();
        }
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            b[i] = b[i] + mat[i * n + j] * x[j];
        }
    }

    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
    //         printf("%d ", mat[i * n + j]);
    //     }
    //     printf("\n");
    // }

    // for (j = 0; j < n; j++) {
    //     printf("%d ", x[j]);
    // }

    // printf("\n");

    // for (j = 0; j < n; j++) {
    //     printf("%d ", b[j]);
    // }

    // printf("\n");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%d\n", n);

    FILE *fptr;
    fptr = fopen("dados_iter_trocada.csv", "a");
    if(fptr == NULL) {
      printf("Error!");   
      exit(1);             
    }

    fprintf(fptr,"%d", n);
    fprintf(fptr,",%f\n", time_spent);
    fclose(fptr);
    
    exit(0);
}