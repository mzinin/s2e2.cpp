CMAKE_MINIMUM_REQUIRED (VERSION 3.5.0 FATAL_ERROR)

PROJECT (s2e2 VERSION 0.0.0 LANGUAGES CXX)

SET (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

INCLUDE (BuildFlags)
INCLUDE (OutputDirs)


SET (PUBLIC_HEADERS
    "include/error.hpp"
)

SET (HEADERS
    "src/interface_tokenizer.hpp"
    "src/token_type.hpp"
    "src/token.hpp"
    "src/tokenizer.hpp"
)

SET (SOURCES
    "src/error.cpp"
    "src/token.cpp"
    "src/tokenizer.cpp"
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
    FILES ${PUBLIC_HEADERS}
    DESTINATION ${HEADERS_OUTPUT_DIR}
)


ADD_SUBDIRECTORY(3rdparty)
ADD_SUBDIRECTORY(test)
