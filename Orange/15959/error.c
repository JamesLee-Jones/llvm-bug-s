int main (void)
{
  volatile short x = 1;
  static long k = 1L;
  int a = x << ( k - 1 );   // a = 1
  long t = 1L >> a ;        // t = 0
  if ( t != 0L ) { __builtin_abort(); }
  return 0;
}
