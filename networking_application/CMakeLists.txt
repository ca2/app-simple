cmake_minimum_required(VERSION 3.16)
project(app_simple_networking_application CXX)



list(APPEND library_source
   _.h
   ##_library.h
   #_factory.cpp
   application.cpp
   application.h
   document.cpp
   document.h
   framework.cpp
   framework.h
   frame.cpp
   frame.h
   main_frame.cpp
   main_frame.h
   tab_impact.cpp
   tab_impact.h
   impact.cpp
   impact.h
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
else ()
   set(LIBCXX_TARGETING_MSVC OFF)
endif ()


add_library(${PROJECT_NAME} SHARED ${library_source})

target_precompile_headers(app_simple_networking_application PRIVATE framework.h)

set_target_properties(app_simple_networking_application PROPERTIES LINKER_LANGUAGE CXX)


list(APPEND app_simple_networking_application_references
   acme
   apex
   aqua
   aura
   axis
   base
   )

if (MSVC)
   target_compile_options(app_simple_networking_application PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_networking_application PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_networking_application PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_networking_application PRIVATE ${app_simple_networking_application_references})
   add_dependencies(app_simple_networking_application draw2d_gdiplus imaging_wic)
elseif(LINUX OR FREEBSD)
   target_compile_options(app_simple_networking_application PRIVATE -fpermissive)
   #target_link_options(app_simple_networking_application PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_networking_application PRIVATE ${app_simple_networking_application_references})
   target_link_options(app_simple_networking_application PRIVATE -Wl,-z,defs)
   add_dependencies(app_simple_networking_application draw2d_cairo imaging_freeimage)
endif ()

add_dependencies(app_simple_networking_application experience_core)
add_dependencies(app_simple_networking_application networking_bsd)

list(APPEND library_link_directories
   ${LIBRARY_OUTPUT_PATH}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis
   )


target_link_directories(app_simple_networking_application PRIVATE ${library_link_directories})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})




list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(app_simple_networking_application PRIVATE _APP_SIMPLE_DRAWING_LIBRARY)
target_compile_definitions(app_simple_networking_application PRIVATE UNICODE)
target_compile_definitions(app_simple_networking_application PRIVATE _UNICODE)



add_subdirectory(__implement)

