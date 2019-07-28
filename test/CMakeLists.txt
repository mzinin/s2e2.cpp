SET (TARGET_NAME s2e2_tests)


SET (SOURCES
    "src/main.cpp"
    "src/tokenizer_tests.cpp"
)

ADD_EXECUTABLE (${TARGET_NAME}
    ${SOURCES}
)

TARGET_LINK_LIBRARIES (${TARGET_NAME}
    s2e2
    gmock
    gtest
)

TARGET_INCLUDE_DIRECTORIES (${TARGET_NAME}
    PRIVATE "../include"
    PRIVATE "../src"
    PRIVATE "../3rdparty/googletest/googlemock/include"
    PRIVATE "../3rdparty/googletest/googletest/include"
)

TARGET_COMPILE_FEATURES (${TARGET_NAME}
    PUBLIC "cxx_std_17"
)
