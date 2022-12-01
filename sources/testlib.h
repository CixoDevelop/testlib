#ifndef HEADER_TESTLIB_H_INCLUDED
#define HEADER_TESTLIB_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/** \struct test_unit_t
 * This struct store single test unit.
 */
typedef struct {

    /* Name of test unit */
    char *name;

    /* Unit test to run */
    int (*unit)(void *);

    /* Param to pass into test unit */
    void *param;

} test_unit_t;

/** \struct test_t
 * This struct store table of test unit to run in test.
 */
typedef struct {
    
    /* Test units array */
    test_unit_t *test_units;

    /* Name of test */
    char *name;

    /* Test unit array size */
    int size;

} test_t;

/** \fn test_create
 * This create single test.
 * @*test Test to work on
 */
void test_create(test_t *test);

/** \fn test_unit_add
 * This add one unit from params into test.
 * @*test Test to work on
 * @*name Name of test unit
 * @(*unit)(void *) Test unit function
 * @*param Param to test
 */
void test_unit_add(
    test_t *test, 
    char *name, 
    int (*unit)(void *), 
    void *param
);

/** \fn test_run
 * This create test, load unit from user file, next run all test units, when
 * all went well, return 0, if not then return -1.
 * @*test Test to run
 */
int test_run(test_t *test);

#endif
