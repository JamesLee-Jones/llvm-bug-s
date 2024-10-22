int printf (const char *, ...);

#pragma pack(1)
struct S1
{
  int f0;
  char f1;
  short f2;
} g_43 = { }, g_123, g_1126;

int fn1 (struct S1 p1)
{
  g_123.f0 = 0;
  return 0;
}

void fn2 (void)
{
  struct S1 l_1445;
  g_1126 = l_1445 = g_43;
}

int g_474;

int main (void)
{
  struct S1 l_38;
  l_38 = g_43;
  fn1 (g_43);
  g_474 = l_38.f0;
  l_38.f2 || fn1 (g_123);
  for (g_43.f1 = 1; ; g_43.f1++)
    break;
  fn2 ();
  printf ("%d\n", g_1126.f1);
}

