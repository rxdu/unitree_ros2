/* 
 * @file sports_mode_client_node.cpp
 * @date 1/28/25
 * @brief
 *
 * @copyright Copyright (c) 2025 Ruixiang Du (rdu)
 */

#include "unitree_driver/sports_mode_client.hpp"

int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<unitree::SportsModeClient>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}