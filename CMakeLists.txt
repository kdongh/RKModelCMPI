cmake_minimum_required(VERSION 2.7)
project(RK_MPI)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

set(SOURCE_FILES testMain.cpp basis.cpp complexNumber.cpp parallelizing_core.cpp tdSch.cpp)

add_executable(out ${SOURCE_FILES})


target_link_libraries(out ${MPI_LIBRARIES})

if(MPI_COMPLIE_FLAGS)
    set_target_properties(out PROPERTIES COMPLIE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(out PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()