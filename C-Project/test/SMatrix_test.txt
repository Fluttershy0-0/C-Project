#include "../src/SMatrix.c"

enum INPUT_TYPE
{
    INPUT_FROM_CONSOLE,
    INPUT_FROM_FILE
};

enum OUTPUT_TYPE
{
    OUTPUT_IN_CONSOLE,
    OUTPUT_IN_FILE
};

const enum INPUT_TYPE input_type = INPUT_FROM_FILE;
const enum OUTPUT_TYPE ouput_type = OUTPUT_IN_FILE;
const char *path_to_inputfile = "/home/pandrii000/hdd/University/Coursework/SVector_SMatrix_Polukhin_and_Liaskovskiy/tests/SMatrix_test.txt";
const char *path_to_outputfile = "/home/pandrii000/hdd/University/Coursework/SVector_SMatrix_Polukhin_and_Liaskovskiy/tests/SMatrix_output.txt";

void test_add_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST add_SMatrix FUNCTION\n");
    SMatrix a, b, answer;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    answer = add_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_sub_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST sub_SMatrix FUNCTION\n");
    SMatrix a, b, answer;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    answer = sub_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_mult_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST mult_SMatrix FUNCTION\n");
    SMatrix a, b, answer;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    answer = mult_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_divide_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST divide_SMatrix FUNCTION\n");
    SMatrix a, b, answer;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    answer = divide_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_mod_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST mod_SMatrix FUNCTION\n");
    SMatrix a, b, answer;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    answer = mod_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_multConst_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST multConst_SMatrix FUNCTION\n");
    SMatrix a, answer;
    ITYPE size_a_rows, size_a_columns;
    DTYPE b;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read DTYPE b
    scanf("%lf", &b);
    // testing
    answer = multConst_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_divideConst_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST divideConst_SMatrix FUNCTION\n");
    SMatrix a, answer;
    ITYPE size_a_rows, size_a_columns;
    DTYPE b;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read DTYPE b
    scanf("%lf", &b);
    // testing
    answer = divideConst_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_modConst_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST modConst_SMatrix FUNCTION\n");
    SMatrix a, answer;
    ITYPE size_a_rows, size_a_columns;
    DTYPE b;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read DTYPE b
    scanf("%lf", &b);
    // testing
    answer = modConst_SMatrix(a, b);
    output_SMatrix(answer, type, width, precision);
}

void test_unadd_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unadd_SMatrix FUNCTION\n");
    SMatrix a, b;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    if (unadd_SMatrix(&a, b))
        output_SMatrix(a, type, width, precision);
}

void test_unsub_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unsub_SMatrix FUNCTION\n");
    SMatrix a, b;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    if (unsub_SMatrix(&a, b))
        output_SMatrix(a, type, width, precision);
}

void test_unmult_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unmult_SMatrix FUNCTION\n");
    SMatrix a, b;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    if (unmult_SMatrix(&a, b))
        output_SMatrix(a, type, width, precision);
}

void test_undivide_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST undivide_SMatrix FUNCTION\n");
    SMatrix a, b;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    if (undivide_SMatrix(&a, b))
        output_SMatrix(a, type, width, precision);
}

void test_unmod_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unmod_SMatrix FUNCTION\n");
    SMatrix a, b;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b_rows, size_b_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read matrix b
    scanf("%d %d", &size_b_rows, &size_b_columns);
    b = generate_SMatrix(size_b_rows, size_b_columns);
    input_SMatrix(&b);
    // testing
    if (unmod_SMatrix(&a, b))
        output_SMatrix(a, type, width, precision);
}


void test_det(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST det FUNCTION\n");
    SMatrix a;
    ITYPE size_a_rows, size_a_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // testing
    DTYPE d = det_SMatrix(a);
    if (type == 0)
        printf("%*.*lf ", width, precision, d);
    else    
        printf("%*.*e ", width, precision, d);
}

void test_solve_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST solve_SMatrix FUNCTION\n");
    SMatrix a;
    SVector b;
    ITYPE size_a_rows, size_a_columns;
    ITYPE size_b;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read vector b
    scanf("%d", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    SVector answer = solve_SMatrix(a, b);
    output_SVector(answer, type, width, precision);
}

void test_swap_row_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST swap_row_SMatrix FUNCTION\n");
    SMatrix a;
    ITYPE size_a_rows, size_a_columns, i, j;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read i and j
    scanf("%d %d", &i, &j);
    // testing
    swap_row_SMatrix(&a, i, j);
    output_SMatrix(a, type, width, precision);
}

void test_swap_column_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST swap_column_SMatrix FUNCTION\n");
    SMatrix a;
    ITYPE size_a_rows, size_a_columns, i, j;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // read i and j
    scanf("%d %d", &i, &j);
    // testing
    swap_column_SMatrix(&a, i, j);
    output_SMatrix(a, type, width, precision);
}

void test_inverse_SMatrix(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST inverse_SMatrix FUNCTION\n");
    SMatrix a;
    ITYPE size_a_rows, size_a_columns;
    // read matrix a
    scanf("%d %d", &size_a_rows, &size_a_columns);
    a = generate_SMatrix(size_a_rows, size_a_columns);
    input_SMatrix(&a);
    // testing
    SMatrix inv_a = inverse_SMatrix(a);
    output_SMatrix(inv_a, type, width, precision);
}

int main()
{
    if (input_type == INPUT_FROM_FILE)
    {
        FILE *read_ptr = freopen(path_to_inputfile, "r", stdin);
        if (read_ptr == NULL)
        {
            printf("Read error!\n");
            return 0;
        }
    }

    if (ouput_type == OUTPUT_IN_FILE)
    {
        FILE *write_ptr = freopen(path_to_outputfile, "w", stdout);
        if (write_ptr == NULL)
        {
            printf("Write error!\n");
            return 0;
        }
    }

    test_add_SMatrix(0, 7, 2);

    if (input_type == INPUT_FROM_FILE)
        fclose(stdin);

    if (ouput_type == OUTPUT_IN_FILE)
        fclose(stdout);
}