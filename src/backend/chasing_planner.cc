/*******************************************************************************
 *
 * Copyright 2023 Boseong Felipe Jeon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *******************************************************************************/

#include "my_robotics_library/backend/planners/chasing_planner.h"
#include "chrono"

using namespace my_robotics_library;
using namespace my_robotics_library::backend;
using namespace std::chrono;

ChasingMotionPlanningResult::ChasingMotionPlanningResult(
    my_robotics_library::TimedPosition target_position)
    : MotionPlanningResult(
          MotionPhase::kChasing,
          duration<double>(system_clock::now().time_since_epoch()).count()),
      planned_view_position_(target_position) {}

Control ChasingMotionPlanningResult::GenerateControl(double t) const {
  Control control;
  control.phase = GetMotionType();
  control.t = t;
  control.input = planned_view_position_.x;
  return control;
}

std::vector<TimedPosition>
ChasingMotionPlanningResult::GetPlanningTrajectory(double t0, double tf) const {
  return {};
}

ChasingMotionPlanningResult ChasingPlanner::ComputeChasingMotion(
    const my_robotics_library::backend::ChasingPlannerInput &planner_input) {
  return ChasingMotionPlanningResult(planner_input.target_position);
}
