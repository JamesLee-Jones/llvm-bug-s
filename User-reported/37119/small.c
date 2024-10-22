#include <stdio.h>
#include <math.h>

typedef signed int sint;
typedef signed char schar;
typedef unsigned char uchar;
typedef sint __attribute__((ext_vector_type(4))) sint4;
typedef schar __attribute__((ext_vector_type(16))) schar16;
typedef char __attribute__((ext_vector_type(16))) char16;
typedef union { char16 a; schar16 b; } union_char16_schar16;
typedef union { schar16 a; char16 b; } union_schar16_char16;
typedef union { sint4 a; char16 b; } union_sint4_char16;
typedef union { char16 a; char16 b; } union_char16_char16;
typedef double __attribute__((ext_vector_type(8))) double8;
typedef double __attribute__((ext_vector_type(2))) double2;
typedef double __attribute__((ext_vector_type(4))) double4;

template <typename T, typename BASE>
static T protect_num(T in, int elems) {
  for (unsigned i = 0; i < elems; ++i)
    if ((BASE)(in[i] - 1) > (BASE)in[i])
      in[i] += 1;
  return in;
}

template <typename T> static T protect_den(T in, int elems) {
  for (unsigned i = 0; i < elems; ++i)
    if (fabs(in[i]) == 0)
      in[i] = 1;
  return in;
}

static void init(unsigned char pred, volatile void *data, unsigned size) {
  unsigned char *bytes = (unsigned char *)data;
  for (unsigned i = 0; i != size; ++i) {
    bytes[i] = pred + i;
  }
}

void test52() {
  volatile short id11099 = (short)-45550641;
  short id11101;
  init(251, &id11101, sizeof(id11101));
  volatile short id11100 = (static_cast<short>(id11101));
  bool id11098 = ((bool)(id11099 >= id11100));
  volatile double8 id11103 = (double8){
      (double)-1.84364787251, (double)258.198540855, (double)215.868825393,
      (double)-196.634372521, (double)-0.0885134222205, (double)0.938453842222,
      (double)-0.414173708769, (double)-414.216134403};
  double8 id11102 = (__builtin_convertvector(id11103, double8));
  volatile double2 id11106 =
      (double2){(double)-0.40470588901, (double)-0.750401724282};
  for (uchar id11107_idx = 0; (id11107_idx < 153); ++id11107_idx) {
    double2 id11108 =
        (double2){(double)-0.482156643169, (double)-0.216218999868};
    id11106 += id11108;
  }
  double4 id11105 = __builtin_shufflevector(id11106, id11106, 3, 2, 3, 3);
  double8 id11104 =
      __builtin_shufflevector(id11105, id11105, 4, 4, 1, 6, 2, 0, 4, 1);
  static double8 id11097 = ((id11098) ? id11102 : id11104);
  volatile double4 id11096 = (id11097.wzyw);
  double4 id11095 = (id11096.wxzx);
  if (isnan(id11095[0]) || isinf(id11095[0]))
    id11095[0] = 0.0;
  if (isnan(id11095[1]) || isinf(id11095[1]))
    id11095[1] = 0.0;
  if (isnan(id11095[2]) || isinf(id11095[2]))
    id11095[2] = 0.0;
  if (isnan(id11095[3]) || isinf(id11095[3]))
    id11095[3] = 0.0;
  printf("id11095:%lf %lf %lf %lf\n", id11095[0], id11095[1], id11095[2],
         id11095[3]);
}
# 148 "repro2.cpp"
void test54() {
  volatile union_char16_schar16 id11517;
  id11517.a = (char16){(char)1158378631, (char)-1484207745, (char)1482565034,
                       (char)-2097611821, (char)-1274151244, (char)2147483647,
                       (char)-2063407885, (char)876859056, (char)1681923009,
                       (char)-334607626, (char)-1818312796, (char)1062782177,
                       (char)-494970455, (char)-662616453, (char)-1848642622,
                       (char)532945914};
  volatile char16 id11518 =
      (char16){(char)2147483648, (char)-171560550, (char)790433240,
               (char)-1646006744, (char)-932766572, (char)94653733,
               (char)-1690724508, (char)1471313218, (char)1374984411,
               (char)391200456, (char)-326868037, (char)770615476,
               (char)-973930104, (char)-1556350036, (char)2097152,
               (char)613123375};
  volatile char16 id11516 = (((id11517.a = id11518), id11517.a));
  char16 id11515 = (id11516 >> 6);
  char16 id11520 =
      (char16){(char)1046856695, (char)1336660117, (char)997122568,
               (char)-1933657151, (char)-909512802, (char)1259990016,
               (char)-1671905253, (char)1721742487, (char)-539761976,
               (char)1402401860, (char)-1146393014, (char)-535022724,
               (char)801336865, (char)-604314593, (char)-1063401425,
               (char)344363587};
  union_schar16_char16 id11522;
  id11522.b = (char16){(char)999154229, (char)1843837931, (char)-25248785,
                       (char)881970553, (char)-12465844, (char)574361743,
                       (char)493374725, (char)1206970572, (char)-866909670,
                       (char)1677657872, (char)-1967268995, (char)-1025291330,
                       (char)-1231633162, (char)-888928768, (char)271859817,
                       (char)1404448438};
  union_sint4_char16 id11525;
  id11525.b = (char16){(char)1600085295, (char)1302461699, (char)1836408340,
                       (char)-232312909, (char)-459052645, (char)859799064,
                       (char)-58002511, (char)1384151236, (char)-177414095,
                       (char)1015475428, (char)67108868, (char)607428127,
                       (char)1507324071, (char)-945359960, (char)-380680690,
                       (char)-982312303};
  char16 id11524 = ((id11525.b));
  char16 id11526 =
      (char16){(char)-1765376525, (char)1316240176, (char)-972268381,
               (char)1269722717, (char)1371934788, (char)1780876833,
               (char)-2046982968, (char)-264550747, (char)2060767912,
               (char)2147483644, (char)-1943325152, (char)-1591293773,
               (char)847763394, (char)608407243, (char)-1798146597,
               (char)1979430069};
  char16 id11523 = ((char16)(id11524 != id11526));
  char16 id11521 = (((id11522.b = id11523), id11522.b));
  char16 id11519 = ((char16)(id11520 <= id11521));
  volatile char16 id11514 = ((char16)((protect_num<char16, char>(id11515, 16) / protect_den(id11519, 16))));
  __attribute__((aligned(32))) union_char16_char16 id11528;
  id11528.b = (char16){(char)656268485, (char)1868419114, (char)-876037910,
                       (char)-1899997920, (char)1980118658, (char)652568678,
                       (char)1865754924, (char)-1533975282, (char)-1793797351,
                       (char)1329430228, (char)-1199491171, (char)-999666011,
                       (char)-982349747, (char)90271323, (char)264349355,
                       (char)-144450398};
  char16 id11527 = ((id11528.a));
  volatile __attribute__((aligned(32))) char16 id11513 =
      ((char16)(id11514 < id11527));
  printf("id11513:%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n",
         id11513[0], id11513[1], id11513[2], id11513[3], id11513[4], id11513[5],
         id11513[6], id11513[7], id11513[8], id11513[9], id11513[10],
         id11513[11], id11513[12], id11513[13], id11513[14], id11513[15]);
}


int main() {
  printf("{BEGIN}\n");
  test52();
  test54();
  printf("{END}\n");
}

