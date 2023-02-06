/* (C) Nguyễn Bá Ngọc */

#ifndef UTF8_H_
#define UTF8_H_

#include <wchar.h>

int seqlen(unsigned char first);
size_t u82wch(wchar_t *dest, const char *s);
size_t u82ws(wchar_t *dest, const char *s);
size_t wch2u8(char *dest, const wchar_t ch);
size_t ws2u8(char *dest, const wchar_t *s);

#endif  // UTF8_H_