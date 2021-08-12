#pragma once

#include "Event.h"
#include "MouseCodes.h"

class MouseMovedEvent : public Event {
public:
	MouseMovedEvent(const float x, const float y)
		:x{ x }, y{ y } {}
	virtual EventType getType() const override { return EventType::MouseMoved }
	float getX() const { return x; }
	float getY() const { return y; }
private:
	float x;
	float y;
};

class MouseScrolledEvent : public Event {
public:
	MouseScrolledEvent(const float offsetX, const float offsetY)
		:offsetX{ offsetY }, offsetY{ offsetY }{}
	virtual EventType getType() const override { return EventType::MouseScrolled }
	float getOffsetX() const { return offsetX; }
	float getOffsetY() const { return offsetY; }
private:
	float offsetX;
	float offsetY;
};

class MouseButtonPressedEvent : public Event {
public:
	MouseButtonPressedEvent(const MouseCode mouseButton)
		:mouseButton{ mouseButton } {}
	virtual EventType getType() const override { return EventType::MouseButtonPressed }
	float getMouseButton() const { return mouseButton; }
private:
	MouseCode mouseButton;
};

class MouseButtonReleasedEvent : public Event {
public:
	MouseButtonReleasedEvent(const MouseCode mouseButton)
		:mouseButton{ mouseButton } {}
	virtual EventType getType() const override { return EventType::MouseButtonReleased }
	float getMouseButton() const { return mouseButton; }
private:
	MouseCode mouseButton;
};