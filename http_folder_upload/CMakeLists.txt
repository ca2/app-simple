cmake_minimum_required(VERSION 3.16)
project(app_simple_http_folder_upload CXX)



list(APPEND library_source
   _.cpp
   _.h
   ##_library.h
   #_factory.cpp
   application.cpp
   application.h
   command.cpp
   command.h
   command_document.cpp
   command_document.h
   command_list2.cpp
   command_list2.h
   computer_list2.cpp
   computer_list2.h
   document.cpp
   document.h
   framework.cpp
   framework.h
   frame.cpp
   frame.h
   interface_list2.cpp
   interface_list2.h
   main_frame.cpp
   main_frame.h
   main_impact.cpp
   main_impact.h
   tab_impact.cpp
   tab_impact.h
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
else ()
   set(LIBCXX_TARGETING_MSVC OFF)
endif ()


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(app_simple_http_folder_upload PROPERTIES LINKER_LANGUAGE CXX)


list(APPEND app_simple_http_folder_upload_references
   acme
   apex
   aqua
   aura
   axis
   base
   bred
   core
   )

if (MSVC)
   target_compile_options(app_simple_http_folder_upload PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_http_folder_upload PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_http_folder_upload PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_http_folder_upload PRIVATE ${app_simple_http_folder_upload_references})
   add_dependencies(app_simple_http_folder_upload draw2d_gdiplus imaging_wic)
elseif(${LINUX} OR ${FREEBSD})
   target_compile_options(app_simple_http_folder_upload PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   #target_link_options(app_simple_http_folder_upload PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_http_folder_upload PRIVATE ${app_simple_http_folder_upload_references})
   target_link_options(app_simple_http_folder_upload PRIVATE -Wl,-z,defs)
   add_dependencies(app_simple_http_folder_upload draw2d_cairo imaging_freeimage)
endif ()

add_dependencies(app_simple_http_folder_upload experience_core)
add_dependencies(app_simple_http_folder_upload networking_bsd)

list(APPEND library_link_directories
   ${LIBRARY_OUTPUT_PATH}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis
   )


target_link_directories(app_simple_http_folder_upload PRIVATE ${library_link_directories})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})




list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})



target_compile_definitions(app_simple_http_folder_upload PRIVATE _APP_SIMPLE_DRAWING_LIBRARY)
target_compile_definitions(app_simple_http_folder_upload PRIVATE UNICODE)
target_compile_definitions(app_simple_http_folder_upload PRIVATE _UNICODE)



add_subdirectory(__implement)

