#include <iostream>
#include <signal.h>
#include <chrono>
#include <thread>

#include "../include/BackEndDummy.hpp"

volatile sig_atomic_t stop;

void inthand(int signum)
{
	stop = 1;
	std::cout << std::endl;
}

int main()
{
	std::cout << "Running Espeon..." << std::endl;

	espeon::BackEndDummy dummyBackEnd;

	/* main loop which check for tcp packages and forwards them to the connected
	 * back ends. */
	std::cout << "Stop server with Ctrl+C..." << std::endl;
	signal(SIGINT, inthand);
	int i = 0;
	while ( !stop )
	{
		dummyBackEnd.parentSendMessage( espeon::BackEndMessage{ espeon::MessageType::DUMMY, i } );
		++i;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	dummyBackEnd.parentSendMessage( espeon::BackEndMessage{ espeon::MessageType::QUIT, 0 } );
	std::cout << "Espeon finished." << std::endl;
	return 0;
}
