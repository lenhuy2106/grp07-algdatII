/**
 * Unit Tests with Google Test Framework.
 *
 * 01.08.2016
 */

#include "gtest/gtest.h"
#include "Naive.h"
#include "KnuthMorrisPratt.h"

using namespace std;

TEST(naiveAlgorithm, run) {
    vector<int> firstIndices = Naive("lorem ipsum alta ipsum fef", "ipsum").run();

    ASSERT_EQ(6, firstIndices.at(0));
    ASSERT_EQ(17, firstIndices.at(1));

    ASSERT_NE(7, firstIndices.at(0));
    ASSERT_NE(19, firstIndices.at(1));

    ASSERT_ANY_THROW(firstIndices.at(2));
}

TEST(kmpAlgorithm, run) {
    vector<int> firstIndices = Naive("lorem ipsum alta ipsum fef", "ipsum").run();

    ASSERT_EQ(6, firstIndices.at(0));
    ASSERT_EQ(17, firstIndices.at(1));

    ASSERT_NE(7, firstIndices.at(0));
    ASSERT_NE(19, firstIndices.at(1));

    ASSERT_ANY_THROW(firstIndices.at(2));
}
