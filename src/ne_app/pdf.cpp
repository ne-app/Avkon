// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/adb

#include <atomic>
#include <ne_app/core/pdf.hpp>

#ifndef NEAPP_PDF_MAGIC
#define NEAPP_PDF_MAGIC "%PDF_2."
#endif

/// @brief Is the PDF pair valid?
bool ne_app::pdf_pair::is_valid(ne_app::pdf_pair::key_type& key) noexcept {
  if (key.empty()) return false;

  return key.starts_with(NEAPP_PDF_MAGIC);
}

/// @brief Write to store.
ne_app::core::stream_type& operator<<(
    ne_app::core::stream_type& os,
    ne_app::core::storage_object<ne_app::pdf_pair>& obj) {
  if (!obj.is_valid(obj.key_)) ne_app::core::throw_pdf_error();
  if (obj.value_.bad()) ne_app::core::throw_pdf_error();

  static std::atomic_flag flg = ATOMIC_FLAG_INIT;
  
  while (!flg.test_and_set(std::memory_order_acquire));

  os << obj.value_.str();

  flg.clear(std::memory_order_release);

  return os;
}

/// @brief Read from store.
ne_app::core::stream_type& operator>>(
    ne_app::core::stream_type& is,
    ne_app::core::storage_object<ne_app::pdf_pair>& obj) {
  if (!obj.is_valid(obj.key_)) ne_app::core::throw_pdf_error();
  if (obj.value_.bad()) ne_app::core::throw_pdf_error();

  if (obj.value_.eof()) ne_app::core::throw_pdf_error();

  static std::atomic_flag flg = ATOMIC_FLAG_INIT;

  while (!flg.test_and_set(std::memory_order_acquire));

  ne_app::core::stream_type tmp_is;
  tmp_is >> obj.value_.rdbuf();

  is >> tmp_is.rdbuf();

  obj.value_ << is.str();

  flg.clear(std::memory_order_release);

  return is;
}
