#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "testlib.h"

/** \fn test_create
 * This preprare object to being test.
 * @*test Test to work on
 */
void test_create(test_t *test) {
    test->name = "Sample test";
    test->size = 0x00;
    test->test_units = malloc(0x00);
}

/** \fn test_unit_add
 * This add new test unit to test. Test unit is function which return bool,
 * true when test has been passed, and false when not.
 * @*test Test to work on
 * @*name Test unit name
 * @*(unit)(void *) Unit of test
 * @*param Param to unit
 */
void test_unit_add(
    test_t *test,
    char *name,
    int (*unit)(void *),
    void *param
) {
    ++test->size;

    test->test_units = realloc(
        test->test_units, 
        test->size * sizeof(test_unit_t)
    );

    test_unit_t *current = test->test_units + test->size - 1;

    current->name = name;
    current->unit = unit;
    current->param = param;
}

/** \fn test_unit_run 
 * This run test unit, print messages into stdout. When test has not been 
 * passed press user to type Y or N. When pass Y, then test skip this test
 * unit and goes on, if type N, then test has been stoped with error code.
 * @*test Test to run
 */
static inline bool test_unit_run(test_unit_t *test) {
    printf("Test unit \"%s\"...", test->name);
   
    int result = test->unit(test->param);

    if (result) {
        printf("NOT WORK, result: %i!!!\n", result);

        while (true) {
            printf("Click 'Y' to run next test, or 'N' to close tests: ");

            char choice = getchar();

            if (choice == 'Y' || choice == 'y') return true;
            if (choice == 'N' || choice == 'n') return false;

            printf("\n");
        }
    }

    printf("work\n");

    return true;
}

/** \fn test_run
 * This create test, load unit from user file, next run all test units, when
 * all went well, return 0, if not then return -1.
 * @*test Test to run
 */
int test_run(test_t *test) {
    printf("Starting test %s...\n", test->name);

    for (int count = 0x00; count < test->size; ++count) {
        if (!test_unit_run(test->test_units + count)) return -1;
    }

    return 0;
}
