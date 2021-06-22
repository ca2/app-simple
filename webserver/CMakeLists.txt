cmake_minimum_required(VERSION 3.17)
project(app_simple_drawing CXX)



list(APPEND library_source
   _.h
   _drawing.h
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
   render.cpp
   render.h
   render_1through3.cpp
   render_arcs.cpp
   tab_view.cpp
   tab_view.h
   view.cpp
   view.h
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
else ()
   set(LIBCXX_TARGETING_MSVC OFF)
endif ()


add_library(app_simple_drawing SHARED ${library_source})

target_precompile_headers(app_simple_drawing PRIVATE framework.h)

set_target_properties(app_simple_drawing PROPERTIES LINKER_LANGUAGE CXX)



list(APPEND app_simple_drawing_references
   acme
   apex
   aqua
   aura
   axis
   base
   )

if (MSVC)
   target_compile_options(app_simple_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_drawing PRIVATE ${app_simple_drawing_references})
   add_dependencies(app_simple_drawing draw2d_gdiplus imaging_wic)
elseif (LINUX)
   target_compile_options(app_simple_drawing PRIVATE -fpermissive)
   target_link_options(app_simple_drawing PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(app_simple_drawing PRIVATE ${app_simple_drawing_references})
   target_link_options(app_simple_drawing PRIVATE -Wl,-z,defs)
   add_dependencies(app_simple_drawing draw2d_cairo imaging_freeimage)
endif ()

add_dependencies(app_simple_drawing experience_core)

list(APPEND library_link_directories
   ${LIBRARY_OUTPUT_PATH}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis
   )


target_link_directories(app_simple_drawing PRIVATE ${library_link_directories})


target_include_directories(${LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})



target_include_directories(app_simple_drawing PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_drawing PRIVATE _APP_SIMPLE_DRAWING_LIBRARY)
target_compile_definitions(app_simple_drawing PRIVATE UNICODE)
target_compile_definitions(app_simple_drawing PRIVATE _UNICODE)

add_executable(_app_simple_drawing ${PLATFORM_NAME}/main.cpp)
target_compile_definitions(_app_simple_drawing PRIVATE UNICODE)
target_compile_definitions(_app_simple_drawing PRIVATE _UNICODE)

if (MSVC)
   target_compile_options(_app_simple_drawing PRIVATE "/D_APP_ID=\"app-simple/drawing\"")
   target_compile_options(_app_simple_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(_app_simple_drawing PRIVATE ${app_simple_drawing_references} app_simple_drawing)
   add_dependencies(_app_simple_drawing draw2d_gdiplus imaging_wic)
elseif (LINUX)
   target_compile_options(_app_simple_drawing PRIVATE -fpermissive)
   target_link_options(_app_simple_drawing PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(_app_simple_drawing PRIVATE ${app_simple_drawing_references} app_simple_drawing)
   target_link_options(_app_simple_drawing PRIVATE -Wl,-z,defs)
   add_dependencies(_app_simple_drawing draw2d_cairo imaging_freeimage)


endif ()


add_dependencies(_app_simple_drawing app_simple_drawing)

target_include_directories(_app_simple_drawing PRIVATE ${library_include_directories})

target_link_directories(_app_simple_drawing PRIVATE ${library_link_directories})

target_link_libraries(_app_simple_drawing PRIVATE acme apex aqua aura axis base app_simple_drawing)

set_target_properties(_app_simple_drawing PROPERTIES LINKER_LANGUAGE CXX)