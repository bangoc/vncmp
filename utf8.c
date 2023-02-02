/* (C) Nguyễn Bá Ngọc */

#include "utf8.h"

#include <string.h>
#include <wchar.h>

int seqlen(unsigned char first) {
  int cc = 0;
  while (first > 0x7F) {
    first <<= 1;
    ++cc;
  }
  return cc? cc: 1;
}

size_t u82wc(wchar_t *dest, const char *s) {
  wchar_t wch = 0;
  const unsigned char *p = s;
  int nb = seqlen(*p);
  int mask = (1 << (8 - nb)) - 1;
  wch = (*p) & mask;
  for (int i = 1; i < nb; ++i) {
    wch <<= 6;
    wch += p[i] & 0x3F;
  }
  *dest = wch;
  return nb;
}

size_t u82ws(wchar_t *dest, const char *s) {
  const char *p = s;
  wchar_t tmp;
  int idx = 0;
  while (*p) {
    int nb = u82wc(&tmp, p);
    dest[idx] = tmp;
    ++idx;
    p += nb;
  }
  dest[idx] = 0;
  return idx;
}

size_t wc2u8(char *dest, const wchar_t ch) {
  if (ch < 0x80) {
    dest[0] = (char)ch;
    dest[1] = '\0';
    return 1;
  }
  if (ch < 0x800) {
    dest[0] = (ch >> 6) | 0xC0;
    dest[1] = (ch & 0x3F) | 0x80;
    dest[2] = '\0';
    return 2;
  }
  if (ch < 0x10000) {
    dest[0] = (ch >> 12) | 0xE0;
    dest[1] = ((ch >> 6) & 0x3F) | 0x80;
    dest[2] = (ch & 0x3F) | 0x80;
    dest[3] = '\0';
    return 3;
  }
  if (ch < 0x110000) {
    dest[0] = (ch >> 18) | 0xF0;
    dest[1] = ((ch >> 12) & 0x3F) | 0x80;
    dest[2] = ((ch >> 6) & 0x3F) | 0x80;
    dest[3] = (ch & 0x3F) | 0x80;
    dest[4] = '\0';
    return 4;
  }
  return 0;
}

size_t ws2u8(char *dest, const wchar_t *s) {
  size_t idx = 0;
  for (int i = 0; i < wcslen(s); ++i) {
    char buff[10];
    size_t n = wc2u8(buff, s[i]);
    memcpy(dest + idx, buff, n);
    idx += n;
  }
  dest[idx] = 0;
  return idx;
}