#include "Event.h"

class WindowResizedEvent : public ApplicationEvent {
public:
	WindowResizedEvent(int width, int height)
		: width{ width }, height{ height } {}
	virtual EventType getType() const override { return EventType::WindowResized; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }

private:
	int width;
	int height;
};