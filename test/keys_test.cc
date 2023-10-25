#include "gtest/gtest.h"

#include "transfers/transfer/transfer_result.h"
#include "transfers/types.h"

#include "geo/latlng.h"

TEST(keys, zerocoord) {
  using namespace transfers;

  auto zero = geo::latlng{0.0, 0.0};
  // 0x0 || 0x0
  ASSERT_EQ(to_key(zero), 0x0);
}

TEST(keys, nonzeroposlat) {
  using namespace transfers;

  auto nonzeroposlat = geo::latlng{1.0, 0.0};
  // 0x3F800000 || 0x0
  ASSERT_EQ(to_key(nonzeroposlat), 0x3f80000000000000);
}

TEST(keys, nonzeroneglat) {
  using namespace transfers;

  auto nonzeroneglat = geo::latlng{-1.0, 0.0};
  // 0xBF800000 || 0x0
  ASSERT_EQ(to_key(nonzeroneglat), 0xbf80000000000000);
}

TEST(keys, nonzeroposlng) {
  using namespace transfers;

  auto nonzeroposlng = geo::latlng{0.0, 1.0};
  // 0x0 || 0x3F800000
  ASSERT_EQ(to_key(nonzeroposlng), 0x000000003f800000);
}

TEST(keys, nonzeroneglng) {
  using namespace transfers;

  auto nonzeroneglng = geo::latlng{0.0, -1.0};
  // 0x0 || 0xBF800000
  ASSERT_EQ(to_key(nonzeroneglng), 0x00000000bf800000);
}

TEST(keys, nonzerolatlng) {
  using namespace transfers;

  auto nonzeroneglng = geo::latlng{1.0, 2.0};
  // 0x3F800000 || 0x40000000
  ASSERT_EQ(to_key(nonzeroneglng), 0x3f80000040000000);
}
