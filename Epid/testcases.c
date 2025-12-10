#include <stdio.h>
#include <math.h>
#include "CuTest.h"
#include "epid.h"

// funktionsprototype

void simulerEpidemi(
    SEIHRS_model *,
    int model_type,
    int use_app,
    int use_vaccine,
    int valg_input,
    FILE *file,
    int replicate_num,
    int is_stochastic,
    int print_to_terminal);

// testcase 1 af vaccine funktion (vaccine til)
void vaccine_effekt_1(CuTest *tc)
{

    SEIHRS_model tekstfil[2];
    SEIHRS_model tekstfil_orig[2];

    FILE *testfile = fopen("test_output.txt", "w");

    simulerEpidemi(
        &tekstfil[1],
        1, // SIR
        0, // ingen app
        1, // vaccine til
        1, // inputfil 1
        testfile,
        1, // 1 simulering
        0, // deterministisk
        0  // ingen terminalprint
    );

    fclose(testfile);

    // Nu åbner vi filen igen og tjekker resultatet
    testfile = fopen("test_output.txt", "r");

    double Imax;
    fscanf(testfile, "%lf", &Imax);

    fclose(testfile);

    CuAssertTrue(tc, Imax < 0.2); // fx forventet lav smittetop
}

CuSuite *vaccine_udrulning_suite(void)
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, vaccine_effekt_1);

    return suite;
}

/*
// testcase 2 af vaccine funktion (ingen er vaccinerede)
void vaccine_effekt_2(CuTest *tc)
{
    FILE *testfile = fopen("test_output.txt", "w");

    simulerEpidemi(
        1, // SEIR
        0, // ingen app

        0, // ingen vaccine
        1, // inputfil 1
        testfile,
        1, // 1 simulering
        0, // deterministisk
        0  // ingen terminalprint
    );

    fclose(testfile);

    // Nu åbner vi filen igen og tjekker resultatet
    testfile = fopen("test_output.txt", "r");

    double Imax;
    fscanf(testfile, "%lf", &Imax);

    fclose(testfile);

    CuAssertTrue(tc, Imax > 0.2); // fx forventet høj smittetop
}

// testsuite af testcases af vaccineeffekt


// testcases af migrations effekt  ( lukket grænse = 0) (1 by uden smittede, får overførst smitte fra anden by)

// testsuite af testcases af migrations effekt

// testcases af Smitte|Stop effekt

// testsuites af Smitte|Stop effekt

// testcases af stokastisk simulering uden vaccine og app

// testsuites af test af stokastisk simulering

*/