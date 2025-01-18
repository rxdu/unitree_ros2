/*
 * @file motor_utils.cpp
 * @date 1/19/25
 * @brief
 *
 * @copyright Copyright (c) 2025 Ruixiang Du (rdu)
 */

#include "unitree_driver/motor_utils.hpp"

#include <motor_crc.h>
#include <motor_crc_hg.h>

namespace unitree {
void motor_utils::CalculateAndSetGoCrc(unitree_go::msg::LowCmd& msg) {
  go_motor_crc::get_crc(msg);
}

void motor_utils::CalculateAndSetHGCrc(unitree_hg::msg::LowCmd& msg) {
  hg_motor_crc::get_crc(msg);
}
}  // namespace unitree