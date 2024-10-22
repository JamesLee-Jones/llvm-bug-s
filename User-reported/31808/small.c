extern "C" {
int printf(const char *, ...);
void *malloc(unsigned long);
void *memcpy(void *, const void *, unsigned long);
}

struct Array {
  unsigned char *m_ArrayData;
  unsigned int m_ReservedSize;
  unsigned int m_Size;

  Array() : m_ArrayData(), m_ReservedSize(0), m_Size(0) {}

  int **End() { return (int **)(m_ArrayData + m_Size * sizeof(int *)); }

  void Reserve(unsigned int newReservedSize) {
    if (m_ReservedSize < newReservedSize) {
      void *newData = malloc(newReservedSize * sizeof(int *));
      if (m_Size) {
        memcpy(newData, m_ArrayData, sizeof(int *) * m_Size);
      }
      m_ArrayData = (unsigned char *)newData;
    }
  }

  void Add() {
    if (m_Size + 1 > m_ReservedSize) {
      Reserve((m_Size * 3 / 2) + 8);
    }

    unsigned int newSize = m_Size + 1;
    m_Size = newSize;

    int *it = (int *)m_ArrayData + newSize - 1;
    *it = 1;
  }
};

struct LoopIter {
  LoopIter(Array &from) : m_Curr((int **)from.m_ArrayData), m_End(from.End()) {}

  operator int **() { return m_Curr; }

  int **m_Curr;
  int **m_End;
};

struct SomeStruct {
  Array m_SomeStruct;

  void AddSomeStruct() { m_SomeStruct.Add(); }
  __attribute__((noinline)) void CheckOne() {
    LoopIter it(m_SomeStruct);
    bool match = (it + 1) == it.m_End;
    printf("%p %p {%s}\n", it + 1, it.m_End, (match ? "PASS" : "FAIL"));
  }
};

int main() {
  printf("{{BEGIN}}\n");
  SomeStruct var;
  var.AddSomeStruct();
  var.CheckOne();
  printf("{{END}}\n");

  return 0;
}

