/* (C) Nguyễn Bá Ngọc 2023 */

#include "vncmp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"

#include "k_vn_characters.ic"
#include "k_vn_map.ic"

int vnwchcmp(wchar_t ch1, wchar_t ch2) {
  if (ch1 == ch2) {
    return 0;
  }
  return VNCHMAP(ch1) < VNCHMAP(ch2)? -1: 1;
}

int vnwscmp(const wchar_t *s1, const wchar_t *s2) {
  while (*s1 == *s2) {
    if (*s1 == 0) {
      return 0;
    }
    ++s1;
    ++s2;
  }
  return VNCHMAP(*s1) < VNCHMAP(*s2)? -1: 1;
}

int vnu8scmp(const char *s1, const char *s2) {
  wchar_t ch1, ch2;
  while (s1 += u82wch(&ch1, s1),
         s2 += u82wch(&ch2, s2),
         ch1 == ch2) {
    if (ch1 == 0) {
      return 0;
    }
  }
  return VNCHMAP(ch1) < VNCHMAP(ch2)? -1: 1;;
}
