#include <stdio.h>
#include <string.h>

void quantize(char *data, float *src, int nb_src, int vsize)
{
    unsigned char  i8[4];

    switch(vsize)
    {
  case 4: i8[3] = (unsigned char)src[3];
  case 3: i8[2] = (unsigned char)src[2];
    i8[1] = (unsigned char)src[1];
  case 1: i8[0] = (unsigned char)src[0];
    }
    ::memcpy(data, i8, vsize*sizeof(unsigned char));
}

int main()
{
    float   b[4] = {1,1,1,1};
    unsigned char i8[4] = {0,0,0,0};

    quantize((char *)i8, b, 4, 4);

    printf("%d %d %d %d\n", i8[0], i8[1], i8[2], i8[3]);
    return 0;
}

