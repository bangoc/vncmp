#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c-cpp/vncmp.h"

int main() {
  int n = 0;

  // Không quá 100 chuỗi 100 bytes
  char *ss[100];
  for (int i = 0; i < 100; ++i) {
    ss[i] = malloc(100);
  }
  int ret = 0;
  while (scanf("%[^\n]%*c", ss[n]) == 1) {
    ++n;
  }
  if (n < 1) {
    return 0;
  }
  if (n == 1) {
    printf("%s\n", ss[0]);
    return 0;
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (vnu8scmp(ss[i], ss[j]) > 0) {
        char *tmp = ss[i];
        ss[i] = ss[j];
        ss[j] = tmp;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%s\n", ss[i]);
  }
  for (int i = 0; i < 100; ++i) {
    free(ss[i]);
  }
}