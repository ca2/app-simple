cmake_minimum_required(VERSION 3.16)
project(app_simple_form CXX)


list(APPEND library_source
   _.cpp
   _.h
   _library.h
   _factory.cpp
   application.cpp
   application.h
   document.cpp
   document.h
   form.cpp
   form.h
   form_001.cpp
   form_001.h
   form_002.cpp
   form_002.h
   frame.cpp
   frame.h
   impact.cpp
   impact.h
   framework.cpp
   framework.h
   main_frame.cpp
   main_frame.h
   main_impact.cpp
   main_impact.h
   tab_view.cpp
   tab_view.h
   )


add_library(app_simple_form ${library_source})


target_precompile_headers(app_simple_form PRIVATE framework.h)


set_target_properties(app_simple_form PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
   target_compile_options(app_simple_form PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_form PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   add_dependencies(app_simple_form draw2d_gdiplus imaging_wic)
elseif(LINUX OR FREEBSD)
   target_compile_options(app_simple_form PRIVATE -fpermissive)
   #target_link_options(app_simple_form PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_form PRIVATE acme apex aqua aura axis base)
   target_link_options(app_simple_form PRIVATE -Wl,-z,defs)
endif ()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_form PRIVATE _APP_SIMPLE_FORM_LIBRARY)


add_executable(_${PROJECT_NAME} _main.cpp)


list(APPEND executable_references
   acme
   apex
   aqua
   aura
   axis
   base
   app_simple_form)

if(LINUX OR FREEBSD)
#
#   add_custom_command(
#      COMMAND ${APPLICATION_BUILD_HELPER} ${PROJECT_SOURCE_DIR}
#      COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_BINARY_DIR}/matter.timestamp
#      OUTPUT ${PROJECT_BINARY_DIR}/matter.timestamp
#      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
#      BYPRODUCTS ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o
#      DEPENDS application_matter.txt matter.txt _console_application_build_helper
#      VERBATIM
#      )
#
#   add_custom_target(${PROJECT_NAME}_matter
#      DEPENDS ${PROJECT_BINARY_DIR}/matter.timestamp
#   )
#
list(APPEND executable_references ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o)
#
#   add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_matter)
#
endif()


if (MSVC)

   target_compile_options(_app_simple_form PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_form PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_form PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(_app_simple_form PRIVATE ${executable_references})

elseif(LINUX OR FREEBSD)

   target_compile_options(_app_simple_form PRIVATE -fpermissive)
   target_link_libraries(_app_simple_form PRIVATE ${executable_references})
   target_link_options(_app_simple_form PRIVATE -Wl,-z,defs)

endif ()


add_dependencies(_${PROJECT_NAME} ${app_common_dependencies})
add_dependencies(_${PROJECT_NAME} ${default_draw2d})
add_dependencies(_${PROJECT_NAME} ${default_imaging})
add_dependencies(_${PROJECT_NAME} ${default_write_text})
add_dependencies(_${PROJECT_NAME} ${default_node})
add_dependencies(_${PROJECT_NAME} crypto_openssl)
add_dependencies(_${PROJECT_NAME} database_sqlite3)
add_dependencies(_${PROJECT_NAME} experience_tranquillum)
add_dependencies(_${PROJECT_NAME} folder_zip)


target_include_directories(_app_simple_form PRIVATE ${library_include_directories})

target_link_directories(_app_simple_form PRIVATE ${library_link_directories})

set_target_properties(_app_simple_form PROPERTIES LINKER_LANGUAGE CXX)



