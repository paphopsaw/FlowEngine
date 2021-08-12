#pragma once

enum class EventType {
	WindowResized,
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

class EventDispatcher {
public:
	EventDispatcher(Event& e)
		: m_event{ e } {}
	template<typename T, typename F>
	void dispatch(const F& func) {
		if (m_event.getType() == T::getStaticType)
			func(m_event)
	}
private:
	Event& m_event;
};