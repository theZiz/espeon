#pragma once

#include "CommunicationAble.hpp"
#include "RunAble.hpp"
#include <string>

namespace espeon
{

enum MessageType
{
	QUIT,
	DUMMY
};

struct BackEndMessage
{
	MessageType type;
	int i;
};

class BackEnd :
	public RunAble,
	public CommunicationAble< BackEndMessage, BackEndMessage >
{
	public:
		//To be overwritten
		virtual std::string getName() = 0;
};

} // namespace espeon
