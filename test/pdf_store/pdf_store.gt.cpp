// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/adb

#include <ne_app/core/pdf.hpp>
#include <ne_app/tasks/tasks.hpp>
#include <gtest/gtest.h>

TEST(pdf, GT_ReadPDF) {
  std::vector<std::string> paths;

  paths.emplace_back("short.pdf");
  paths.emplace_back("long.pdf");
  paths.emplace_back("very_long.pdf");
  paths.emplace_back("invalid.pdf");

  std::size_t i = 0;
  std::array<ne_app::tasks::task_tag, 4> tasks;

  for (const auto& fmt : paths) {
    ne_app::tasks::task_tag& t = tasks[i];
    ne_app::tasks::run<void(std::atomic_flag&)>(
        [&fmt](std::atomic_flag& flg) {
          ne_app::pdf::render(fmt.c_str(), fmt.size());
        },
        t);
    ++i;
  }
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
