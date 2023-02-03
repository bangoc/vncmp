#include <stdio.h>

#include "vncmp.h"

int main() {
  printf("%d\n", vnwchcmp(L'\xAB', L'\xAD'));
  printf("%d\n", vnwchcmp(L'\xAD', L'\xAB'));
  printf("%d\n", vnwchcmp(L'\xAB', L'\xAB'));
  printf("%d\n", vnwchcmp(L'\xFFFFFFFF', L'\x01'));
}