// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/adb

#include <ne_app/core/pdf.hpp>

static void GT_ReadPDF(void) {
  std::vector<std::string> paths;

  paths.emplace_back("short.pdf");
  paths.emplace_back("long.pdf");
  paths.emplace_back("very_long.pdf");
  paths.emplace_back("invalid.pdf");

  for (const auto& fmt : paths) {
    ne_app::pdf::render(fmt.c_str(), fmt.size());
  }
}
