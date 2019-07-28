CMAKE_MINIMUM_REQUIRED (VERSION 3.5.0 FATAL_ERROR)

PROJECT (s2e2 VERSION 0.0.0 LANGUAGES CXX)


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

TARGET_COMPILE_FEATURES (${PROJECT_NAME}
    PUBLIC "cxx_std_17"
)

ADD_SUBDIRECTORY(3rdparty)
ADD_SUBDIRECTORY(test)
