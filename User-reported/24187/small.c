#include <tmmintrin.h>

int main()
{   
    alignas(16) int m[4];
    *reinterpret_cast<__m128i*>(m) = _mm_alignr_epi8((__v4si{4, 5, 6, 7}),
                                                     (__v4si{0, 1, 2, 3}), 20);
    if (m[0] != 5) {
        abort();
    }
    return 0;
}
