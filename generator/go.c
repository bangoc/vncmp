#include <stdio.h>

#include "c-cpp/vncmp.h"

int main() {
  printf("// (C) Nguyễn Bá Ngọc 2023\n");
  printf("package vncmp\n\n");
  printf("var vn_map = [...]int {\n  ");
  for (int i = 0; i < k_vn_map_len; ++i) {
    printf("0X%.4X", k_vn_map[i]);
    if (i < k_vn_map_len - 1) {
      printf(", ");
    }
    if (i % 16 == 15 && i < k_vn_map_len) {
      printf("\n  ");
    }
  }
  printf("}\n\n");

  printf("var vn_map_len = len(vn_map)\n\n");
}