/* (C) Nguyễn Bá Ngọc 2023 */

#include "vncmp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"

#include "k_vn_characters.ic"
#include "k_vn_map.ic"

int vnwchcmp(wchar_t ch1, wchar_t ch2) {
  return VNCHMAP(ch1) - VNCHMAP(ch2);
}

int vnwscmp(const wchar_t *s1, const wchar_t *s2) {
  wchar_t ch1, ch2;
  for (;;) {
    ch1 = *s1;
    ch2 = *s2;
    if (ch1 == 0 || ch2 == 0) {
      break;
    }
    if (ch1 == ch2) {
      ++s1;
      ++s2;
      continue;
    }
    break;
  }
  return VNCHMAP(ch1) - VNCHMAP(ch2);
}

int vnu8scmp(const char *s1, const char *s2) {
  wchar_t ch1, ch2;
  for (;;) {
    s1 += u82wc(&ch1, s1);
    s2 += u82wc(&ch2, s2);
    if (ch1 == 0 || ch2 == 0) {
      break;
    }
    if (ch1 == ch2) {
      continue;
    }
    break;
  }
  return VNCHMAP(ch1) - VNCHMAP(ch2);
}
