/* (C) Nguyễn Bá Ngọc 2023 */

#ifndef TOOLS_VN_MAP_EXPORT_H_
#define TOOLS_VN_MAP_EXPORT_H_

#include <wchar.h>

void vn_map_export(size_t n, const wchar_t *a, const char *name);
void init_vn_map(wchar_t *map);

#endif  // TOOLS_VN_MAP_EXPORT_H_
