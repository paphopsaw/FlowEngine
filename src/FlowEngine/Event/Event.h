
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