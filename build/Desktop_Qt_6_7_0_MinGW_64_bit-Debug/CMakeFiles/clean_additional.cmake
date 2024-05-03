# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appFantasyMovies_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appFantasyMovies_autogen.dir\\ParseCache.txt"
  "appFantasyMovies_autogen"
  )
endif()
