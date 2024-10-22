extern "C" void printf(...);

int a = 0;
int d = 0;
float c = 1.f / (1 << 16);
float k[1000];
float m[1000];
float *l = k;

void fn1(float *p1, float *p2, unsigned p3) {
  int e = d;
  int f = d & (1 << 16) - 1;
  int g = (1 << 16) / p3;
  float *h = p1 + 190;
  float *j = p2 + 512;
  while (g--) {
    *j = f;
    ++j;
    e += p3;
    a = e >> 16;
    f = e & (1 << 16) - 1;
  }

  *j = h[a] + f * c;
}

#pragma clang optimize off
int main() {
  float *n = m;
  for (int i = 0; i < 521; i++)
    l[i] = i;
  fn1(k, m, 8192);
  printf("outBuf[520]: %f\n", n[520]);
}

