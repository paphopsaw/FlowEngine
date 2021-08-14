#pragma once

#include "Event.h"
#include <iostream>

class WindowResizeEvent : public Event {
public:
	WindowResizeEvent(int width, int height)
		: width{ width }, height{ height } {}
	virtual EventType getType() const override { return EventType::WindowResize; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	friend std::ostream& operator<< (std::ostream& out, const WindowResizeEvent& e) {
		out << "WindowResizeEvent: (" << e.height << ", " << e.width << ")";
		return out;
	}

private:
	int width;
	int height;
};

class WindowCloseEvent : public Event {
public:
	WindowCloseEvent() {}
	virtual EventType getType() const override { return EventType::WindowClose; }
	friend std::ostream& operator<< (std::ostream& out, const WindowCloseEvent& e) {
		out << "WindowCloseEvent";
		return out;
	}
};