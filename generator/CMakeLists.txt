add_executable(py py.c)
foreach (p py)
  target_link_libraries(${p} vncmp)
endforeach()