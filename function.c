#include <stdio.h>
#include <stdlib.h>


void fibonacci_sequence(int n){
    /* Function: fibonacci_sequence
     * ----------------------------
     *
     * Compute the n first terms of Fibonacci sequence
     *
     * n : number of terms computed
     * */
    int u0 = 0;
    int u1 = 1;
    int tmp = 0;

    // Loop over the indices
    for (int i=0 ; i < n ; i++){
        tmp = u1;
        u1 += u0;
        u0 = tmp;
        printf("\nu_%d: %d", i, u0);
    }
}

void display_row(int *table, size_t n){
    /* Function : display_row
     * ----------------------
     *
     *  Display a row of Pascal triangle
     *
     *  table : row of Pascal triangle
     *  n : Size of the row
     * */
    printf("\n");
    for (int i=0 ; i < n; i++){
        if (*(table + i) != 0){
            printf("%d\t", *(table + i));
        }
    }
}

void pascal_triangle(int n){
    /* Function: fibonacci_sequence
     * ----------------------------
     *
     * Compute the n first row of Pascal triangle
     *
     * n : number of rows computed
     * */
    int *table = (int *)malloc((n+1) * sizeof(int));

    *table = 1;
    for (int j=1 ; j <= n; j++){
        *(table + j) = 0;
    }
    display_row(table, n);

    for (int i = 1 ; i < n; i++){
        for (int j=n ; j > 0 ; j--) {
            *(table + j) += *(table + j - 1);
        }
        display_row(table, n);
    }
}
