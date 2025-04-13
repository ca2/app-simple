cmake_minimum_required(VERSION 3.16)
project(app_simple_winnfsd_desktop CXX)



list(APPEND library_source
   _.cpp
   _.h
   ##_library.h
   #_factory.cpp
   application.cpp
   application.h
   command.cpp
   command.h
   document.cpp
   document.h
   edit_impact.cpp
   edit_impact.h
   framework.cpp
   framework.h
   frame.cpp
   frame.h
   impact.cpp
   impact.h
   incoming_socket_thread.cpp
   incoming_socket_thread.h
   incoming_socket.cpp
   incoming_socket.h
   main_document.cpp
   main_document.h
   main_frame.cpp
   main_frame.h
   main_impact.cpp
   main_impact.h
   socket.cpp
   socket.h
   tab_impact.cpp
   tab_impact.h
   )


if (MSVC)
   set(LIBCXX_TARGETING_MSVC ON)
endif ()


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})

target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


list(APPEND library_references
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
   target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${global_library_references})
   add_dependencies(${PROJECT_NAME} draw2d_gdiplus imaging_wic)
elseif(${LINUX} OR ${__BSD__})
   target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
   #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} ${global_library_references})
   target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
   add_dependencies(${PROJECT_NAME} draw2d_cairo imaging_freeimage)
endif ()

add_dependencies(${PROJECT_NAME} experience_core)
add_dependencies(${PROJECT_NAME} networking_bsd)

list(APPEND library_link_directories
   ${LIBRARY_OUTPUT_PATH}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis
   )


target_link_directories(${PROJECT_NAME} PRIVATE ${library_link_directories})


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



target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)
target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE)



add_subdirectory(__implement)

