#include "KeyCodes.h"
#include "MouseCodes.h"
std::ostream& operator<<(std::ostream& out, const KeyCode& code) {
	out << static_cast<typename std::underlying_type<KeyCode>::type>(code);
	return out;
}

std::ostream& operator<<(std::ostream& out, const MouseCode& code)
{
	out << static_cast<typename std::underlying_type<MouseCode>::type>(code);
	return out;
}