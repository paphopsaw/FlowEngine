#include "Window.h"

Window::Window(const std::string& name, unsigned int width, unsigned int height) {
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
	int success = glfwInit();
	assert(success && "Could not initializ GLFW");
	m_window = glfwCreateWindow(props.width, props.height, props.name.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, &props);
	setVSync(true);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
	}

	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
		WindowProps& props = *(WindowProps*)glfwGetWindowUserPointer(window);
		WindowResizeEvent e(width, height);
		props.callback(e);
	});

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
		WindowProps& props = *(WindowProps*)glfwGetWindowUserPointer(window);
		WindowCloseEvent e;
		props.callback(e);
	});

	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		WindowProps& props = *(WindowProps*)glfwGetWindowUserPointer(window);
		switch (action) {
		case GLFW_PRESS:
		{
			KeyPressedEvent e(static_cast<KeyCode>(key));
			props.callback(e);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent e(static_cast<KeyCode>(key));
			props.callback(e);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyRepeatedEvent e(static_cast<KeyCode>(key));
			props.callback(e);
			break;
		}
		}
	});

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
		WindowProps& props = *(WindowProps*)glfwGetWindowUserPointer(window);
		switch (action) {
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent e(static_cast<MouseCode>(button));
			props.callback(e);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent e(static_cast<MouseCode>(button));
			props.callback(e);
			break;
		}
		}
	});

	glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
		WindowProps& props = *(WindowProps*)glfwGetWindowUserPointer(window);
		MouseScrolledEvent e(static_cast<float>(xoffset), static_cast<float>(yoffset));
		props.callback(e);
	});

	glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
		WindowProps& props = *(WindowProps*)glfwGetWindowUserPointer(window);
		MouseMovedEvent e(static_cast<float>(xpos), static_cast<float>(ypos));
		props.callback(e);
	});

}

void Window::shutdown() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::onUpdate() {
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

bool Window::isRunning() {
	return !glfwWindowShouldClose(m_window);
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


void Window::setEventCallback(EventCallback callback) {
	props.callback = callback;
}