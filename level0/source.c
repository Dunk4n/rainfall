#define _GNU_SOURCE         /* See feature_test_macros(7) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
    {
    int     iVar1;
    char   *tab[2];
    __uid_t local_18;
    __gid_t local_14;

    iVar1 = atoi(argv[1]);
    if (iVar1 == 423)
        {
        tab[0] = strdup("/bin/sh");
        tab[1] = 0;
        local_14 = getegid();
        local_18 = geteuid();
        setresgid(local_14, local_14, local_14);
        setresuid(local_18, local_18, local_18);
        execv("/bin/sh", tab);
        }
    else
        {
        fwrite("No !\n", 1, 5, (FILE *)stderr);
        }
    return 0;
    }
