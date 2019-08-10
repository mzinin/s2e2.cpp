STRING (TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE_SUBDIR)


SET (OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build/output/${BUILD_TYPE_SUBDIR}")
SET (HEADERS_OUTPUT_DIR "${OUTPUT_DIR}/include")
SET (LIB_OUTPUT_DIR "${OUTPUT_DIR}/lib")
SET (TEST_OUTPUT_DIR "${OUTPUT_DIR}/test")


FILE (MAKE_DIRECTORY ${HEADERS_OUTPUT_DIR})
FILE (MAKE_DIRECTORY ${LIB_OUTPUT_DIR})
FILE (MAKE_DIRECTORY ${TEST_OUTPUT_DIR})
