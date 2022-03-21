/**
 * C program to get minimum and maximum range of a type using C library constants
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char 0 to %d\n\n", UCHAR_MAX);

    printf("Range of signed short int %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int 0 to %d\n\n", USHRT_MAX);

    printf("Range of signed int %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int 0 to %u\n\n", UINT_MAX);

    printf("Range of signed long int %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int 0 to %lu\n\n", ULONG_MAX);

    printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of long double %e to %e\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
