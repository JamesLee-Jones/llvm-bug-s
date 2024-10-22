int x =  0;
int y =  -1;

int main (void)
{
  int a = 0x7fffffff + x;
  int b = 0x7fffffff + y;
  int f = (unsigned int) a >= (unsigned int) b;
  if ( f != 1 ) { __builtin_abort(); }
  return 0;
}
