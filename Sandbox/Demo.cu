#include <iostream>

#include <Engine.h>

using namespace Engine;

const SApplicationConfig config{ 60,	1,	{ 1280, 720, "Demo" } };

class CSandbox final : public CApplication {
public:
	CSandbox() noexcept : CApplication(config) {
		std::cout << "created" << std::endl;
	}

	~CSandbox() noexcept override {
		std::cout << "destroyed" << std::endl;
	}

public:
	void OnRender(double deltaTime) const noexcept override {
		std::cout << "render" << std::endl;
	}

	void OnCompute(double deltaTime) const noexcept override {
		std::cout << "compute" << std::endl;
	}
};

CApplication* Create() { return new CSandbox(); }