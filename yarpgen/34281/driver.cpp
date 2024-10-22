#include <stdio.h>
extern const signed char var_11;
extern const unsigned int var_21;
extern const signed char var_29;
extern signed char var_370;
extern unsigned int var_390;

const signed char var_11 = 97;
const unsigned int var_21 = 3536697529U;
const signed char var_29 = 20;
signed char var_370 = 16;
unsigned int var_390 = 1082014357U;

extern void foo ();

int main () {
    foo ();
    printf("%llu\n", var_390);
    return 0;
}
