
int main (void)
{
  int a = 0;
  unsigned long c = ((1LU & (1 | (0 < a))) % 1 + 0xffffffffffffffffLU);
  double t = c % 2;
  if (t != 1.0) __builtin_abort();
  return 0;
}
