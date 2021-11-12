#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void n(void)
    {
    system("/bin/cat /home/user/level7/.pass");
    return;
    }

void m(void *param_1,int param_2,char *param_3,int param_4,int param_5)
    {
    puts("Nope");
    return;
    }

typedef void (*func_ptr)(void);

void main(int argc, char **argv)
    {
    char *buff;
    func_ptr *func;

    buff = (char *)malloc(64);
    func = malloc(4);
    *func = &m;
    strcpy(buff, argv[1]);
    (*func)();
    return;
    }
