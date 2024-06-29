cmake_minimum_required(VERSION 3.26)

project(oop2_project)
set(MY_AUTHORS "nir_busheri-itay_mijan-sagi_seri")

include(cmake/CompilerSettings.cmake)

add_executable(${CMAKE_PROJECT_NAME} WIN32)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(resources)
add_subdirectory(external/box2d/src)

include(cmake/Zip.cmake)

set(SFML_LOCATION "C:/SFML/SFML-2.6.0")
set(SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")

# Modified to include the audio component in addition to graphics
find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)

set_target_properties(sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

# Modified to link sfml-audio in addition to sfml-graphics and sfml-main
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-audio sfml-main)
target_link_libraries(${CMAKE_PROJECT_NAME} box2d)

include(cmake/SFML.cmake)

