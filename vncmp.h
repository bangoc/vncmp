/* (C) Nguyễn Bá Ngọc */

#ifndef VNCMP_H_
#define VNCMP_H_

#include <wchar.h>

#define VN_UP_A  0X0041
#define VN_UP_D  0X0044
#define VN_UP_E  0X0045
#define VN_UP_I  0X0049
#define VN_UP_O  0X004F
#define VN_UP_U  0X0055
#define VN_UP_Y  0X0059
#define VN_LO_A  0X0061
#define VN_LO_D  0X0064
#define VN_LO_E  0x0065
#define VN_LO_I  0x0069
#define VN_LO_O  0x006F
#define VN_LO_U  0x0075
#define VN_LO_Y  0x0079
#define VN_UP_AF 0X00C0
#define VN_UP_AS 0X00C1
#define VN_UP_AA 0X00C2
#define VN_UP_AX 0X00C3
#define VN_UP_EF 0X00C8
#define VN_UP_ES 0X00C9
#define VN_UP_EE 0X00CA
#define VN_UP_IF 0X00CC
#define VN_UP_IS 0X00CD
#define VN_UP_OF 0X00D2
#define VN_UP_OS 0X00D3
#define VN_UP_OO 0X00D4
#define VN_UP_OX 0X00D5
#define VN_UP_UF 0X00D9
#define VN_UP_US 0X00DA
#define VN_UP_YS 0X00DD
#define VN_LO_AF 0X00E0
#define VN_LO_AS 0X00E1
#define VN_LO_AA 0X00E2
#define VN_LO_AX 0X00E3
#define VN_LO_EF 0X00E8
#define VN_LO_ES 0X00E9
#define VN_LO_EE 0X00EA
#define VN_LO_IF 0X00EC
#define VN_LO_IS 0X00ED
#define VN_LO_OF 0X00F2
#define VN_LO_OS 0X00F3
#define VN_LO_OO 0X00F4
#define VN_LO_OX 0X00F5
#define VN_LO_UF 0X00F9
#define VN_LO_US 0X00FA
#define VN_LO_YS 0X00FD
#define VN_UP_AW 0X0102
#define VN_LO_AW 0X0103
#define VN_UP_DD 0X0110
#define VN_LO_DD 0X0111
#define VN_UP_IX 0X0128
#define VN_LO_IX 0X0129
#define VN_UP_UX 0X0168
#define VN_LO_UX 0X0169
#define VN_UP_OW 0X01A0
#define VN_LO_OW 0X01A1
#define VN_UP_UW 0X01AF
#define VN_LO_UW 0X01B0
#define VN_UP_AJ 0X1EA0
#define VN_LO_AJ 0X1EA1
#define VN_UP_AR 0X1EA2
#define VN_LO_AR 0X1EA3
#define VN_UP_AAS 0X1EA4
#define VN_LO_AAS 0X1EA5
#define VN_UP_AAF 0X1EA6
#define VN_LO_AAF 0X1EA7
#define VN_UP_AAR 0X1EA8
#define VN_LO_AAR 0X1EA9
#define VN_UP_AAX 0X1EAA
#define VN_LO_AAX 0X1EAB
#define VN_UP_AAJ 0X1EAC
#define VN_LO_AAJ 0X1EAD
#define VN_UP_AWS 0X1EAE
#define VN_LO_AWS 0X1EAF
#define VN_UP_AWF 0X1EB0
#define VN_LO_AWF 0X1EB1
#define VN_UP_AWR 0X1EB2
#define VN_LO_AWR 0X1EB3
#define VN_UP_AWX 0X1EB4
#define VN_LO_AWX 0X1EB5
#define VN_UP_AWJ 0X1EB6
#define VN_LO_AWJ 0X1EB7
#define VN_UP_EJ 0X1EB8
#define VN_LO_EJ 0X1EB9
#define VN_UP_ER 0X1EBA
#define VN_LO_ER 0X1EBB
#define VN_UP_EX 0X1EBC
#define VN_LO_EX 0X1EBD
#define VN_UP_EES 0X1EBE
#define VN_LO_EES 0X1EBF
#define VN_UP_EEF 0X1EC0
#define VN_LO_EEF 0X1EC1
#define VN_UP_EER 0X1EC2
#define VN_LO_EER 0X1EC3
#define VN_UP_EEX 0X1EC4
#define VN_LO_EEX 0X1EC5
#define VN_UP_EEJ 0X1EC6
#define VN_LO_EEJ 0X1EC7
#define VN_UP_IR 0X1EC8
#define VN_LO_IR 0X1EC9
#define VN_UP_IJ 0X1ECA
#define VN_LO_IJ 0X1ECB
#define VN_UP_OJ 0X1ECC
#define VN_LO_OJ 0X1ECD
#define VN_UP_OR 0X1ECE
#define VN_LO_OR 0X1ECF
#define VN_UP_OOS 0X1ED0
#define VN_LO_OOS 0X1ED1
#define VN_UP_OOF 0X1ED2
#define VN_LO_OOF 0X1ED3
#define VN_UP_OOR 0X1ED4
#define VN_LO_OOR 0X1ED5
#define VN_UP_OOX 0X1ED6
#define VN_LO_OOX 0X1ED7
#define VN_UP_OOJ 0X1ED8
#define VN_LO_OOJ 0X1ED9
#define VN_UP_OWS 0X1EDA
#define VN_LO_OWS 0X1EDB
#define VN_UP_OWF 0X1EDC
#define VN_LO_OWF 0X1EDD
#define VN_UP_OWR 0X1EDE
#define VN_LO_OWR 0X1EDF
#define VN_UP_OWX 0X1EE0
#define VN_LO_OWX 0X1EE1
#define VN_UP_OWJ 0X1EE2
#define VN_LO_OWJ 0X1EE3
#define VN_UP_UJ 0X1EE4
#define VN_LO_UJ 0X1EE5
#define VN_UP_UR 0X1EE6
#define VN_LO_UR 0X1EE7
#define VN_UP_UWS 0X1EE8
#define VN_LO_UWS 0X1EE9
#define VN_UP_UWF 0X1EEA
#define VN_LO_UWF 0X1EEB
#define VN_UP_UWR 0X1EEC
#define VN_LO_UWR 0X1EED
#define VN_UP_UWX 0X1EEE
#define VN_LO_UWX 0X1EEF
#define VN_UP_UWJ 0X1EF0
#define VN_LO_UWJ 0X1EF1
#define VN_UP_YF 0X1EF2
#define VN_LO_YF 0X1EF3
#define VN_UP_YJ 0X1EF4
#define VN_LO_YJ 0X1EF5
#define VN_UP_YR 0X1EF6
#define VN_LO_YR 0X1EF7
#define VN_UP_YX 0X1EF8
#define VN_LO_YX 0X1EF9

extern wchar_t g_vn_map[];

extern const wchar_t k_vn_characters[];
extern const int k_vn_map_max_index;

void lazy_init_vn_map(void);
int vnwchcmp(wchar_t ch1, wchar_t ch2);
int vnwscmp(const wchar_t *s1, const wchar_t *s2);
int vnu8scmp(const char *s1, const char *s2);

#endif  // VNCMP_H_