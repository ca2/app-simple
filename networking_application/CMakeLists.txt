cmake_minimum_required(VERSION 3.16)
project(app_simple_networking_application CXX)



list(APPEND library_source
   _.h
   _app_simple_networking_application.h
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
   tab_view.cpp
   tab_view.h
   impact.cpp
   impact.h
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
else ()
   set(LIBCXX_TARGETING_MSVC OFF)
endif ()


add_library(app_simple_networking_application SHARED ${library_source})

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

list(APPEND library_link_directories
   ${LIBRARY_OUTPUT_PATH}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating-system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating-system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis
   )


target_link_directories(app_simple_networking_application PRIVATE ${library_link_directories})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})



target_include_directories(app_simple_networking_application PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_networking_application PRIVATE _APP_SIMPLE_DRAWING_LIBRARY)
target_compile_definitions(app_simple_networking_application PRIVATE UNICODE)
target_compile_definitions(app_simple_networking_application PRIVATE _UNICODE)



add_executable(_${PROJECT_NAME} operating-system/${SLASHED_OPERATING_SYSTEM}/_${PROJECT_NAME}.cpp)
target_compile_definitions(_app_simple_networking_application PRIVATE UNICODE)
target_compile_definitions(_app_simple_networking_application PRIVATE _UNICODE)


list(APPEND executable_references
   acme
   apex
   aqua
   aura
   axis
   base
   app_simple_networking_application)


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
   

   target_compile_options(_app_simple_networking_application PRIVATE "/D_APP_ID=\"app-simple/drawing\"")
   target_compile_options(_app_simple_networking_application PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_networking_application PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_networking_application PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(_app_simple_networking_application PRIVATE ${executable_references})
   add_dependencies(_app_simple_networking_application draw2d_gdiplus imaging_wic)


elseif(LINUX OR FREEBSD)


   target_compile_options(_app_simple_networking_application PRIVATE -fpermissive)
   #target_link_options(_app_simple_networking_application PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(_app_simple_networking_application PRIVATE ${executable_references})
   target_link_options(_app_simple_networking_application PRIVATE -Wl,-z,defs)
   add_dependencies(_app_simple_networking_application draw2d_cairo imaging_freeimage)


endif ()


add_dependencies(_${PROJECT_NAME} ${PROJECT_NAME})
add_dependencies(_${PROJECT_NAME} ${default_draw2d})
add_dependencies(_${PROJECT_NAME} ${default_write_text})
add_dependencies(_${PROJECT_NAME} ${default_node})
add_dependencies(_${PROJECT_NAME} ${app_common_dependencies})
add_dependencies(_${PROJECT_NAME} crypto_openssl)
add_dependencies(_${PROJECT_NAME} experience_core)
add_dependencies(_${PROJECT_NAME} folder_zip)


target_include_directories(_app_simple_networking_application PRIVATE ${library_include_directories})

target_link_directories(_app_simple_networking_application PRIVATE ${library_link_directories})

target_link_libraries(_app_simple_networking_application PRIVATE acme apex aqua aura axis base app_simple_networking_application)

set_target_properties(_app_simple_networking_application PROPERTIES LINKER_LANGUAGE CXX)