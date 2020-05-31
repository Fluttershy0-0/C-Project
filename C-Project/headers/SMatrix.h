#define SMatrix_H
#pragma once

#include "common.h"
#include "../src/SVector.c"

typedef struct SMatrixTag
{
	UTYPE rows;
	UTYPE columns;
	DTYPE **mas;
} SMatrix;

/**
 * @brief Add values in SMatrix x and SMatrix y, by the indices
 * 
 * @param x SMatrix
 * @param y SMatrix
 * @return SMatrix 
 */
extern SMatrix add_SMatrix(SMatrix x, SMatrix y);

/**
 * @brief Substitute values in SMatrix x and SMatrix y, by the indices
 * 
 * @param x SMatrix
 * @param y SMatrix
 * @return SMatrix 
 */
extern SMatrix sub_SMatrix(SMatrix x, SMatrix y);

/**
 * @brief Multiply values in SMatrix x and SMatrix y by the indices
 * 
 * @param x SMatrix
 * @param y SMatrix
 * @return SMatrix 
 */
extern SMatrix mult_SMatrix(SMatrix x, SMatrix y);

/**
 * @brief Multiply every value in SMatrix x with DTYPE y 
 * 
 * @param x SMatrix
 * @param y DTYPE
 * @return SMatrix 
 */
extern SMatrix multConst_SMatrix(SMatrix x, DTYPE y);

/**
 * @brief Divide values in SMatrix x and SMatrix y, by the indices
 * 
 * @param x SMatrix
 * @param y SMatrix
 * @return SMatrix 
 */
extern SMatrix divide_SMatrix(SMatrix x, SMatrix y);

/**
 * @brief Divide every value in SMatrix x with DTYPE y 
 * 
 * @param x SMatrix
 * @param y DTYPE
 * @return SMatrix 
 */
extern SMatrix divideConst_SMatrix(SMatrix x, DTYPE y);

/**
 * @brief Do modulo division for values in SMatrix x and SMatrix y, by the indices
 * 
 * @param x SMatrix
 * @param y SMatrix
 * @return SMatrix 
 */
extern SMatrix mod_SMatrix(SMatrix x, SMatrix y);

/**
 * @brief Do modulo division for every value in SMatrix x with DTYPE y 
 * 
 * @param x SMatrix
 * @param y DTYPE
 * @return SMatrix 
 */
extern SMatrix modConst_SMatrix(SMatrix x, DTYPE y);

/**
 * @brief Change every value in SMatrix x by adding value in SMatrix y with the same index
 * 
 * @param x pointer to SMatrix
 * @param y SMatrix
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unadd_SMatrix(SMatrix *x, const SMatrix y);

/**
 * @brief Change every value in SMatrix x by substitute value in SMatrix y with the same index
 * 
 * @param x pointer to SMatrix
 * @param y SMatrix
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unsub_SMatrix(SMatrix *x, const SMatrix y);

/**
 * @brief Change every value in SMatrix x by multiply value in SMatrix y with the same index
 * 
 * @param x pointer to SMatrix
 * @param y SMatrix
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unmult_SMatrix(SMatrix *x, const SMatrix y);

/**
 * @brief Change every value in SMatrix x by division value in SMatrix y with the same index
 * 
 * @param x pointer to SMatrix
 * @param y SMatrix
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE undivide_SMatrix(SMatrix *x, const SMatrix y);

/**
 * @brief Change every value in SMatrix x by modulo division value in SMatrix y with the same index
 * 
 * @param x pointer to SMatrix
 * @param y SMatrix
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unmod_SMatrix(SMatrix *x, const SMatrix y);

/**
 * @brief Calculate determinant of x
 * 
 * @param x SMatrix
 * @return determinant
 */
extern DTYPE det_SMatrix(SMatrix x);

/**
 * @brief Calculate inverse matrix of x
 * 
 * @param x SMatrix
 * @return inverse SMatrix 
 */
extern SMatrix inverse_SMatrix(SMatrix x);

/**
 * @brief Multiply matrix on vector, by the algebra rule 
 * 
 * @param x SMatrix
 * @param y SVector
 * @return SVector 
 */
extern SVector solve_SMatrix(SMatrix x, SVector y);

/**
 * @brief Swap rows in matrix x 
 * 
 * @param x pointer to the matrix
 * @param i number of first row
 * @param j number of second row
 * @return is operation successfully finished
 */
extern ITYPE swap_row_SMatrix(SMatrix *x, UTYPE i, UTYPE j);

/**
 * @brief Swap columns in matrix x 
 * 
 * @param x pointer to the matrix
 * @param i number of first column
 * @param j number of second column
 * @return is operation successfully finished
 */
extern ITYPE swap_column_SMatrix(SMatrix *x, UTYPE i, UTYPE j);

/**
 * @brief Fill given SMatrix x with input values 
 * 
 * @param x pointer to SMatrix x
 * @return size of x
 */
extern ITYPE input_SMatrix(SMatrix *x);

/**
 * @brief Write values of SMatrix x in the current output stream with given type, width and precision
 * 
 * @param x SMatrix
 * @param type 0 - common representation, 1 - exponential representation of values
 * @param width minimum amount of chars, that every value fill
 * @param precision level of exactness in the values 
 * @return size of x 
 */
extern ITYPE output_SMatrix(SMatrix x, ITYPE type, ITYPE width, ITYPE precision);

/**
 * @brief Fill given SMatrix x with values in the binary file 
 * 
 * @param file name of the file
 * @param x pointer to SMatrix x
 * @return size of x
 */
extern ITYPE inputBinaryFile_SMatrix(char *file, SMatrix *x);

/**
 * @brief Write values of SMatrix x in the binary file 
 * 
 * @param File path to the file
 * @param x SMatrix
 * @return size of x 
 */
extern ITYPE outputBinaryFile_SMatrix(char *File, SMatrix x);

/**
 * @brief Fill given SMatrix x with values in the text file 
 * 
 * @param file path to the file
 * @param x pointer to SMatrix x
 * @return size of x
 */
extern ITYPE inputTextFile_SMatrix(char *file, SMatrix *x);

/**
 * @brief Write values of SMatrix x in the text file with given type, width and precision 
 * 
 * @param File path to the file
 * @param x SMatrix
 * @param type 0 - common representation, 1 - exponential representation of values
 * @param width minimum amount of chars, that every value fill
 * @param precision level of exactness in the values 
 * @return size of x 
 */
extern ITYPE outputTextFile_SMatrix(char *File, SMatrix x, ITYPE type, ITYPE width, ITYPE precision);

/**
 * @brief Generate SMatrix with size n*m
 * 
 * @param n number of rows
 * @param m number of columns
 * @return SMatrix 
 */
extern SMatrix generate_SMatrix(UTYPE n, UTYPE m);