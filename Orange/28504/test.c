int main (void)
{
  signed char c = 1;
  int i = (short) (signed char) ( c - (unsigned char) c + (c==1) ) ;
  short s = c;

  if (i != 1) __builtin_abort();

  return 0;
}
