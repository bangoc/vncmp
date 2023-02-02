/* (C) Nguyễn Bá Ngọc 2023 */

#include "vncmp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"

const wchar_t k_vn_characters[] = {
/* Chữ hoa */
  VN_UP_A  , VN_UP_AF , VN_UP_AX , VN_UP_AR , VN_UP_AS , VN_UP_AJ ,
  VN_UP_AW , VN_UP_AWF, VN_UP_AWX, VN_UP_AWR, VN_UP_AWS, VN_UP_AWJ,
  VN_UP_AA , VN_UP_AAF, VN_UP_AAX, VN_UP_AAR, VN_UP_AAS, VN_UP_AAJ,
  VN_UP_D, VN_UP_DD ,
  VN_UP_E  , VN_UP_EF , VN_UP_EX , VN_UP_ER , VN_UP_ES , VN_UP_EJ ,
  VN_UP_EE , VN_UP_EEF, VN_UP_EEX, VN_UP_EER, VN_UP_EES, VN_UP_EEJ,
  VN_UP_I  , VN_UP_IF , VN_UP_IX , VN_UP_IR , VN_UP_IS , VN_UP_IJ ,
  VN_UP_O  , VN_UP_OF , VN_UP_OX , VN_UP_OR , VN_UP_OS , VN_UP_OJ ,
  VN_UP_OO , VN_UP_OOF, VN_UP_OOX, VN_UP_OOR, VN_UP_OOS, VN_UP_OOJ,
  VN_UP_OW , VN_UP_OWF, VN_UP_OWX, VN_UP_OWR, VN_UP_OWS, VN_UP_OWJ,
  VN_UP_U  , VN_UP_UF , VN_UP_UX , VN_UP_UR , VN_UP_US , VN_UP_UJ ,
  VN_UP_UW , VN_UP_UWF, VN_UP_UWX, VN_UP_UWR, VN_UP_UWS, VN_UP_UWJ,
  VN_UP_Y  , VN_UP_YF , VN_UP_YX , VN_UP_YR , VN_UP_YS , VN_UP_YJ ,

/* Chữ thường */
  VN_LO_A  , VN_LO_AF , VN_LO_AX , VN_LO_AR , VN_LO_AS , VN_LO_AJ ,
  VN_LO_AW , VN_LO_AWF, VN_LO_AWX, VN_LO_AWR, VN_LO_AWS, VN_LO_AWJ,
  VN_LO_AA , VN_LO_AAF, VN_LO_AAX, VN_LO_AAR, VN_LO_AAS, VN_LO_AAJ,
  VN_LO_D, VN_LO_DD ,
  VN_LO_E  , VN_LO_EF , VN_LO_EX , VN_LO_ER , VN_LO_ES , VN_LO_EJ ,
  VN_LO_EE , VN_LO_EEF, VN_LO_EEX, VN_LO_EER, VN_LO_EES, VN_LO_EEJ,
  VN_LO_I  , VN_LO_IF , VN_LO_IX , VN_LO_IR , VN_LO_IS , VN_LO_IJ ,
  VN_LO_O  , VN_LO_OF , VN_LO_OX , VN_LO_OR , VN_LO_OS , VN_LO_OJ ,
  VN_LO_OO , VN_LO_OOF, VN_LO_OOX, VN_LO_OOR, VN_LO_OOS, VN_LO_OOJ,
  VN_LO_OW , VN_LO_OWF, VN_LO_OWX, VN_LO_OWR, VN_LO_OWS, VN_LO_OWJ,
  VN_LO_U  , VN_LO_UF , VN_LO_UX , VN_LO_UR , VN_LO_US , VN_LO_UJ ,
  VN_LO_UW , VN_LO_UWF, VN_LO_UWX, VN_LO_UWR, VN_LO_UWS, VN_LO_UWJ,
  VN_LO_Y  , VN_LO_YF , VN_LO_YX , VN_LO_YR , VN_LO_YS , VN_LO_YJ ,
  0
};

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
