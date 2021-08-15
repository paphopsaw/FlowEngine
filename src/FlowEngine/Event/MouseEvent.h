#pragma once

#include "Event.h"
#include "MouseCodes.h"

class MouseMovedEvent : public Event {
public:
	MouseMovedEvent(const float x, const float y)
		:x{ x }, y{ y } {}
	virtual EventType getType() const override { return EventType::MouseMoved; }
	float getX() const { return x; }
	float getY() const { return y; }
	friend std::ostream& operator<< (std::ostream& out, const MouseMovedEvent& e) {
		out << "MouseMoved: (" << e.x << ", " << e.y << ")";
		return out;
	}
private:
	float x;
	float y;
};

class MouseScrolledEvent : public Event {
public:
	MouseScrolledEvent(const float offsetX, const float offsetY)
		:offsetX{ offsetX }, offsetY{ offsetY }{}
	virtual EventType getType() const override { return EventType::MouseScrolled; }
	float getOffsetX() const { return offsetX; }
	float getOffsetY() const { return offsetY; }
	friend std::ostream& operator<< (std::ostream& out, const MouseScrolledEvent& e) {
		out << "MouseScrolled: (" << e.offsetX << ", " << e.offsetY << ")";
		return out;
	}
private:
	float offsetX;
	float offsetY;
};

class MouseButtonPressedEvent : public Event {
public:
	MouseButtonPressedEvent(const MouseCode mouseButton)
		:mouseButton{ mouseButton } {}
	virtual EventType getType() const override { return EventType::MouseButtonPressed; }
	float getMouseButton() const { return mouseButton; }
	friend std::ostream& operator<< (std::ostream& out, const MouseButtonPressedEvent& e) {
		out << "MouseButtonPressed: " << e.mouseButton;
		return out;
	}
private:
	MouseCode mouseButton;
};

class MouseButtonReleasedEvent : public Event {
public:
	MouseButtonReleasedEvent(const MouseCode mouseButton)
		:mouseButton{ mouseButton } {}
	virtual EventType getType() const override { return EventType::MouseButtonReleased; }
	float getMouseButton() const { return mouseButton; }
	friend std::ostream& operator<< (std::ostream& out, const MouseButtonReleasedEvent& e) {
		out << "MouseButtonReleased: " << e.mouseButton;
		return out;
	}
private:
	MouseCode mouseButton;
};