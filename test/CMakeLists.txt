find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(pdfTest tests.cpp)
target_link_libraries(pdfTest PRIVATE pdfwriter ${GTEST_LIBRARIES} pthread)
