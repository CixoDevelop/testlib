# TestLib

## This simple lib can be used to test functions in project

### User Manual
 * Build this lib: go to build dir and exec ./build.sh. This will build 
   libtestlib.a
 * Add headers dir to compiler command line: 
    -Iyour-libs-dir/testlib/headers
 * Add lib archive to compiler command line: 
    -Lyour-libs-dir/testlib/build -ltestlib
 * Create file for test script: 
    touch test.c
 * Add testlib header: 
    #include <testlib.h>
 * In main function add: 
    test_t *test = malloc(sizeof(test_t));
 * Then add: 
    test_create(test);
 * Add test name: 
    test->name = "name";
 * Next add all you tests: 
    test_unit_add(test, "name", function, *param);
 * On end add: 
    return test_run(test);

### How to write test unit function
 * Function will return int, zero if all goes well, other number if 
   something went wrong. If something went wrong, this will print
   this numer on screen and wait for user interaction.
 * Function will get void *param from testlib. This is same pointer
   that had been passed on creating unit test. 
