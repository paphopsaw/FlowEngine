#pragma once

enum class EventType {
	WindowResize,
	WindowClose,
	KeyPressed,
	KeyReleased,
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

class Event {
public:
	virtual ~Event() = default;
	virtual EventType getType() const = 0;
};