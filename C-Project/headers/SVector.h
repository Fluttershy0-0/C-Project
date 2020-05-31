#define SVector_H
#pragma once

#include "common.h"

typedef struct SVectorTag
{
    UTYPE size;
    DTYPE *mas;

} SVector;

/**
 * @brief Add values in SVector x and SVector y, by the indices
 * 
 * @param x SVector
 * @param y SVector
 * @return SVector 
 */
extern SVector add_SVector(SVector x, SVector y);

/**
 * @brief Substitute values in SVector x and SVector y, by the indices
 * 
 * @param x SVector
 * @param y SVector
 * @return SVector 
 */
extern SVector sub_SVector(SVector x, SVector y);

/**
 * @brief Multiply values in SVector x and SVector y, by the indices
 * 
 * @param x SVector
 * @param y SVector
 * @return SVector 
 */
extern SVector mult_SVector(SVector x, SVector y);

/**
 * @brief Multiply every value in SVector x with DTYPE y 
 * 
 * @param x SVector
 * @param y DTYPE
 * @return SVector 
 */
extern SVector multConst_SVector(SVector x, DTYPE y);

/**
 * @brief Divide values in SVector x and SVector y, by the indices
 * 
 * @param x SVector
 * @param y SVector
 * @return SVector 
 */
extern SVector divide_SVector(SVector x, SVector y);

/**
 * @brief Divide every value in SVector x with DTYPE y 
 * 
 * @param x SVector
 * @param y DTYPE
 * @return SVector 
 */
extern SVector divideConst_SVector(SVector x, DTYPE y);

/**
 * @brief Do modulo division for values in SVector x and SVector y, by the indices
 * 
 * @param x SVector
 * @param y SVector
 * @return SVector 
 */
extern SVector mod_SVector(SVector x, SVector y);

/**
 * @brief Do modulo division for every value in SVector x with DTYPE y 
 * 
 * @param x SVector
 * @param y DTYPE
 * @return SVector 
 */
extern SVector modConst_SVector(SVector x, DTYPE y);

/**
 * @brief Change every value in SVector x by adding value in SVector y with the same index
 * 
 * @param x pointer to SVector
 * @param y Dvector
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unadd_SVector(SVector *x, const SVector y);

/**
 * @brief Change every value in SVector x by substitute value in SVector y with the same index
 * 
 * @param x pointer to SVector
 * @param y Dvector
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unsub_SVector(SVector *x, const SVector y);

/**
 * @brief Change every value in SVector x by multiply value in SVector y with the same index
 * 
 * @param x pointer to SVector
 * @param y Dvector
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unmult_SVector(SVector *x, const SVector y);

/**
 * @brief Change every value in SVector x by division value in SVector y with the same index
 * 
 * @param x pointer to SVector
 * @param y Dvector
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE undivide_SVector(SVector *x, const SVector y);

/**
 * @brief Change every value in SVector x by modulo division value in SVector y with the same index
 * 
 * @param x pointer to SVector
 * @param y Dvector
 * @return 0 if operation can not be executed, else 1
 */
extern ITYPE unmod_SVector(SVector *x, const SVector y);

/**
 * @brief Fill given SVector x with input values 
 * 
 * @param x pointer to SVector x
 * @return size of x
 */
extern ITYPE input_SVector(SVector *x);

/**
 * @brief Write values of SVector x in the current output stream with given type, width and precision
 * 
 * @param x SVector
 * @param type 0 - common representation, 1 - exponential representation of values
 * @param width minimum amount of chars, that every value fill
 * @param precision level of exactness in the values 
 * @return size of x 
 */
extern ITYPE output_SVector(SVector x, ITYPE type, ITYPE width, ITYPE precision);

/**
 * @brief Fill given SVector x with values in the binary file 
 * 
 * @param file name of the file
 * @param x pointer to SVector x
 * @return size of x
 */
extern ITYPE inputBinaryFile_SVector(char *file, SVector *x);

/**
 * @brief Write values of SVector x in the binary file 
 * 
 * @param File path to the file
 * @param x SVector
 * @return size of x 
 */
extern ITYPE outputBinaryFile_SVector(char *File, SVector x);

/**
 * @brief Fill given SVector x with values in the text file 
 * 
 * @param file path to the file
 * @param x pointer to SVector x
 * @return size of x
 */
extern ITYPE inputTextFile_SVector(char *file, SVector *x);

/**
 * @brief Write values of SVector x in the text file with given type, width and precision 
 * 
 * @param File path to the file
 * @param x SVector
 * @param type 0 - common representation, 1 - exponential representation of values
 * @param width minimum amount of chars, that every value fill
 * @param precision level of exactness in the values 
 * @return size of x 
 */
extern ITYPE outputTextFile_SVector(char *File, SVector x, ITYPE type, ITYPE width, ITYPE precision);

/**
 * @brief Generate SVector with size n
 * 
 * @param n size of SVector
 * @return SVector 
 */
extern SVector generate_SVector(UTYPE n);