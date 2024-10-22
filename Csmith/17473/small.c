int printf(const char *, ...);
int a, c, d, e, f, g, i, j;
short b;
char h;

int fn1(void) 
{ 
  return b && a > b || b < 0 && a ?: b; 
}

void fn2(void) {
  for (;; f = fn1())
    ;
}

void fn3(int p1) {
  j &&(c = 0 ?: 0);
  g = p1;
}

int main(void) {
  for (h = 0; h >= 0; ++h) {
    fn3(h);
    i = d >= 0 ?: 0;
  }
  e = g;
  e += h;
  printf("%x\n", e);
  return 0;
}

