cmake_minimum_required(VERSION 3.17)
project(app_simple_form CXX)


list(APPEND app_simple_form_source
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
   main_view.cpp
   main_view.h
   simple_form.cpp
   simple_form.h
   tab_view.cpp
   tab_view.h
   view.cpp
   view.h
   )

add_executable(app_simple_form ${app_simple_form_source})

target_precompile_headers(app_simple_form PRIVATE framework.h)

set_target_properties(app_simple_form PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
   target_compile_options(app_simple_form PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   add_dependencies(app_simple_form draw2d_gdiplus imaging_wic)
elseif (LINUX)
   if(EXISTS $ENV{HOME}/__config/gnome.txt)
      add_dependencies(app_simple_form node_gnome)
   endif()
   if(EXISTS $ENV{HOME}/__config/kde.txt)
      add_dependencies(app_simple_form node_kde)
   endif()
   target_compile_options(app_simple_form PRIVATE -fpermissive)
   target_link_options(app_simple_form PRIVATE -Wl,-rpath=\$ORIGIN)
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   target_link_options(app_simple_form PRIVATE -Wl,-z,defs)
endif ()


add_dependencies(app_simple_form experience_tranquillum)
add_dependencies(app_simple_form ${default_draw2d})
add_dependencies(app_simple_form ${default_imaging})
add_dependencies(app_simple_form ${default_write_text})
add_dependencies(app_simple_form ${app_common_dependencies})



target_link_directories(app_simple_form PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/library/x64/basis)
target_link_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/storage-${PLATFORM_NAME}/third/library/x64/basis)


target_include_directories(app_simple_form PRIVATE .)
target_include_directories(app_simple_form PRIVATE $ENV{HOME}/__config)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME})
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/platform-${PLATFORM_NAME}/_include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../archive/third-${PLATFORM_NAME}/third/include/include)
target_include_directories(app_simple_form PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_form PRIVATE _APP_SIMPLE_FORM_LIBRARY)
target_compile_definitions(app_simple_form PRIVATE UNICODE)
target_compile_definitions(app_simple_form PRIVATE _UNICODE)



