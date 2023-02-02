/* (C) Nguyễn Bá Ngọc */

#ifndef VNCMP_H_
#define VNCMP_H_

#include <wchar.h>

#include "vnchar.h"

extern const wchar_t k_vn_map[];
extern const wchar_t k_vn_characters[];

int vnwchcmp(wchar_t ch1, wchar_t ch2);
int vnwscmp(const wchar_t *s1, const wchar_t *s2);
int vnu8scmp(const char *s1, const char *s2);

#endif  // VNCMP_H_