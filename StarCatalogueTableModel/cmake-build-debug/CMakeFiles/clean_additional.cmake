# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\final_star_catalogue_tablemodel__autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\final_star_catalogue_tablemodel__autogen.dir\\ParseCache.txt"
  "final_star_catalogue_tablemodel__autogen"
  )
endif()
