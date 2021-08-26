cmake_minimum_required(VERSION 3.17)
project(app_simple_form CXX)


list(APPEND library_source
   _.h
   001.cpp
   002.cpp
   application.cpp
   application.h
   document.cpp
   document.h
   frame.cpp
   frame.h
   framework.cpp
   framework.h
   main_frame.cpp
   main_frame.h
   main_impact.cpp
   main_impact.h
   simple_form.cpp
   simple_form.h
   tab_view.cpp
   tab_view.h
   impact.cpp
   impact.h
   )

add_executable(app_simple_form ${library_source})

target_precompile_headers(app_simple_form PRIVATE framework.h)

set_target_properties(app_simple_form PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
   target_compile_options(app_simple_form PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   add_dependencies(app_simple_form draw2d_gdiplus imaging_wic)
elseif (LINUX)
   target_compile_options(app_simple_form PRIVATE -fpermissive)
   #target_link_options(app_simple_form PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   target_link_options(app_simple_form PRIVATE -Wl,-z,defs)
endif ()


add_dependencies(app_simple_form experience_tranquillum)
add_dependencies(app_simple_form ${default_draw2d})
add_dependencies(app_simple_form ${default_imaging})
add_dependencies(app_simple_form ${default_write_text})
add_dependencies(app_simple_form ${app_common_dependencies})
add_dependencies(app_simple_form database_sqlite3)
add_dependencies(app_simple_form regular_expression_pcre2)




target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_form PRIVATE _APP_SIMPLE_FORM_LIBRARY)



