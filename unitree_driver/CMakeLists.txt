cmake_minimum_required(VERSION 3.5)
project(unitree_driver)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

## set C/C++ standard
# default to C99
if (NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif ()

# default to C++14
if (NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif ()

## find dependencies
find_package(ament_cmake REQUIRED)

set(dependencies
    rclcpp
    std_msgs
    unitree_go
    unitree_hg
    unitree_api)
foreach (dep IN ITEMS ${dependencies})
  find_package(${dep} REQUIRED)
endforeach ()

# add targets
add_library(${PROJECT_NAME}
    src/motor_utils.cpp
    src/motor_crc.cpp
    src/motor_crc_hg.cpp
    src/ros2_sport_client.cpp)
ament_target_dependencies(${PROJECT_NAME} ${dependencies})
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/json/include>"
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
    PRIVATE src)

## install and export configuration
install(TARGETS ${PROJECT_NAME}
    EXPORT export_${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin)

install(DIRECTORY include/
    DESTINATION include/${PROJECT_NAME})

add_subdirectory(test)

## testing configuration
if (BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif ()

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(${dependencies})

ament_package()
