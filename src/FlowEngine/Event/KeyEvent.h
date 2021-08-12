#pragma once

#include "Event.h"
#include "KeyCodes.h"

// Change to one key event with type
// Add key repeat
class KeyPressedEvent : public Event {
public:
	KeyPressedEvent(const KeyCode key)
		:key{ key } {}
	virtual EventType getType() const override { return EventType::KeyPressed; }
	KeyCode getKey() const { return key; }
private:
	KeyCode key;
};

class KeyReleasedEvent : public Event {
public:
	KeyReleasedEvent(const KeyCode key)
		:key{ key } {}
	virtual EventType getType() const override { return EventType::KeyReleased; }
	KeyCode getKey() const { return key; }
private:
	KeyCode key;
};