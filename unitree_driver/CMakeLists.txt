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
include_directories(include include/common include/nlohmann)
link_directories(src)

add_executable(low_level_ctrl src/low_level_ctrl.cpp src/common/motor_crc.cpp)
ament_target_dependencies(low_level_ctrl ${dependencies})

add_executable(low_level_ctrl_hg src/h1-2/lowlevel/low_level_ctrl_hg.cpp src/common/motor_crc_hg.cpp)
ament_target_dependencies(low_level_ctrl_hg ${dependencies})

add_executable(g1_low_level_example src/g1/lowlevel/g1_low_level_example.cpp src/common/motor_crc_hg.cpp)
ament_target_dependencies(g1_low_level_example ${dependencies})

add_executable(read_low_state src/read_low_state.cpp)
ament_target_dependencies(read_low_state ${dependencies})

add_executable(read_low_state_hg src/read_low_state_hg.cpp)
ament_target_dependencies(read_low_state_hg ${dependencies})

add_executable(read_motion_state src/read_motion_state.cpp)
ament_target_dependencies(read_motion_state ${dependencies})

add_executable(read_wireless_controller src/read_wireless_controller.cpp)
ament_target_dependencies(read_wireless_controller ${dependencies})

#add_executable(record_bag src/record_bag.cpp)
#ament_target_dependencies(record_bag ${dependencies})

add_executable(sport_mode_ctrl src/sport_mode_ctrl.cpp src/common/ros2_sport_client.cpp)
ament_target_dependencies(sport_mode_ctrl ${dependencies})

install(TARGETS
    low_level_ctrl
    low_level_ctrl_hg
    g1_low_level_example
    read_low_state
    read_low_state_hg
    read_motion_state
    read_wireless_controller
    sport_mode_ctrl
    DESTINATION)

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

#ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(${dependencies})

ament_package()
