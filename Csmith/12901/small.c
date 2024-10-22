int printf (const char *, ...);
int a, b = 1, c, e, f, h, i, j;
int *d = &c, *g = &c;

void fn1 (int *p1)
{
    *p1 = *d;
}

void fn2 (int *p1)
{
    f = *p1;
    *g = f;
}

int main ()
{
    int *k = &b, *l = &b;
    h = 1;
    for (; h; h--)
        for (; j <= 0; j++)
        {
            int **m = &l;
            for (; i <= 0; i++)
                *l = 0;
            *k ^= 1;
            *m = 0;
        }
    e = b;
    fn2 (&e);
    fn1 (&a);
    printf ("%d\n", a);
    return 0;
}

