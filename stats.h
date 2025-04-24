#ifndef STATS_H
#define STATS_H

#include <vector>
#include <limits>

namespace Statistics {
    class Stats {
    public:
        Stats() : average(std::numeric_limits<float>::quiet_NaN()),
                 max(std::numeric_limits<float>::quiet_NaN()),
                 min(std::numeric_limits<float>::quiet_NaN()) {}
        
        // Getters
        const float& getAverage() const { return average; }
        const float& getMax() const { return max; }
        const float& getMin() const { return min; }
        
        void setStats(float avg, float maxVal, float minVal) {
            average = avg;
            max = maxVal;
            min = minVal;
        }
        
    private:
        float average;
        float max;
        float min;
    };

    Stats ComputeStatistics(const std::vector<float>& data);
}

#endif
