/* (C) Nguyễn Bá Ngọc */

#include <stdio.h>

#include "c-cpp/vncmp.h"

int main() {
  printf("# (C) Nguyễn Bá Ngọc 2023\n\n");
  printf("import array\n\n");
  printf("vn_map = array.array('i',\n  [");
  for (int i = 0; i < k_vn_map_len; ++i) {
    printf("0X%.4X", k_vn_map[i]);
    if (i < k_vn_map_len - 1) {
      printf(", ");
    }
    if (i % 16 == 15 && i != k_vn_map_len -1) {
      printf("\n    ");
    }
  }
  printf("])\n\n");

  printf("def vnchmap(c):\n");
  printf("  if ord(c) >= len(vn_map):\n");
  printf("    return ord(c)\n");
  printf("  return vn_map[ord(c)]\n\n");

  printf("def wchcmp(c1, c2):\n");
  printf("  if c1 == c2:\n");
  printf("    return 0;\n");
  printf("  return -1 if vnchmap(c1) < vnchmap(c2) else 1\n\n");

  printf("def wscmp(s1, s2):\n");
  printf("  for i in range(len(s1)):\n");
  printf("    if i >= len(s2):\n");
  printf("      return 1\n");
  printf("    if s1[i] == s2[i]:\n");
  printf("      continue\n");
  printf("    if vnchmap(s1[i]) > vnchmap(s2[i]):\n");
  printf("      return 1\n");
  printf("    elif vnchmap(s1[i]) < vnchmap(s2[i]):\n");
  printf("      return -1\n");
  printf("  if len(s1) < len(s2):\n");
  printf("    return -1;\n");
  printf("  return 0\n");
}