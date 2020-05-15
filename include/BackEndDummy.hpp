#pragma once

#include "BackEnd.hpp"

#include <iostream>

namespace espeon
{

class BackEndDummy : public BackEnd
{
	public:
		BackEndDummy() : t( runThread() ) {}

		//Overwriting
		std::string getName()
		{
			return std::string("dummy back end");
		}
		int threadFunction()
		{
			std::cout << "Running back end thread..." << std::endl;
			bool run = true;
			while ( run )
			{
				auto message = childGetMessage();
				switch (message.type)
				{
					case DUMMY:
						std::cout << message.i << std::endl;
						break;
					case QUIT:
						std::cout << "Received quit message" << std::endl;
						run = false;
						break;
				};
				//~ std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			return 0;
		}
		~BackEndDummy()
		{
			t.join();
		}

		std::thread t;
};

} // namespace espeon
