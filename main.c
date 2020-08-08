#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "function.h"


void usage(){
    /* Print usage
     * */
    fprintf(stderr, "Usage: out [fph] n\n\n");
    fputs(
        "[-f] Compute n terms of Fibonnacci sequence\n" 
        "[-p] Compute n rows of Pascal triangle\n" 
        "[-h] Manual\n" 
        , stderr
    );
    exit(1);
}

int pascal_option(char *option){
    /* Handle Pascal option
     *
     * option : User option
     * */
    int n = atoi(option);
    if (n==0){
        usage();
    }
    printf("\nPASCAL TRIANGLE");
    printf("\n---------------");
    pascal_triangle(n);
    printf("\n");
    exit(0);
}

int fibonnacci_option(char *option){
    /* Handle Fibonnacci option
     *
     * option : User option
     * */
    int n = atoi(option);
    if (n==0){
        usage();
    }
    printf("\nFIBONNACCI SEQUENCE");
    printf("\n-------------------");
    fibonacci_sequence(n);
    printf("\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    int opt; 
    while ((opt = getopt(argc, argv, "fph")) != -1) {
        switch (opt) 
            case 'f':
                fibonnacci_option(argv[optind]); break;
            case 'p':
                pascal_option(argv[optind]); break;
            case 'h':
                usage(); break;
            case '?':
                usage(); break;
        }
    }
    usage();
    return 0;
}
