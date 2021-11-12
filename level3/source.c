#include <stdio.h>
#include <stdlib.h>

int m;

void v(void)
    {
    char local_20c[520];

    fgets(local_20c, 512, stdin);
    printf(local_20c);
    if (m == 0x40) {
        fwrite("Wait what?!\n", 1, 0xc, stdout);
        system("/bin/sh");
    }
    return;
    }

void main(void)
    {
    v();
    return;
    }
