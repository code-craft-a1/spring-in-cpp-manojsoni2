#include "stats.h"
#include <algorithm>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    Stats stats;  // Will be initialized with NaN values
    
    if (data.empty()) {
        return stats;  // Returns with NaN values
    }
    
    float sum = 0;
    float currentMin = data[0];
    float currentMax = data[0];
    
    for (const float& num : data) {
        sum += num;
        currentMin = std::min(currentMin, num);
        currentMax = std::max(currentMax, num);
    }
    
    float average = sum / static_cast<float>(data.size());
    stats.setStats(average, currentMax, currentMin);
    return stats;
}
