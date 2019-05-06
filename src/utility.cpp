//
// Created by sriteja on 16/2/19.
//

#include "main.h"


void print_mat4(glm::mat4 matrix) {
    printf("\nmatrix\n");
    for (int i=0;i<4;i++)
        printf("%f  %f  %f  %f\n",matrix[i].x, matrix[i].y, matrix[i].z, matrix[i].w);
    printf("\n");
}