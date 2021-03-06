cmake_minimum_required(VERSION 3.17)
project(app_simple_change_grub_default_entry CXX)


list(APPEND library_source
   _.cpp
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
   simple_change_grub_default_entry.cpp
   simple_change_grub_default_entry.h
   simple_change_grub_default_entry_001.h
   simple_change_grub_default_entry_002.h
   tab_view.cpp
   tab_view.h
   view.cpp
   view.h
   )

add_library(app_simple_change_grub_default_entry SHARED ${library_source})

target_precompile_headers(app_simple_change_grub_default_entry PRIVATE framework.h)

set_target_properties(app_simple_change_grub_default_entry PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
   target_compile_options(app_simple_change_grub_default_entry PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_change_grub_default_entry PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_change_grub_default_entry PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_change_grub_default_entry PRIVATE acme apex aqua aura axis base)
elseif (LINUX)
   target_compile_options(app_simple_change_grub_default_entry PRIVATE -fpermissive)
   #target_link_options(app_simple_change_grub_default_entry PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_change_grub_default_entry PRIVATE acme apex aqua aura axis base)
   target_link_options(app_simple_change_grub_default_entry PRIVATE -Wl,-z,defs)
endif ()






target_include_directories(app_simple_change_grub_default_entry PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_change_grub_default_entry PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_change_grub_default_entry PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_change_grub_default_entry PRIVATE _APP_SIMPLE_FORM_LIBRARY)






add_executable(_app_simple_change_grub_default_entry ${PLATFORM_NAME}/main.cpp)




if (MSVC)

   target_compile_options(_app_simple_change_grub_default_entry PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_change_grub_default_entry PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_libraries(_app_simple_change_grub_default_entry PRIVATE acme apex)
   target_link_libraries(_app_simple_change_grub_default_entry PRIVATE ${app_core_hellomultiverse_references} app_core_hellomultiverse)

elseif (LINUX)

   target_compile_options(_app_simple_change_grub_default_entry PRIVATE -fpermissive)
   #target_link_options(_app_simple_change_grub_default_entry PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(_app_simple_change_grub_default_entry PRIVATE acme apex)
   target_link_options(_app_simple_change_grub_default_entry PRIVATE -Wl,-z,defs)

endif ()


add_dependencies(_app_simple_change_grub_default_entry app_simple_change_grub_default_entry)
add_dependencies(_app_simple_change_grub_default_entry ${app_common_dependencies})
add_dependencies(_app_simple_change_grub_default_entry experience_tranquillum)
add_dependencies(_app_simple_change_grub_default_entry ${default_draw2d})
add_dependencies(_app_simple_change_grub_default_entry ${default_imaging})
add_dependencies(_app_simple_change_grub_default_entry ${default_write_text})
add_dependencies(_app_simple_change_grub_default_entry database_sqlite3)


target_include_directories(_app_simple_change_grub_default_entry PRIVATE ${library_include_directories})

target_link_directories(_app_simple_change_grub_default_entry PRIVATE ${library_link_directories})

set_target_properties(_app_simple_change_grub_default_entry PROPERTIES LINKER_LANGUAGE CXX)





