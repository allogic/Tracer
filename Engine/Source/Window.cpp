#include <glad/glad.h>

#include "Window.h"

Engine::CWindow::CWindow(const SWindowConfig& config) noexcept :
	mConfig(config) {
	if (!glfwInit()) {
		ENGINE_ERROR("Failed initializing glfw");

		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_SAMPLES, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mpWindow = glfwCreateWindow(static_cast<int>(mConfig.width), static_cast<int>(mConfig.height), mConfig.title.c_str(), nullptr, nullptr);

	if (!mpWindow) {
		ENGINE_ERROR("Failed creating window");

		return;
	}

	glfwMakeContextCurrent(mpWindow);
	//glfwSetWindowSizeCallback(mpWindow, glfwWindowSizeCallback);

	if (!gladLoadGL()) {
		ENGINE_ERROR("Failed loading gl");

		glfwDestroyWindow(mpWindow);

		return;
	}
}

Engine::CWindow::~CWindow() noexcept {
	glfwDestroyWindow(mpWindow);
}