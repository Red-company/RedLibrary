#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fmt::fmt" for configuration "Release"
set_property(TARGET fmt::fmt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(fmt::fmt PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libfmt.8.1.1.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libfmt.8.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS fmt::fmt )
list(APPEND _IMPORT_CHECK_FILES_FOR_fmt::fmt "${_IMPORT_PREFIX}/lib/libfmt.8.1.1.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
