cmake_minimum_required(VERSION 3.16)

project(EcoMugG4Test)

set(CMAKE_CXX_STANDARD 20)

message(STATUS "Looking for Geant4")
find_package(Geant4 11.0.0 REQUIRED ui_all vis_all)
message(STATUS "Looking for Geant4 - found (version: ${Geant4_VERSION})")

file(GLOB EcoMugG4Test_SCRIPTS ${PROJECT_SOURCE_DIR}/scripts/*)
foreach(_script ${EcoMugG4Test_SCRIPTS})
    configure_file(${_script} ${PROJECT_BINARY_DIR} COPYONLY)
endforeach()

file(GLOB_RECURSE EcoMugG4Test_SOURCES ${PROJECT_SOURCE_DIR}/*.cxx)
add_executable(EcoMugG4Test ${EcoMugG4Test_SOURCES})
target_include_directories(EcoMugG4Test PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(EcoMugG4Test PRIVATE ${Geant4_LIBRARIES})
