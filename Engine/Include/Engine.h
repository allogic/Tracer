#include <glad/glad.h>

#include "Application.h"

extern Engine::CApplication* Create();

int main(int argc, char** argv) {
	auto* app = Create();

	app->Run();

	delete app;
}