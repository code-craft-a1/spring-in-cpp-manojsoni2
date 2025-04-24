#include "stats.h"

#include "gtest/gtest.h"
#include <cmath>

TEST(Statistics, ReportsAverageMinMax) {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.getAverage() - 4.525), epsilon);
    EXPECT_LT(std::abs(computedStats.getMax() - 8.9), epsilon);
    EXPECT_LT(std::abs(computedStats.getMin() - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    auto computedStats = Statistics::ComputeStatistics({});
    EXPECT_TRUE(std::isnan(computedStats.getAverage()));
    EXPECT_TRUE(std::isnan(computedStats.getMax()));
    EXPECT_TRUE(std::isnan(computedStats.getMin()));
}
