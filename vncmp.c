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

enum vn_all_up_a {
  VN_UP_A_POS  , VN_UP_AF_POS , VN_UP_AX_POS , VN_UP_AR_POS , VN_UP_AS_POS , VN_UP_AJ_POS ,
  VN_UP_AW_POS , VN_UP_AWF_POS, VN_UP_AWX_POS, VN_UP_AWR_POS, VN_UP_AWS_POS, VN_UP_AWJ_POS,
  VN_UP_AA_POS , VN_UP_AAF_POS, VN_UP_AAX_POS, VN_UP_AAR_POS, VN_UP_AAS_POS, VN_UP_AAJ_POS,
  VN_UP_A_ALL
};

enum vn_all_up_d {
  VN_UP_D_POS, VN_UP_DD_POS,
  VN_UP_D_ALL
};

enum vn_all_up_e {
  VN_UP_E_POS  , VN_UP_EF_POS , VN_UP_EX_POS , VN_UP_ER_POS , VN_UP_ES_POS , VN_UP_EJ_POS ,
  VN_UP_EE_POS , VN_UP_EEF_POS, VN_UP_EEX_POS, VN_UP_EER_POS, VN_UP_EES_POS, VN_UP_EEJ_POS,
  VN_UP_E_ALL
};

enum vn_all_up_i {
  VN_UP_I_POS  , VN_UP_IF_POS , VN_UP_IX_POS , VN_UP_IR_POS , VN_UP_IS_POS , VN_UP_IJ_POS,
  VN_UP_I_ALL
};

enum vn_all_up_o {
  VN_UP_O_POS  , VN_UP_OF_POS , VN_UP_OX_POS , VN_UP_OR_POS , VN_UP_OS_POS , VN_UP_OJ_POS ,
  VN_UP_OO_POS , VN_UP_OOF_POS, VN_UP_OOX_POS, VN_UP_OOR_POS, VN_UP_OOS_POS, VN_UP_OOJ_POS,
  VN_UP_OW_POS , VN_UP_OWF_POS, VN_UP_OWX_POS, VN_UP_OWR_POS, VN_UP_OWS_POS, VN_UP_OWJ_POS,
  VN_UP_O_ALL
};

enum vn_all_up_u {
  VN_UP_U_POS  , VN_UP_UF_POS , VN_UP_UX_POS , VN_UP_UR_POS , VN_UP_US_POS , VN_UP_UJ_POS ,
  VN_UP_UW_POS , VN_UP_UWF_POS, VN_UP_UWX_POS, VN_UP_UWR_POS, VN_UP_UWS_POS, VN_UP_UWJ_POS,
  VN_UP_U_ALL
};

enum vn_all_up_y {
  VN_UP_Y_POS  , VN_UP_YF_POS , VN_UP_YX_POS , VN_UP_YR_POS , VN_UP_YS_POS , VN_UP_YJ_POS,
  VN_UP_Y_ALL
};

enum vn_all_lo_a {
  VN_LO_A_POS  , VN_LO_AF_POS , VN_LO_AX_POS , VN_LO_AR_POS , VN_LO_AS_POS , VN_LO_AJ_POS ,
  VN_LO_AW_POS , VN_LO_AWF_POS, VN_LO_AWX_POS, VN_LO_AWR_POS, VN_LO_AWS_POS, VN_LO_AWJ_POS,
  VN_LO_AA_POS , VN_LO_AAF_POS, VN_LO_AAX_POS, VN_LO_AAR_POS, VN_LO_AAS_POS, VN_LO_AAJ_POS,
  VN_LO_A_ALL
};

enum vn_all_lo_d {
  VN_LO_D_POS, VN_LO_DD_POS,
  VN_LO_D_ALL
};

enum vn_all_lo_e {
  VN_LO_E_POS  , VN_LO_EF_POS , VN_LO_EX_POS , VN_LO_ER_POS , VN_LO_ES_POS , VN_LO_EJ_POS ,
  VN_LO_EE_POS , VN_LO_EEF_POS, VN_LO_EEX_POS, VN_LO_EER_POS, VN_LO_EES_POS, VN_LO_EEJ_POS,
  VN_LO_E_ALL
};

enum vn_all_lo_i {
  VN_LO_I_POS  , VN_LO_IF_POS , VN_LO_IX_POS , VN_LO_IR_POS , VN_LO_IS_POS , VN_LO_IJ_POS,
  VN_LO_I_ALL
};

enum vn_all_lo_o {
  VN_LO_O_POS  , VN_LO_OF_POS , VN_LO_OX_POS , VN_LO_OR_POS , VN_LO_OS_POS , VN_LO_OJ_POS ,
  VN_LO_OO_POS , VN_LO_OOF_POS, VN_LO_OOX_POS, VN_LO_OOR_POS, VN_LO_OOS_POS, VN_LO_OOJ_POS,
  VN_LO_OW_POS , VN_LO_OWF_POS, VN_LO_OWX_POS, VN_LO_OWR_POS, VN_LO_OWS_POS, VN_LO_OWJ_POS,
  VN_LO_O_ALL
};

enum vn_all_lo_u {
  VN_LO_U_POS  , VN_LO_UF_POS , VN_LO_UX_POS , VN_LO_UR_POS , VN_LO_US_POS , VN_LO_UJ_POS ,
  VN_LO_UW_POS , VN_LO_UWF_POS, VN_LO_UWX_POS, VN_LO_UWR_POS, VN_LO_UWS_POS, VN_LO_UWJ_POS,
  VN_LO_U_ALL
};

enum vn_all_lo_y {
  VN_LO_Y_POS  , VN_LO_YF_POS , VN_LO_YX_POS , VN_LO_YR_POS , VN_LO_YS_POS , VN_LO_YJ_POS,
  VN_LO_Y_ALL
};

#define VN_MAXCHAR 0x1EFA
wchar_t g_vn_map[VN_MAXCHAR];

#define VNCHMAP(v, c) \
  (v) = (c) >= VN_MAXCHAR ? (c): g_vn_map[(c)]

static char g_vn_map_lazy_init = 1;

#define MAP_VALUE(idx, base, pos) \
  g_vn_map[(idx)] = g_vn_map[base] + (pos)

static void check_permutation(void) {
  char mark[VN_MAXCHAR] = {0};
  for (wchar_t i = 0; i < VN_MAXCHAR; ++i) {
    if (mark[g_vn_map[i]]) {
      printf("Failed ad %d\n", i);
      return;
    }
    mark[g_vn_map[i]] = 1;
  }
  printf("Check permutation OK!\n");
}

static void init_vn_map(void) {
  wchar_t shift = 0;
  wchar_t i = 0;
  for (; i <= VN_UP_A; ++i) {
    g_vn_map[i] = i + shift;
  }

  /* Giãn chữ hoa */
  shift += (VN_UP_A_ALL - 1);
  for (; i <= VN_UP_D; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_UP_D_ALL - 1);
  for (; i <= VN_UP_E; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_UP_E_ALL - 1);
  for (; i <= VN_UP_I; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_UP_I_ALL - 1);
  for (; i <= VN_UP_O; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_UP_O_ALL - 1);
  for (; i <= VN_UP_U; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_UP_U_ALL - 1);
  for (; i <= VN_UP_Y; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_UP_Y_ALL - 1);
  for (; i <= VN_LO_A; ++i) {
    g_vn_map[i] = i + shift;
  }

  /* Giãn chữ thường */
  shift += (VN_LO_A_ALL - 1);
  for (; i <= VN_LO_D; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_LO_D_ALL - 1);
  for (; i <= VN_LO_E; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_LO_E_ALL - 1);
  for (; i <= VN_LO_I; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_LO_I_ALL - 1);
  for (; i <= VN_LO_O; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_LO_O_ALL - 1);
  for (; i <= VN_LO_U; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_LO_U_ALL - 1);
  for (; i <= VN_LO_Y; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift += (VN_LO_Y_ALL - 1);
  for (; i < VN_UP_AF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 4;
  for (i = VN_UP_AX + 1; i < VN_UP_EF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 3;
  for (i = VN_UP_EE + 1; i < VN_UP_IF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_UP_IS + 1; i < VN_UP_OF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 4;
  for (i = VN_UP_OX + 1; i < VN_UP_UF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_UP_US + 1; i < VN_UP_YS; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 1;
  for (i = VN_UP_YS + 1; i < VN_LO_AF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 4;
  for (i = VN_LO_AX + 1; i < VN_LO_EF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 3;
  for (i = VN_LO_EE + 1; i < VN_LO_IF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_IS + 1; i < VN_LO_OF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 4;
  for (i = VN_LO_OX + 1; i < VN_LO_UF; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_US + 1; i < VN_LO_YS; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 1;
  for (i = VN_LO_YS + 1; i < VN_UP_AW; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_AW + 1; i < VN_UP_DD; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_DD + 1; i < VN_UP_IX; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_IX + 1; i < VN_UP_UX; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_UX + 1; i < VN_UP_OW; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_OW + 1; i < VN_UP_UW; ++i) {
    g_vn_map[i] = i + shift;
  }
  shift -= 2;
  for (i = VN_LO_UW + 1; i < VN_UP_AJ; ++i) {
    g_vn_map[i] = i + shift;
  }

  /* Ánh xạ chữ cái tiếng Việt */
  MAP_VALUE(VN_UP_AF, VN_UP_A, VN_UP_AF_POS);
  MAP_VALUE(VN_UP_AX, VN_UP_A, VN_UP_AX_POS);
  MAP_VALUE(VN_UP_AR, VN_UP_A, VN_UP_AR_POS);
  MAP_VALUE(VN_UP_AS, VN_UP_A, VN_UP_AS_POS);
  MAP_VALUE(VN_UP_AJ, VN_UP_A, VN_UP_AJ_POS);
  MAP_VALUE(VN_UP_AW, VN_UP_A, VN_UP_AW_POS);
  MAP_VALUE(VN_UP_AWF, VN_UP_A, VN_UP_AWF_POS);
  MAP_VALUE(VN_UP_AWX, VN_UP_A, VN_UP_AWX_POS);
  MAP_VALUE(VN_UP_AWR, VN_UP_A, VN_UP_AWR_POS);
  MAP_VALUE(VN_UP_AWS, VN_UP_A, VN_UP_AWS_POS);
  MAP_VALUE(VN_UP_AWJ, VN_UP_A, VN_UP_AWJ_POS);
  MAP_VALUE(VN_UP_AA, VN_UP_A, VN_UP_AA_POS);
  MAP_VALUE(VN_UP_AAF, VN_UP_A, VN_UP_AAF_POS);
  MAP_VALUE(VN_UP_AAX, VN_UP_A, VN_UP_AAX_POS);
  MAP_VALUE(VN_UP_AAR, VN_UP_A, VN_UP_AAR_POS);
  MAP_VALUE(VN_UP_AAS, VN_UP_A, VN_UP_AAS_POS);
  MAP_VALUE(VN_UP_AAJ, VN_UP_A, VN_UP_AAJ_POS);

  MAP_VALUE(VN_UP_DD, VN_UP_D, VN_UP_DD_POS);

  MAP_VALUE(VN_UP_EF, VN_UP_E, VN_UP_EF_POS);
  MAP_VALUE(VN_UP_EX, VN_UP_E, VN_UP_EX_POS);
  MAP_VALUE(VN_UP_ER, VN_UP_E, VN_UP_ER_POS);
  MAP_VALUE(VN_UP_ES, VN_UP_E, VN_UP_ES_POS);
  MAP_VALUE(VN_UP_EJ, VN_UP_E, VN_UP_EJ_POS);
  MAP_VALUE(VN_UP_EE, VN_UP_E, VN_UP_EE_POS);
  MAP_VALUE(VN_UP_EEF, VN_UP_E, VN_UP_EEF_POS);
  MAP_VALUE(VN_UP_EEX, VN_UP_E, VN_UP_EEX_POS);
  MAP_VALUE(VN_UP_EER, VN_UP_E, VN_UP_EER_POS);
  MAP_VALUE(VN_UP_EES, VN_UP_E, VN_UP_EES_POS);
  MAP_VALUE(VN_UP_EEJ, VN_UP_E, VN_UP_EEJ_POS);

  MAP_VALUE(VN_UP_IF, VN_UP_I, VN_UP_IF_POS);
  MAP_VALUE(VN_UP_IX, VN_UP_I, VN_UP_IX_POS);
  MAP_VALUE(VN_UP_IR, VN_UP_I, VN_UP_IR_POS);
  MAP_VALUE(VN_UP_IS, VN_UP_I, VN_UP_IS_POS);
  MAP_VALUE(VN_UP_IJ, VN_UP_I, VN_UP_IJ_POS);

  MAP_VALUE(VN_UP_OF, VN_UP_O, VN_UP_OF_POS);
  MAP_VALUE(VN_UP_OX, VN_UP_O, VN_UP_OX_POS);
  MAP_VALUE(VN_UP_OR, VN_UP_O, VN_UP_OR_POS);
  MAP_VALUE(VN_UP_OS, VN_UP_O, VN_UP_OS_POS);
  MAP_VALUE(VN_UP_OJ, VN_UP_O, VN_UP_OJ_POS);
  MAP_VALUE(VN_UP_OO, VN_UP_O, VN_UP_OO_POS);
  MAP_VALUE(VN_UP_OOF, VN_UP_O, VN_UP_OOF_POS);
  MAP_VALUE(VN_UP_OOX, VN_UP_O, VN_UP_OOX_POS);
  MAP_VALUE(VN_UP_OOR, VN_UP_O, VN_UP_OOR_POS);
  MAP_VALUE(VN_UP_OOS, VN_UP_O, VN_UP_OOS_POS);
  MAP_VALUE(VN_UP_OOJ, VN_UP_O, VN_UP_OOJ_POS);
  MAP_VALUE(VN_UP_OW, VN_UP_O, VN_UP_OW_POS);
  MAP_VALUE(VN_UP_OWF, VN_UP_O, VN_UP_OWF_POS);
  MAP_VALUE(VN_UP_OWX, VN_UP_O, VN_UP_OWX_POS);
  MAP_VALUE(VN_UP_OWR, VN_UP_O, VN_UP_OWR_POS);
  MAP_VALUE(VN_UP_OWS, VN_UP_O, VN_UP_OWS_POS);
  MAP_VALUE(VN_UP_OWJ, VN_UP_O, VN_UP_OWJ_POS);

  MAP_VALUE(VN_UP_UF, VN_UP_U, VN_UP_UF_POS);
  MAP_VALUE(VN_UP_UX, VN_UP_U, VN_UP_UX_POS);
  MAP_VALUE(VN_UP_UR, VN_UP_U, VN_UP_UR_POS);
  MAP_VALUE(VN_UP_US, VN_UP_U, VN_UP_US_POS);
  MAP_VALUE(VN_UP_UJ, VN_UP_U, VN_UP_UJ_POS);
  MAP_VALUE(VN_UP_UW, VN_UP_U, VN_UP_UW_POS);
  MAP_VALUE(VN_UP_UWF, VN_UP_U, VN_UP_UWF_POS);
  MAP_VALUE(VN_UP_UWX, VN_UP_U, VN_UP_UWX_POS);
  MAP_VALUE(VN_UP_UWR, VN_UP_U, VN_UP_UWR_POS);
  MAP_VALUE(VN_UP_UWS, VN_UP_U, VN_UP_UWS_POS);
  MAP_VALUE(VN_UP_UWJ, VN_UP_U, VN_UP_UWJ_POS);

  MAP_VALUE(VN_UP_YF, VN_UP_Y, VN_UP_YF_POS);
  MAP_VALUE(VN_UP_YX, VN_UP_Y, VN_UP_YX_POS);
  MAP_VALUE(VN_UP_YR, VN_UP_Y, VN_UP_YR_POS);
  MAP_VALUE(VN_UP_YS, VN_UP_Y, VN_UP_YS_POS);
  MAP_VALUE(VN_UP_YJ, VN_UP_Y, VN_UP_YJ_POS);
  MAP_VALUE(VN_LO_AF, VN_LO_A, VN_LO_AF_POS);
  MAP_VALUE(VN_LO_AX, VN_LO_A, VN_LO_AX_POS);
  MAP_VALUE(VN_LO_AR, VN_LO_A, VN_LO_AR_POS);
  MAP_VALUE(VN_LO_AS, VN_LO_A, VN_LO_AS_POS);
  MAP_VALUE(VN_LO_AJ, VN_LO_A, VN_LO_AJ_POS);
  MAP_VALUE(VN_LO_AW, VN_LO_A, VN_LO_AW_POS);
  MAP_VALUE(VN_LO_AWF, VN_LO_A, VN_LO_AWF_POS);
  MAP_VALUE(VN_LO_AWX, VN_LO_A, VN_LO_AWX_POS);
  MAP_VALUE(VN_LO_AWR, VN_LO_A, VN_LO_AWR_POS);
  MAP_VALUE(VN_LO_AWS, VN_LO_A, VN_LO_AWS_POS);
  MAP_VALUE(VN_LO_AWJ, VN_LO_A, VN_LO_AWJ_POS);
  MAP_VALUE(VN_LO_AA, VN_LO_A, VN_LO_AA_POS);
  MAP_VALUE(VN_LO_AAF, VN_LO_A, VN_LO_AAF_POS);
  MAP_VALUE(VN_LO_AAX, VN_LO_A, VN_LO_AAX_POS);
  MAP_VALUE(VN_LO_AAR, VN_LO_A, VN_LO_AAR_POS);
  MAP_VALUE(VN_LO_AAS, VN_LO_A, VN_LO_AAS_POS);
  MAP_VALUE(VN_LO_AAJ, VN_LO_A, VN_LO_AAJ_POS);

  MAP_VALUE(VN_LO_DD, VN_LO_D, VN_LO_DD_POS);

  MAP_VALUE(VN_LO_EF, VN_LO_E, VN_LO_EF_POS);
  MAP_VALUE(VN_LO_EX, VN_LO_E, VN_LO_EX_POS);
  MAP_VALUE(VN_LO_ER, VN_LO_E, VN_LO_ER_POS);
  MAP_VALUE(VN_LO_ES, VN_LO_E, VN_LO_ES_POS);
  MAP_VALUE(VN_LO_EJ, VN_LO_E, VN_LO_EJ_POS);
  MAP_VALUE(VN_LO_EE, VN_LO_E, VN_LO_EE_POS);
  MAP_VALUE(VN_LO_EEF, VN_LO_E, VN_LO_EEF_POS);
  MAP_VALUE(VN_LO_EEX, VN_LO_E, VN_LO_EEX_POS);
  MAP_VALUE(VN_LO_EER, VN_LO_E, VN_LO_EER_POS);
  MAP_VALUE(VN_LO_EES, VN_LO_E, VN_LO_EES_POS);
  MAP_VALUE(VN_LO_EEJ, VN_LO_E, VN_LO_EEJ_POS);

  MAP_VALUE(VN_LO_IF, VN_LO_I, VN_LO_IF_POS);
  MAP_VALUE(VN_LO_IX, VN_LO_I, VN_LO_IX_POS);
  MAP_VALUE(VN_LO_IR, VN_LO_I, VN_LO_IR_POS);
  MAP_VALUE(VN_LO_IS, VN_LO_I, VN_LO_IS_POS);
  MAP_VALUE(VN_LO_IJ, VN_LO_I, VN_LO_IJ_POS);

  MAP_VALUE(VN_LO_OF, VN_LO_O, VN_LO_OF_POS);
  MAP_VALUE(VN_LO_OX, VN_LO_O, VN_LO_OX_POS);
  MAP_VALUE(VN_LO_OR, VN_LO_O, VN_LO_OR_POS);
  MAP_VALUE(VN_LO_OS, VN_LO_O, VN_LO_OS_POS);
  MAP_VALUE(VN_LO_OJ, VN_LO_O, VN_LO_OJ_POS);
  MAP_VALUE(VN_LO_OO, VN_LO_O, VN_LO_OO_POS);
  MAP_VALUE(VN_LO_OOF, VN_LO_O, VN_LO_OOF_POS);
  MAP_VALUE(VN_LO_OOX, VN_LO_O, VN_LO_OOX_POS);
  MAP_VALUE(VN_LO_OOR, VN_LO_O, VN_LO_OOR_POS);
  MAP_VALUE(VN_LO_OOS, VN_LO_O, VN_LO_OOS_POS);
  MAP_VALUE(VN_LO_OOJ, VN_LO_O, VN_LO_OOJ_POS);
  MAP_VALUE(VN_LO_OW, VN_LO_O, VN_LO_OW_POS);
  MAP_VALUE(VN_LO_OWF, VN_LO_O, VN_LO_OWF_POS);
  MAP_VALUE(VN_LO_OWX, VN_LO_O, VN_LO_OWX_POS);
  MAP_VALUE(VN_LO_OWR, VN_LO_O, VN_LO_OWR_POS);
  MAP_VALUE(VN_LO_OWS, VN_LO_O, VN_LO_OWS_POS);
  MAP_VALUE(VN_LO_OWJ, VN_LO_O, VN_LO_OWJ_POS);

  MAP_VALUE(VN_LO_UF, VN_LO_U, VN_LO_UF_POS);
  MAP_VALUE(VN_LO_UX, VN_LO_U, VN_LO_UX_POS);
  MAP_VALUE(VN_LO_UR, VN_LO_U, VN_LO_UR_POS);
  MAP_VALUE(VN_LO_US, VN_LO_U, VN_LO_US_POS);
  MAP_VALUE(VN_LO_UJ, VN_LO_U, VN_LO_UJ_POS);
  MAP_VALUE(VN_LO_UW, VN_LO_U, VN_LO_UW_POS);
  MAP_VALUE(VN_LO_UWF, VN_LO_U, VN_LO_UWF_POS);
  MAP_VALUE(VN_LO_UWX, VN_LO_U, VN_LO_UWX_POS);
  MAP_VALUE(VN_LO_UWR, VN_LO_U, VN_LO_UWR_POS);
  MAP_VALUE(VN_LO_UWS, VN_LO_U, VN_LO_UWS_POS);
  MAP_VALUE(VN_LO_UWJ, VN_LO_U, VN_LO_UWJ_POS);

  MAP_VALUE(VN_LO_YF, VN_LO_Y, VN_LO_YF_POS);
  MAP_VALUE(VN_LO_YX, VN_LO_Y, VN_LO_YX_POS);
  MAP_VALUE(VN_LO_YR, VN_LO_Y, VN_LO_YR_POS);
  MAP_VALUE(VN_LO_YS, VN_LO_Y, VN_LO_YS_POS);
  MAP_VALUE(VN_LO_YJ, VN_LO_Y, VN_LO_YJ_POS);
  // check_permutation();
}

void lazy_init_vn_map(void) {
  if (g_vn_map_lazy_init) {
    init_vn_map();
    g_vn_map_lazy_init = 0;
  }
}

int vnwchcmp(wchar_t ch1, wchar_t ch2) {
  static char lazy_init = 1;
  if (g_vn_map_lazy_init) {
    init_vn_map();
    g_vn_map_lazy_init = 0;
  }
  wchar_t v1, v2;
  VNCHMAP(v1, ch1);
  VNCHMAP(v2, ch2);
  if (v1 < v2) {
    return -1;
  } else if (v1 > v2) {
    return 1;
  }
  return 0;
}

int vnwscmp(const wchar_t *s1, const wchar_t *s2) {
  int chcmp;
  for (;;) {
    if (*s1 == 0 || *s2 == 0) {
      if (*s1 < *s2) {
        return -1;
      } else if (*s1 > *s2) {
        return 1;
      } else {
        break;
      }
    }
    chcmp = vnwchcmp(*s1, *s2);
    if (chcmp) {
      return chcmp;
    }
    ++s1;
    ++s2;
  }
  return 0;
}

int vnu8scmp(const char *s1, const char *s2) {
  wchar_t *ws1 = calloc(strlen(s1) + 1, sizeof(wchar_t));
  wchar_t *ws2 = calloc(strlen(s2) + 1, sizeof(wchar_t));
  u82ws(ws1, s1);
  u82ws(ws2, s2);
  int res = vnwscmp(ws1, ws2);
  free(ws1);
  free(ws2);
  return res;
}
