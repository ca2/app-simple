cmake_minimum_required(VERSION 3.16)
project(app_simple_box CXX)


set(LIBRARY_NAME app_simple_box)


list(APPEND library_source
        _.cpp
        _.h
   #_factory.cpp
        application.cpp
        application.h
        document.cpp
        document.h
        framework.cpp
        framework.h
        impact.cpp
        impact.h
        main_frame.cpp
        main_frame.h
   )


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(app_simple_box PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)


    target_compile_options(app_simple_box PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_box PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_box PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(app_simple_box PRIVATE acme apex aqua aura axis base)


elseif(${LINUX} OR ${FREEBSD})


    target_compile_options(app_simple_box PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive>)
    #target_link_options(app_simple_box PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(app_simple_box PRIVATE acme apex aqua aura axis base)
    target_link_options(app_simple_box PRIVATE -Wl,-z,defs)


endif()


add_dependencies(app_simple_box experience_core)
add_dependencies(app_simple_box ${default_draw2d})
add_dependencies(app_simple_box ${default_imaging})
add_dependencies(app_simple_box ${default_write_text})



list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_box PRIVATE _APP_SIMPLE_BOX_LIBRARY)


add_subdirectory(__implement)

