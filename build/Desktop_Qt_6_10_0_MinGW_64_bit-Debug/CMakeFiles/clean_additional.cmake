# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Gestor_Stock_EstruII_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Gestor_Stock_EstruII_autogen.dir\\ParseCache.txt"
  "Gestor_Stock_EstruII_autogen"
  )
endif()
