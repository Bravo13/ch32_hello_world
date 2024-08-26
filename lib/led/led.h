#include<ch32v00x.h>

class Led
{
private:
	/* data */
public:
	uint8_t level = 0;

	// How many calls of update_led in one refresh cycle( like, how many frames per second we have)
	uint64_t calls_per_cycle = 0;
	uint64_t _current_frame = 0;
	uint64_t _switch_frame = 0;
	BitAction _state = Bit_RESET;

	Led(uint64_t calls_per_cycle);
	~Led();
	BitAction update_led();
	void set_brightness(uint8_t level);
};