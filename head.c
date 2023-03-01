#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void head(int fd, char *name)
{
    int i, n;
    int l;

    l = 0;
    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            printf(1, "%c", buf[i]);
            if (buf[i] == '\n')
                l++;
            if (l == 10)
                exit();
        }
    }
    if (n < 0)
    {
        printf(1, "wc: read error\n");
        exit();
    }
}

int main(int argc, char *argv[])
{
    int fd, i;

    if (argc <= 1)
    {
        head(0, "");
        exit();
    }

    for (i = 1; i < argc; i++)
    {
        if ((fd = open(argv[i], 0)) < 0)
        {
            printf(1, "head: cannot open %s\n", argv[i]);
            exit();
        }
        head(fd, argv[i]);
        close(fd);
    }
    exit();
}
