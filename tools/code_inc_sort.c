#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./p inp.txt\n");
    return 0;
  }
  FILE *inp = fopen(argv[1], "r");
  char def[100], name[100], code[100];
  struct vncdef {
    char def[100], name[100], code[100];
    int val;
  } lines[1000];
  int n = 0;
  while (fscanf(inp, "%s%s%s", def, name, code) == 3) {
    int val = 0;
    sscanf(code, "%i", &val);
    strcpy(lines[n].def, def);
    strcpy(lines[n].name, name);
    strcpy(lines[n].code, code);
    lines[n].val = val;
    ++n;
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (lines[i].val > lines[j].val) {
        struct vncdef tmp = lines[i];
        lines[i] = lines[j];
        lines[j] = tmp;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%s %s %s\n", lines[i].def, lines[i].name, lines[i].code);
  }
  fclose(inp);
}