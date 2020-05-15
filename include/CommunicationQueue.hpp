#pragma once

#include <mutex>
#include <queue>
#include <chrono>

template <typename T> class CommunicationQueue
{
	public:
		void push(T t)
		{
			queueMutex.lock();
			queue.push( t );
			queueMutex.unlock();
		}
		bool popable()
		{
			return queue.size() > 0;
		}
		T pop()
		{
			while ( queue.empty() )
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			queueMutex.lock();
			auto t = queue.front();
			queue.pop();
			queueMutex.unlock();
			return t;
		}
		int length()
		{
			return queue.size();
		}
	private:
		std::queue<T> queue;
		std::mutex queueMutex;
};
