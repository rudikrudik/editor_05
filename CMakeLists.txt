cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

if ($ENV{GITHUB_RUN_NUMBER})
    set(PROJECT_VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
else ()
    set(PROJECT_VERSION 0.0.1)
endif ()

project(editor VERSION ${PROJECT_VERSION})

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(editor
                src/controller.cpp
                src/main.cpp
                src/model.cpp
                src/primitives.cpp
                src/view.cpp
)

if (MSVC)
    target_compile_options(editor PRIVATE
            /W4
    )
else ()
    target_compile_options(editor PRIVATE
            -Wall
    )
endif()

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT rudik.login@gmail.com)
include(CPack)