CMAKE_MINIMUM_REQUIRED (VERSION 3.5.0 FATAL_ERROR)

PROJECT (s2e2 VERSION 0.0.0 LANGUAGES CXX)

SET (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

INCLUDE (BuildFlags)
INCLUDE (OutputDirs)


SET (PUBLIC_HEADERS_DIR
    "include/"
)

SET (PUBLIC_HEADERS
    "include/error.hpp"
    "include/function.hpp"
    "include/functions/function_if.hpp"
    "include/functions/function_replace.hpp"
)

SET (HEADERS
    "src/converter.hpp"
    "src/interface_converter.hpp"
    "src/interface_tokenizer.hpp"
    "src/token_type.hpp"
    "src/token.hpp"
    "src/tokenizer.hpp"
)

SET (SOURCES
    "src/converter.cpp"
    "src/error.cpp"
    "src/function.cpp"
    "src/token.cpp"
    "src/tokenizer.cpp"
    "src/functions/function_if.cpp"
    "src/functions/function_replace.cpp"
)

ADD_LIBRARY (${PROJECT_NAME} STATIC
    ${PUBLIC_HEADERS}
    ${HEADERS}
    ${SOURCES}
)

TARGET_INCLUDE_DIRECTORIES (${PROJECT_NAME}
    PUBLIC "include"
)

INSTALL (
    TARGETS ${PROJECT_NAME} 
    ARCHIVE DESTINATION ${LIB_OUTPUT_DIR}
    LIBRARY DESTINATION ${LIB_OUTPUT_DIR}
)

INSTALL (
    DIRECTORY ${PUBLIC_HEADERS_DIR}
    DESTINATION ${HEADERS_OUTPUT_DIR}
    FILES_MATCHING PATTERN "*.hpp"
)


ADD_SUBDIRECTORY(3rdparty)
ADD_SUBDIRECTORY(test)
