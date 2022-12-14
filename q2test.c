#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_kernel_2D_memcpy 451

int main() {
    float MAT1[3][3] = {{1.0,2.0,3.0},{3.0,4.0,5.0},{6.0,7.0,8.0}};
    float MAT2[3][3] = {{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0}};

    printf("Destination Matrix:\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", MAT1[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    printf("Source Matrix:\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", MAT2[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    int res = syscall(SYS_kernel_2D_memcpy, MAT1, MAT2);

    if(res < 0){
        printf("ERROR! Could not perform system call.");
        exit(1);
    }

    printf("Destination Matrix:\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", MAT1[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    printf("Source Matrix:\n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", MAT2[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    return 0;
}
