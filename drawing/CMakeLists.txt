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


add_library(app_simple_drawing SHARED ${library_source})

target_precompile_headers(app_simple_drawing PRIVATE framework.h)

set_target_properties(app_simple_drawing PROPERTIES LINKER_LANGUAGE CXX)


list(APPEND library_references
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
   target_link_libraries(app_simple_drawing PRIVATE ${library_references})

elseif (LINUX)

   target_compile_options(app_simple_drawing PRIVATE -fpermissive)
   #target_link_options(app_simple_drawing PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_drawing PRIVATE ${library_references})
   target_link_options(app_simple_drawing PRIVATE -Wl,-z,defs)

endif ()




target_link_directories(app_simple_drawing PRIVATE ${library_link_directories})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(app_simple_drawing PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_drawing PRIVATE _APP_SIMPLE_DRAWING_LIBRARY)


add_executable(_app_simple_drawing ${PLATFORM_NAME}/main.cpp)


target_compile_definitions(_app_simple_drawing PRIVATE _APP_ID="app-simple/drawing")


if (MSVC)

   target_compile_options(_app_simple_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(_app_simple_drawing PRIVATE ${library_references})

elseif (LINUX)

   target_compile_options(_app_simple_drawing PRIVATE -fpermissive)
   #target_link_options(_app_simple_drawing PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(_app_simple_drawing PRIVATE ${library_references})
   target_link_options(_app_simple_drawing PRIVATE -Wl,-z,defs)

endif ()


add_dependencies(_app_simple_drawing app_simple_drawing)
add_dependencies(_app_simple_drawing ${default_draw2d})
add_dependencies(_app_simple_drawing ${default_imaging})
add_dependencies(_app_simple_drawing ${default_write_text})
add_dependencies(_app_simple_drawing ${app_common_dependencies})


target_include_directories(_app_simple_drawing PRIVATE ${library_include_directories})

target_link_directories(_app_simple_drawing PRIVATE ${library_link_directories})

target_link_libraries(_app_simple_drawing PRIVATE acme apex)

set_target_properties(_app_simple_drawing PROPERTIES LINKER_LANGUAGE CXX)



