#include "types.h"
// #include "stat.h"
#include "user.h"
int main()
{
    printf(0, "total system calls so far = %d\n", trace(1));
    printf(0, "total system calls so far = %d\n", trace(0));
    printf(0, "total system calls so far = %d\n", trace(0));
    printf(0, "total system calls so far = %d\n", trace(1));
    printf(0, "total system calls so far = %d\n", trace(0));
    return 0;
}