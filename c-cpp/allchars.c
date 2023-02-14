#include <stdio.h>

#include "vnwscmp.h"
#include "utf8.h"

int main() {
  char buff[1000];
  ws2u8(buff, k_vn_characters);
  size_t len = wcslen(k_vn_characters);
  printf("%zu\n%s\n", len, buff);
  for (int i = 0; i < len -1; ++i) {
    printf("%d ", vnwchcmp(k_vn_characters[i], k_vn_characters[i + 1]));
  }
  printf("\n");
  for (int i = 0; i < len -1; ++i) {
    printf("%d ", vnwchcmp(k_vn_characters[i + 1], k_vn_characters[i]));
  }
  printf("\n");
}