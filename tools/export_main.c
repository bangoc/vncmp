#include "tools/vn_map_export.h"
#include "vncmp.h"

wchar_t map[VN_MAXCHAR];

int main() {
  init_vn_map(map);
  vn_map_export(VN_MAXCHAR, map, "k_vn_map");
}