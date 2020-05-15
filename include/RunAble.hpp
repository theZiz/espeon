#pragma once

#include <thread>

namespace espeon
{

class RunAble
{
	public:
		//To be overwritten
		virtual int threadFunction() = 0;

		std::thread runThread()
		{
			std::thread t( [this] { this->threadFunction(); } );
			return t;
		}
};

} // namespace espeon
