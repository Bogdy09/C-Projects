# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\final_quiz_observer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\final_quiz_observer_autogen.dir\\ParseCache.txt"
  "final_quiz_observer_autogen"
  )
endif()
