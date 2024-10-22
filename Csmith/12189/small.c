int printf (const char *, ...);

short a;
int b, d, k, l, m;

int fn1 (short p1, int p2) {
  return p1 - p2;
}

int fn2 (short p1) {
  return p1 == 0 || a == 0 ? a : a % p1;
}

int fn3 (int p1, unsigned short p2) {
  return p2 == 0 ? 0 : p1 % p2;
}

void fn4 (unsigned char p1) {
  if (p1)
    b = 1;
}

void fn5 (p1) {
  short n = 60018;
  k = fn2 (p1);
  d = k != 0;
  l = fn1 (d, n);
  m = fn3 (l, p1);
  fn4 (m);
}

int main () {
  fn5 (2);
  printf ("%d\n", b);
  return 0;
}

