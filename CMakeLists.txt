cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)


#project(editor VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
project(editor VERSION 0.0.1)

include_directories(src)

file(GLOB ALL_SRC
        "src/*.cpp"
        "include/*.hpp"
        main.cpp
)

add_executable(editor  ${ALL_SRC})

if (MSVC)
    target_compile_options(editor PRIVATE
            /W4
    )
else ()
    target_compile_options(editor PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT rudik.login@gmail.com)
include(CPack)