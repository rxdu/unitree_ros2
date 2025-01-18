/*
 * @file motor_utils.hpp
 * @date 1/19/25
 * @brief
 *
 * @copyright Copyright (c) 2025 Ruixiang Du (rdu)
 */

#ifndef MOTOR_UTILS_HPP
#define MOTOR_UTILS_HPP

#include "unitree_go/msg/low_cmd.hpp"
#include "unitree_hg/msg/low_cmd.hpp"

namespace unitree {
namespace motor_utils {
constexpr int HIGHLEVEL = 0xee;
constexpr int LOWLEVEL = 0xff;
constexpr int TRIGERLEVEL = 0xf0;
constexpr double PosStopF = (2.146E+9f);
constexpr double VelStopF = (16000.0f);

// joint index
constexpr int FR_0 = 0;
constexpr int FR_1 = 1;
constexpr int FR_2 = 2;

constexpr int FL_0 = 3;
constexpr int FL_1 = 4;
constexpr int FL_2 = 5;

constexpr int RR_0 = 6;
constexpr int RR_1 = 7;
constexpr int RR_2 = 8;

constexpr int RL_0 = 9;
constexpr int RL_1 = 10;
constexpr int RL_2 = 11;

void CalculateAndSetGoCrc(unitree_go::msg::LowCmd& msg);
void CalculateAndSetHGCrc(unitree_hg::msg::LowCmd& msg);
}  // namespace MotorUtils
}  // namespace unitree

#endif  // MOTOR_UTILS_HPP