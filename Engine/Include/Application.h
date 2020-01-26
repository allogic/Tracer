#pragma once

#include "Window.h"

int main(int argc, char** argv);

namespace Engine {
	struct SApplicationConfig {
		int framesPerSecond;
		int computesPerSecond;

		SWindowConfig windowConfig;
	};

	class CApplication {
	protected:
		CApplication(const SApplicationConfig& config) noexcept;
		CApplication(const CApplication&) = delete;
		CApplication(CApplication&&) = delete;

		virtual ~CApplication() noexcept;

	protected:
		CApplication& operator =(const CApplication&) = delete;

	protected:
		virtual void OnPreRender() const noexcept {};
		virtual void OnRender(double deltaTime) const noexcept = 0;
		virtual void OnPostRender() const noexcept {};

		virtual void OnPreCompute() const noexcept {};
		virtual void OnCompute(double deltaTime) const noexcept = 0;
		virtual void OnPostCompute() const noexcept {};

	private:
		friend int ::main(int argc, char** argv);

		void Run() const noexcept;

	private:
		SApplicationConfig mConfig;
		CWindow mWindow;
	};
}

Engine::CApplication* Create();