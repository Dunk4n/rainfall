#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void p(void)
    {
    void *unaff_retaddr;
    char local_50[76];

    fflush(stdout);
    gets(local_50);
    if (((uint) unaff_retaddr & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", unaff_retaddr);
        _exit(1);
    }
    puts(local_50);
    strdup(local_50);
    return;
    }

int main(void)
    {
    p();
    return (0);
    }
