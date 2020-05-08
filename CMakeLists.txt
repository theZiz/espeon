cmake_minimum_required(VERSION 3.1)

set(PROJECTNAME espeon)

project( ${PROJECTNAME} )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
	${CMAKE_SOURCE_DIR}/src/espeon.cpp
)

find_package(OpenMP)
if (OPENMP_FOUND)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(LIBS ${LIBS} ${OpenMP_CXX_LIBRARIES})
endif()

add_executable( ${PROJECTNAME} ${HDRS} ${SRCS} )
#include_directories(${PROJECTNAME} ${INCLUDE})
target_link_libraries(${PROJECTNAME} ${LIBS})

install(TARGETS ${PROJECTNAME} RUNTIME DESTINATION bin)
