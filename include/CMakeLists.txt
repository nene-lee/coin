configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Inventor/C/basic.h.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/Inventor/C/basic.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Inventor/system/gl-headers.h.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/Inventor/system/gl-headers.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Inventor/system/inttypes.h.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/Inventor/system/inttypes.h)

file(GLOB_RECURSE COMMON_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/Inventor/*.h)
file(GLOB_RECURSE COMMON_BIN_HDRS ${CMAKE_CURRENT_BINARY_DIR}/Inventor/*.h)

set(COIN_DOCUMENTATION_FILES
  ${COIN_DOCUMENTATION_FILES}
  ${CMAKE_CURRENT_SOURCE_DIR}/SoDebug.h
  ${CMAKE_CURRENT_BINARY_DIR}/Inventor/C/basic.h
  ${COMMON_HDRS}
  CACHE INTERNAL "COIN_DOCUMENTATION_FILES"
)

set(COMMON_HDRS ${COMMON_HDRS} ${COMMON_BIN_HDRS} PARENT_SCOPE)
