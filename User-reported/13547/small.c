#include <stdio.h>
#include <string.h>

int
main(void)
{
        char buf[1024], *c;
        int i;

        for (i = 0; i < 100; i++)
                buf[i] = '/';
        buf[i] = '\0';

        c = strdup(buf);
        printf("%s\n", c);

        return (0);
}
