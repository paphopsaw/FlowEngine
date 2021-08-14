#pragma once

#include "Event.h"
#include "KeyCodes.h"

class KeyPressedEvent : public Event {
public:
	KeyPressedEvent(const KeyCode& key)
		:key{ key } {}
	virtual EventType getType() const override { return EventType::KeyPressed; }
	KeyCode getKey() const { return key; }
	friend std::ostream& operator<< (std::ostream& out, const KeyPressedEvent& e) {
		out << "KeyPressedEvent: " << e.key;
		return out;
	}
private:
	KeyCode key;
};

class KeyReleasedEvent : public Event {
public:
	KeyReleasedEvent(const KeyCode& key)
		:key{ key } {}
	virtual EventType getType() const override { return EventType::KeyReleased; }
	KeyCode getKey() const { return key; }
	friend std::ostream& operator<< (std::ostream& out, const KeyReleasedEvent& e) {
		out << "KeyReleasedEvent: " << e.key;
		return out;
	}
private:
	KeyCode key;
};

class KeyRepeatedEvent : public Event {
public:
	KeyRepeatedEvent(const KeyCode& key)
		:key{ key } {}
	virtual EventType getType() const override { return EventType::KeyRepeated; }
	KeyCode getKey() const { return key; }
	friend std::ostream& operator<< (std::ostream& out, const KeyRepeatedEvent& e) {
		out << "KeyRepeatedEvent: " << e.key;
		return out;
	}
private:
	KeyCode key;
};