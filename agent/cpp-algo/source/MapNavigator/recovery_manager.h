#pragma once

#include <cstdint>

#include "motion_controller.h"
#include "navigation_runtime_state.h"
#include "navigation_session.h"
#include "pose_estimator.h"
#include "route_tracker.h"

namespace mapnavigator
{

enum class RecoveryStatus {
    NotTriggered,
    InProgress,
    Recovered,
    RequestRejoin,
    TimeoutFailed
};

class RecoveryManager
{
public:
    static RecoveryStatus Tick(
        MotionController* motion_controller,
        NavigationSession* session,
        NavigationRuntimeState* runtime_state,
        const PoseEstimate& pose,
        const RouteTrackingState& route,
        int64_t stalled_ms);
};

} // namespace mapnavigator
