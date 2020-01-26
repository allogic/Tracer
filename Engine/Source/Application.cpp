#include "Application.h"

Engine::CApplication::CApplication(const SApplicationConfig& config) noexcept :
	mConfig(config),
	mWindow(config.windowConfig) {

}

Engine::CApplication::~CApplication() noexcept {
	glfwTerminate();
}

void Engine::CApplication::Run() const noexcept {
	if (!mWindow.WindowPtr()) return;

	glfwSetWindowUserPointer(mWindow.WindowPtr(), nullptr);

	double time = 0.;
	double prevTime = 0.;

	double deltaTime = 0.;

	const double computeRate = 1. / mConfig.computesPerSecond;
	double prevComputeTime = 0.;

	const double renderRate = 1. / mConfig.framesPerSecond;
	double prevRenderTime = 0.;

	while (!glfwWindowShouldClose(mWindow.WindowPtr())) {
		time = glfwGetTime();

		deltaTime = time - prevTime;

		if ((time - prevRenderTime) >= renderRate) {
			glClearColor(0.f, 0.f, .1f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);

			OnPreRender();
			OnRender(deltaTime);
			OnPostRender();

			glfwSwapBuffers(mWindow.WindowPtr());

			prevRenderTime = time;
		}

		if ((time - prevComputeTime) >= computeRate) {
			OnPreCompute();
			OnCompute(deltaTime);
			OnPostCompute();

			prevComputeTime = time;
		}

		prevTime = time;

		glfwPollEvents();
	}
}