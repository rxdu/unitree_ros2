/*
 * @file sports_mode_client.hpp
 * @date 1/27/25
 * @brief
 *
 * @copyright Copyright (c) 2025 Ruixiang Du (rdu)
 */

#ifndef SPORTS_MODE_CLIENT_HPP
#define SPORTS_MODE_CLIENT_HPP

#include <rclcpp/rclcpp.hpp>

#include <sensor_msgs/msg/joint_state.hpp>

#include "unitree_api/msg/request.hpp"
#include "unitree_api/msg/response.hpp"
#include "unitree_go/msg/low_state.hpp"
#include "unitree_go/msg/sport_mode_state.hpp"

#include "unitree_driver/unitree_api_id.hpp"

namespace unitree {
class SportsModeClient : public rclcpp::Node {
 public:
  SportsModeClient();

 private:
  static constexpr auto kLowStateTopic = "lowstate";
  static constexpr auto kSportsModeStateTopic = "sportmodestate";
  static constexpr auto kRequestTopic = "/api/sport/request";
  static constexpr auto kResponseTopic = "/api/sport/response";

  void HandleLowLevelState(const unitree_go::msg::LowState::SharedPtr msg);
  void HandleSportsModeState(
      const unitree_go::msg::SportModeState::SharedPtr msg);

  void SendApiRequest(UnitreeApiId api_id, uint32_t timeout_ms = 500);
  void HandleApiResponse();

  void PublishJointStates();

  // publisher/subscriber for Unitree API
  rclcpp::Subscription<unitree_go::msg::LowState>::SharedPtr ll_state_sub_;
  rclcpp::Subscription<unitree_go::msg::SportModeState>::SharedPtr
      sm_state_sub_;
  rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_pub_;
  rclcpp::Subscription<unitree_api::msg::Response>::SharedPtr res_sub_;

  // publisher/subscriber for ROS-facing interface
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
};
}  // namespace unitree

#endif  // SPORTS_MODE_CLIENT_HPP