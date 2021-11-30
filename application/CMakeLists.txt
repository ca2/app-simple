cmake_minimum_required(VERSION 3.17)
project(app_simple_application CXX)


list(APPEND library_source
        _.cpp
        _.h
        _user.h
        application.cpp
        application.h
        document.cpp
        document.h
        framework.cpp
        framework.h
        main_frame.cpp
        main_frame.h
        impact.cpp
        impact.h)


list(APPEND library_references
   acme
   apex
   aqua
   aura
   axis
   base
   )


add_library(app_simple_application ${library_source} )


target_precompile_headers(app_simple_application PRIVATE framework.h)


set_target_properties(app_simple_application PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(app_simple_application PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_application PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_libraries(app_simple_application PRIVATE ${library_references})
    target_link_options(app_simple_application PRIVATE "/SUBSYSTEM:WINDOWS")
elseif(LINUX OR FREEBSD)
    target_compile_options(app_simple_application PRIVATE -fpermissive)
    #target_link_options(app_simple_application PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(app_simple_application PRIVATE ${library_references})
    target_link_options(app_simple_application PRIVATE -Wl,-z,defs)
endif()


add_dependencies(app_simple_application experience_core)
add_dependencies(app_simple_application ${default_draw2d})
add_dependencies(app_simple_application ${default_write_text})
add_dependencies(app_simple_application ${app_common_dependencies})
add_dependencies(app_simple_application database_sqlite3)


target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_application PRIVATE _APP_SIMPLE_APPLICATION_LIBRARY)


add_executable(_app_simple_application _app_simple_application.cpp)


list(APPEND executable_references
   acme
   apex
   aqua
   aura
   axis
   base
   app_simple_application
   )


add_custom_target(${PROJECT_NAME}_matter
   COMMAND ${APPLICATION_BUILD_HELPER} ${PROJECT_SOURCE_DIR}
   WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
   DEPENDS deps.txt matter.txt
   VERBATIM
   )


if(LINUX OR FREEBSD)


    list(APPEND executable_references ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o)


endif()


add_dependencies(_${PROJECT_NAME} ${PROJECT_NAME}_matter)


if (MSVC)


    target_compile_options(_app_simple_application PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_app_simple_application PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_app_simple_application PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(_app_simple_application PRIVATE ${executable_references})


elseif(LINUX OR FREEBSD)


    target_compile_options(_app_simple_application PRIVATE -fpermissive)
    target_link_libraries(_app_simple_application PRIVATE ${executable_references})
    target_link_options(_app_simple_application PRIVATE -Wl,-z,defs)


endif ()


add_dependencies(_app_simple_application ${default_draw2d})
add_dependencies(_app_simple_application ${default_write_text})
add_dependencies(_app_simple_application ${app_common_dependencies})
add_dependencies(_app_simple_application experience_core)
add_dependencies(_app_simple_application gpu_opengl)


target_include_directories(_app_simple_application PRIVATE ${library_include_directories})

target_link_directories(_app_simple_application PRIVATE ${library_link_directories})

target_link_libraries(_app_simple_application PRIVATE acme apex app_simple_application)

set_target_properties(_app_simple_application PROPERTIES LINKER_LANGUAGE CXX)



