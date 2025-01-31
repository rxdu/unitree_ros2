/*
 * @file sports_mode_client.cpp
 * @date 1/27/25
 * @brief
 *
 * @copyright Copyright (c) 2025 Ruixiang Du (rdu)
 */

#include "unitree_driver/sports_mode_client.hpp"

#include "unitree_robot_api_id.hpp"

namespace unitree {
SportsModeClient::SportsModeClient() : Node("sports_mode_client") {
  // set up user-facing interface
  joint_state_pub_ =
      create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

  // set up unitree interface
  ll_state_sub_ = this->create_subscription<unitree_go::msg::LowState>(
      kLowStateTopic, 10,
      std::bind(&SportsModeClient::HandleLowLevelState, this,
                std::placeholders::_1));

  sm_state_sub_ = this->create_subscription<unitree_go::msg::SportModeState>(
      kSportsModeStateTopic, 10,
      std::bind(&SportsModeClient::HandleSportsModeState, this,
                std::placeholders::_1));

  req_pub_ =
      this->create_publisher<unitree_api::msg::Request>(kRequestTopic, 10);

  res_sub_ = this->create_subscription<unitree_api::msg::Response>(
      kResponseTopic, 10,
      [this](const unitree_api::msg::Response::SharedPtr msg) {
        // process response message
      });
}

void SportsModeClient::HandleLowLevelState(
    const unitree_go::msg::LowState::SharedPtr msg) {
  // process low state message
  sensor_msgs::msg::JointState joint_state;
  joint_state.header.stamp = now();
  joint_state.name = {"FR_hip_joint", "FR_thigh_joint", "FR_calf_joint",
                      "FL_hip_joint", "FL_thigh_joint", "FL_calf_joint",
                      "RR_hip_joint", "RR_thigh_joint", "RR_calf_joint",
                      "RL_hip_joint", "RL_thigh_joint", "RL_calf_joint"};

  joint_state.position = {
      msg->motor_state[0].q, msg->motor_state[1].q,  msg->motor_state[2].q,
      msg->motor_state[3].q, msg->motor_state[4].q,  msg->motor_state[5].q,
      msg->motor_state[6].q, msg->motor_state[7].q,  msg->motor_state[8].q,
      msg->motor_state[9].q, msg->motor_state[10].q, msg->motor_state[11].q};
  joint_state.velocity = {
      msg->motor_state[0].dq, msg->motor_state[1].dq,  msg->motor_state[2].dq,
      msg->motor_state[3].dq, msg->motor_state[4].dq,  msg->motor_state[5].dq,
      msg->motor_state[6].dq, msg->motor_state[7].dq,  msg->motor_state[8].dq,
      msg->motor_state[9].dq, msg->motor_state[10].dq, msg->motor_state[11].dq};

  joint_state_pub_->publish(joint_state);
}

void SportsModeClient::HandleSportsModeState(
    const unitree_go::msg::SportModeState::SharedPtr msg) {}
}  // namespace unitree
