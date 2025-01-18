add_executable(low_level_ctrl low_level_ctrl.cpp)
target_link_libraries(low_level_ctrl ${PROJECT_NAME})

add_executable(low_level_ctrl_hg h1-2/lowlevel/low_level_ctrl_hg.cpp)
target_link_libraries(low_level_ctrl_hg ${PROJECT_NAME})

add_executable(g1_low_level_example g1/lowlevel/g1_low_level_example.cpp)
target_link_libraries(g1_low_level_example ${PROJECT_NAME})

add_executable(read_low_state read_low_state.cpp)
target_link_libraries(read_low_state ${PROJECT_NAME})

add_executable(read_low_state_hg read_low_state_hg.cpp)
target_link_libraries(read_low_state_hg ${PROJECT_NAME})

add_executable(read_motion_state read_motion_state.cpp)
target_link_libraries(read_motion_state ${PROJECT_NAME})

add_executable(read_wireless_controller read_wireless_controller.cpp)
target_link_libraries(read_wireless_controller ${PROJECT_NAME})

#add_executable(record_bag src/record_bag.cpp)
#target_link_libraries(record_bag ${PROJECT_NAME})

add_executable(sport_mode_ctrl sport_mode_ctrl.cpp)
target_link_libraries(sport_mode_ctrl ${PROJECT_NAME})

#install(TARGETS
#    low_level_ctrl
#    low_level_ctrl_hg
#    g1_low_level_example
#    read_low_state
#    read_low_state_hg
#    read_motion_state
#    read_wireless_controller
#    sport_mode_ctrl
#    DESTINATION)