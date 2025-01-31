/* 
 * @file unitree_api_id.hpp
 * @date 1/31/25
 * @brief
 *
 * @copyright Copyright (c) 2025 Ruixiang Du (rdu)
 */
#ifndef UNITREE_API_ID_HPP
#define UNITREE_API_ID_HPP

namespace unitree {
enum class UnitreeApiId: int {
  kDamp = 1001,
  kBalanceStand = 1002,
  kStopMove = 1003,
  kStandUp = 1004,
  kStandDown = 1005,
  kRecoveryStand = 1006,
  kEuler = 1007,
  kMove = 1008,
  kSit = 1009,
  kRiseSit = 1010,
  kSwitchGait = 1011,
  kTrigger = 1012,
  kBodyHeight = 1013,
  kFootRaiseHeight = 1014,
  kSpeedLevel = 1015,
  kHello = 1016,
  kStretch = 1017,
  kTrajectoryFollow = 1018,
  kContinuousGait = 1019,
  kContent = 1020,
  kWallow = 1021,
  kDance1 = 1022,
  kDance2 = 1023,
  kGetBodyHeight = 1024,
  kGetFootRaiseHeight = 1025,
  kGetSpeedLevel = 1026,
  kSwitchJoystick = 1027,
  kPose = 1028,
  kScrape = 1029,
  kFrontFlip = 1030,
  kFrontJump = 1031,
  kFrontPounce = 1032,
};
}  // namespace unitree

#endif //UNITREE_API_ID_HPP
