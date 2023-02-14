#include <stdio.h>
#include <string.h>
#include <uchar.h>

#include "c-cpp/vncmp.h"
#include "c-cpp/utf8.h"

int main() {
  printf("%zu\n", sizeof(wchar_t));
  wchar_t str[] = L"Tháng 3 mùa hoa gạo.";
  wchar_t *p = str;
  while (*p) {
    printf("%d ", *p);
    ++p;
  }
  printf("\n%zu\n", wcslen(str));
  char u8str[100];
  printf("%zu\n", ws2u8(u8str, str));
  printf("%s\n", u8str);
  char *s = u8"ạ";
  wchar_t wch;
  printf("%zu ", u82wch(&wch, s));
  printf("%d\n", wch);
  char *u8s = u8"Tháng 3 mùa hoa gạo.";
  wchar_t ws[100];
  printf("%zu\n", u82ws(ws, u8s));
  printf("wcscmp = %d\n", wcscmp(ws, str));

  printf("%d\n", vnu8scmp(u8"Hà Nội", u8"Hải Phòng"));
  printf("%d\n", vnu8scmp(u8"Yên Bái", u8"Vĩnh Phúc"));
}