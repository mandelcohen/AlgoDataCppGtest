set(CLASS_LIBRARY_SRCS
        TurboCollections.hpp
        TurboCollections.cpp
        TurboLinkedStack.h
        TurboLinkedStack.cpp
        TurboLinkedList.h
)

# Declare the library
add_library(CLASS_LIBRARY STATIC
    ${CLASS_LIBRARY_SRCS}
)

target_link_libraries(CLASS_LIBRARY)

# Specify here the include directories exported
# by this library
target_include_directories(CLASS_LIBRARY PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
