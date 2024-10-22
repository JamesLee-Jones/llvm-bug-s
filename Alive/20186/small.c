int printf (const char *, ...);

int a, b;
long c;

void func_37 () {
  --c;
  a = 0 || c;
}

int main ()
{
  func_37 ();
  printf ("%ld\n", c);
}

