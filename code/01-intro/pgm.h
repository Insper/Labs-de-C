#ifndef __PGM_H_
#define __PGM_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HI(num)	(((num) & 0x0000FF00) << 8)
#define LO(num)	((num) & 0x000000FF)

typedef struct _PGMData {
    int row;
    int col;
    int max_gray;
    int **matrix;
} PGMData;

PGMData* readPGM(const char *file_name, PGMData *data);
void writePGM(const char *filename, const PGMData *data);
static int **allocate_dynamic_matrix(int row, int col);
static void deallocate_dynamic_matrix(int **matrix, int row);
static void SkipComments(FILE *fp);

#endif // __PGM_H_
