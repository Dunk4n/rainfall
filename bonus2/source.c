#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

int language;

void greetuser(char user[])
    {
    char  hello[19];

    if (language == 1)
        {
        hello = "Hyvää päivää ";
        }
    else if (language == 2)
        {
        hello = "Goedemiddag! ";
        }
    else if (language == 0)
        {
        hello = "Hello ";
        }

    strcat(hello, user);
    puts(hello);
    return;
    }

int main(int argc, char **argv)
    {
    int   uVar1;
    int   iVar2;
    char *puVar3;
    char *puVar4;
    char  bVar5;
    int   local_60[10];
    char  acStack56[36];
    char *local_14;

    bVar5 = 0;
    if (argc == 3)
        {
        puVar3 = local_60;
        for (iVar2 = 19; iVar2 != 0; iVar2--)
            {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
            }

        strncpy((char *)local_60, argv[1], 40);

        strncpy(acStack56, argv[2], 32);

        local_14 = getenv("LANG");
        if (local_14 != NULL)
            {
            iVar2 = memcmp(local_14, "fi", 2);

            if (iVar2 == 0)
                {
                language = 1;
                }
            else
                {
                iVar2 = memcmp(local_14, "nl", 2);
                if (iVar2 == 0)
                    {
                    language = 2;
                    }
                }
            }

        puVar3 = local_60;
        puVar4 = acStack56;
        for (iVar2 = 19; iVar2 != 0; iVar2--)
            {
            *puVar4 = *puVar3;
            puVar3 = puVar3++;
            puVar4 = puVar4++;
            }

        uVar1 = greetuser();
        }
    else
        {
        uVar1 = 1;
        }

    return uVar1;
    }
