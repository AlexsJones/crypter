cmake_minimum_required(VERSION 2.8)
set(INSTALL_PREFIX /usr)

set(PROJECT_NAME "crypter")

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS_DEBUG "-g -rdynamic")
set(SOURCE "")
set(HEADERS "")

add_subdirectory(src)
add_subdirectory(tests)

include_directories(${PROJECT_INC_DIR}src)
include_directories(${PROJECT_INC_DIR}tests)

message("${SOURCE}")
message("${HEADERS}")

add_executable(${PROJECT_NAME} ${SOURCE})
