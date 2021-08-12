#pragma once

#include "Event.h"

class WindowResizeEvent : public Event {
public:
	WindowResizeEvent(int width, int height)
		: width{ width }, height{ height } {}
	virtual EventType getType() const override { return EventType::WindowResize; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }

private:
	int width;
	int height;
};

class WindowCloseEvent : public Event {
public:
	WindowCloseEvent() {}
	virtual EventType getType() const override { return EventType::WindowResize; }
};