#pragma once

#define ENGINE_INFO(MSG) std::cout << MSG << std::endl;
#define ENGINE_ERROR(MSG) std::cerr << MSG << std::endl;

#define BEGIN_TIMED_SCOPE(curr, prev, rate) if ((curr - prev) >= rate) {
#define END_TIMED_SCOPE(curr, prev) prev = curr; }