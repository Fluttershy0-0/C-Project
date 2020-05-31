#include "../src/SVector.c"

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
const char *path_to_inputfile = "/home/pandrii000/hdd/University/Coursework/SVector_SMatrix_Polukhin_and_Liaskovskiy/tests/SVector_test.txt";
const char *path_to_outputfile = "/home/pandrii000/hdd/University/Coursework/SVector_SMatrix_Polukhin_and_Liaskovskiy/tests/SVector_output.txt";

void test_add_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST add_SVector FUNCTION\n");
    SVector a, b, answer;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    answer = add_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_sub_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST sub_SVector FUNCTION\n");
    SVector a, b, answer;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    answer = sub_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_mult_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST mult_SVector FUNCTION\n");
    SVector a, b, answer;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    answer = mult_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_divide_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST divide_SVector FUNCTION\n");
    SVector a, b, answer;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    answer = divide_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_mod_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST mod_SVector FUNCTION\n");
    SVector a, b, answer;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    answer = mod_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_multConst_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST multConst_SVector FUNCTION\n");
    SVector a, answer;
    ITYPE size_a;
    DTYPE b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read DTYPE b
    scanf("%lf", &b);
    // testing
    answer = multConst_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_divideConst_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST divideConst_SVector FUNCTION\n");
    SVector a, answer;
    ITYPE size_a;
    DTYPE b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read DTYPE b
    scanf("%lf", &b);
    // testing
    answer = divideConst_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_modConst_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST modConst_SVector FUNCTION\n");
    SVector a, answer;
    ITYPE size_a;
    DTYPE b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read DTYPE b
    scanf("%lf", &b);
    // testing
    answer = modConst_SVector(a, b);
    output_SVector(answer, type, width, precision);
}

void test_unadd_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unadd_SVector FUNCTION\n");
    SVector a, b;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    if(unadd_SVector(&a, b))
        output_SVector(a, type, width, precision);
}

void test_unsub_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unsub_SVector FUNCTION\n");
    SVector a, b;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    if(unsub_SVector(&a, b))
        output_SVector(a, type, width, precision);
}

void test_unmult_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unmult_SVector FUNCTION\n");
    SVector a, b;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    if(unmult_SVector(&a, b))
        output_SVector(a, type, width, precision);
}

void test_undivide_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST undivide_SVector FUNCTION\n");
    SVector a, b;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    if(undivide_SVector(&a, b))
        output_SVector(a, type, width, precision);
}

void test_unmod_SVector(ITYPE type, ITYPE width, ITYPE precision)
{
    printf("TEST unmod_SVector FUNCTION\n");
    SVector a, b;
    ITYPE size_a, size_b;
    // read vector a
    scanf("%u", &size_a);
    a = generate_SVector(size_a);
    input_SVector(&a);
    // read vector b
    scanf("%u", &size_b);
    b = generate_SVector(size_b);
    input_SVector(&b);
    // testing
    if(unmod_SVector(&a, b))
        output_SVector(a, type, width, precision);
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

    test_sub_SVector(0, 7, 2);

    if (input_type == INPUT_FROM_FILE)
        fclose(stdin);

    if (ouput_type == OUTPUT_IN_FILE)
        fclose(stdout);
}