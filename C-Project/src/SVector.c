#pragma once

#include "../headers/SVector.h"

SVector generate_SVector(UTYPE n)
{
    SVector newvector;
    newvector.size = n;
    newvector.mas = (DTYPE *)malloc(sizeof(DTYPE) * n);
    return newvector;
}

ITYPE input_SVector(SVector *x)
{
    for (UTYPE _i = 0; _i < x->size; ++_i)
    {
        scanf("%lf", &(x->mas[_i]));
    }
    return x->size;
}

ITYPE output_SVector(SVector x, ITYPE type, ITYPE width, ITYPE precision)
{
    if (type == 0)
    {
        for (UTYPE _i = 0; _i < x.size; ++_i)
            printf("%*.*lf ", width, precision, x.mas[_i]);
    }
    else
    {
        for (UTYPE _i = 0; _i < x.size; ++_i)
            printf("%*.*e ", width, precision, x.mas[_i]);
    }
    return x.size;
}

ITYPE inputBinaryFile_SVector(char *file, SVector *x)
{
    FILE *read_ptr;
    if ((read_ptr = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Read error!\n");
        return 0;
    }
    printf("%p\n", read_ptr);
    fread(x->mas, sizeof(DTYPE), x->size, read_ptr);
    fclose(read_ptr);
    return x->size;
}

ITYPE outputBinaryFile_SVector(char *file, SVector x)
{
    FILE *write_ptr;
    if ((write_ptr = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Write error!\n");
        return 0;
    }
    fwrite(x.mas, sizeof(DTYPE), x.size, write_ptr);
    fclose(write_ptr);
    return x.size;
}

ITYPE inputTextFile_SVector(char *file, SVector *x)
{
    FILE *read_ptr;
    if ((read_ptr = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "Read error!\n");
        return 0;
    }

    for (UTYPE _i = 0; _i < x->size; ++_i)
        fscanf(read_ptr, "%lf", &(x->mas[_i]));
    fclose(read_ptr);
    return x->size;
}

ITYPE outputTextFile_SVector(char *file, SVector x, int type, int width, int precision)
{
    FILE *write_ptr;
    if ((write_ptr = fopen(file, "w")) == NULL)
    {
        fprintf(stderr, "Write error!\n");
        return 0;
    }
    if (type == 0)
    {
        for (UTYPE _i = 0; _i < x.size; ++_i)
            fprintf(write_ptr, "%*.*lf ", width, precision, x.mas[_i]);
    }
    else
    {
        for (UTYPE _i = 0; _i < x.size; ++_i)
            fprintf(write_ptr, "%*.*e ", width, precision, x.mas[_i]);
    }
    fprintf(write_ptr, "\n");
    printf("Done!");
    fclose(write_ptr);
    return x.size;
}

SVector add_SVector(SVector x, SVector y)
{
    if (x.size != y.size)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
        x.mas[i] += y.mas[i];

    return x;
}

SVector sub_SVector(SVector x, SVector y)
{
    if (x.size != y.size)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
        x.mas[i] -= y.mas[i];

    return x;
}

SVector mult_SVector(SVector x, SVector y)
{
    if (x.size != y.size)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
        x.mas[i] *= y.mas[i];

    return x;
}

SVector multConst_SVector(SVector x, DTYPE y)
{
    for (UTYPE i = 0; i < x.size; i++)
        x.mas[i] *= y;

    return x;
}

SVector divide_SVector(SVector x, SVector y)
{
    if (x.size != y.size)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
    {
        if (y.mas[i] == 0)
            return generate_SVector(0);

        x.mas[i] /= y.mas[i];
    }

    return x;
}

SVector divideConst_SVector(SVector x, DTYPE y)
{
    if (y == 0)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
    {
        x.mas[i] /= y;
    }

    return x;
}

SVector mod_SVector(SVector x, SVector y)
{
    if (x.size != y.size)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
    {
        if (y.mas[i] == 0)
            return generate_SVector(0);

        while (x.mas[i] - y.mas[i] >= 0)
        {
            x.mas[i] -= y.mas[i];
        }
    }

    return x;
}

SVector modConst_SVector(SVector x, DTYPE y)
{
    if (y == 0)
        return generate_SVector(0);

    for (UTYPE i = 0; i < x.size; i++)
    {
        while (x.mas[i] - y >= 0)
        {
            x.mas[i] -= y;
        }
    }

    return x;
}

ITYPE unadd_SVector(SVector *x, const SVector y)
{
    if (x->size != y.size)
        return 0;

    for (UTYPE i = 0; i < x->size; i++)
        x->mas[i] += y.mas[i];

    return 1;
}

ITYPE unsub_SVector(SVector *x, const SVector y)
{
    if (x->size != y.size)
        return 0;

    for (UTYPE i = 0; i < x->size; i++)
        x->mas[i] -= y.mas[i];

    return 1;
}

ITYPE unmult_SVector(SVector *x, const SVector y)
{
    if (x->size != y.size)
        return 0;

    for (UTYPE i = 0; i < x->size; i++)
        x->mas[i] *= y.mas[i];

    return 1;
}

ITYPE undivide_SVector(SVector *x, const SVector y)
{
    if (x->size != y.size)
        return 0;

    for (UTYPE i = 0; i < x->size; i++)
        if (y.mas[i] == 0)
            return 0;

    for (UTYPE i = 0; i < x->size; i++)
        x->mas[i] /= y.mas[i];

    return 1;
}

ITYPE unmod_SVector(SVector *x, const SVector y)
{
    if (x->size != y.size)
        return 0;

    for (UTYPE i = 0; i < x->size; i++)
        if (y.mas[i] == 0)
            return 0;

    for (UTYPE i = 0; i < x->size; i++)
        while (x->mas[i] - y.mas[i] >= 0)
        {
            x->mas[i] -= y.mas[i];
        }
    return 1;
}