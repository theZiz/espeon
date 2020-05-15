#include <iostream>
#include <signal.h>
#include <chrono>
#include <thread>

volatile sig_atomic_t stop;

void inthand(int signum)
{
	stop = 1;
	std::cout << std::endl;
}

int main()
{
	std::cout << "Running Espeon..." << std::endl;

	/* main loop which check for tcp packages and forwards them to the connected
	 * back ends. */
	std::cout << "Stop server with Ctrl+C..." << std::endl;
	signal(SIGINT, inthand);
	while ( !stop )
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	std::cout << "Espeon finished." << std::endl;
	return 0;
}
