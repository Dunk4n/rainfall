#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
    {
    int   uVar1;
    int   iVar2;
    int  *puVar3;
    char  bVar4;
    int   local_98[16];
    char  local_57;
    char  local_56[66];
    FILE *local_14;

    bVar4 = 0;
    local_14 = fopen("/home/user/end/.pass", "r");

    puVar3 = local_98;
    for (iVar2 = 33; iVar2 != 0; iVar2--)
        {
        *puVar3 = 0;
        puVar3 = puVar3++;
        }

    if ((local_14 == NULL) || (argc != 2))
        {
        uVar1 = 0xffffffff;
        }
    else
        {
        fread(local_98, 1, 66, local_14);
        local_57 = 0;
        iVar2 = atoi(argv[1]);
        *(char *)((int)local_98 + iVar2) = 0;
        fread(local_56, 1, 66, local_14);
        fclose(local_14);

        iVar2 = strcmp((char *)local_98, argv[1]);
        if (iVar2 == 0)
            {
            execl("/bin/sh","sh", NULL);
            }
        else
            {
            puts(local_56);
            }
        uVar1 = 0;
        }
    return uVar1;
    }
