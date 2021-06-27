#include "Window.h"

bool Window::s_glfwInitialized{ false }; 

Window::Window(unsigned int width, unsigned int height, std::string& name) {
	props.width = width;
	props.height = height;
	props.name = name;
	init();
}

Window::~Window() {
	shutdown();
}

void Window::init() {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	if (!s_glfwInitialized) {
		int success = glfwInit();
		assert(success && "Could not initializ GLFW");
		s_glfwInitialized = true;
	}
	window = glfwCreateWindow(props.width, props.height, props.name.c_str(), nullptr, nullptr);
	makeCurrent();
	glfwSetWindowUserPointer(window, &props);
	setVSync(true);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
	}

}
 
void Window::makeCurrent() {
	glfwMakeContextCurrent(window);
}

void Window::shutdown() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::update() {
	glfwPollEvents();
	glfwSwapBuffers(window);
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(window);
}

void Window::clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setVSync(bool enabled) {
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);
	props.vSyncEnabled = enabled;
}

bool Window::isVSync() const {
	return props.vSyncEnabled;
}