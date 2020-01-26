#pragma once

#include <glfw/glfw3.h>

#include "Pch.h"
#include "Core.h"

namespace Engine {
	struct SWindowConfig {
		unsigned int width;
		unsigned int height;

		std::string title;
	};

	class CWindow final {
	public:
		CWindow(const SWindowConfig& config) noexcept;
		CWindow(const CWindow&) = delete;
		CWindow(CWindow&&) = delete;

		virtual ~CWindow() noexcept;

	public:
		CWindow& operator =(const CWindow&) = delete;

	public:
		inline GLFWwindow* WindowPtr() const noexcept { return mpWindow; }

	private:
		SWindowConfig mConfig;

		GLFWwindow* mpWindow = nullptr;
	};
}