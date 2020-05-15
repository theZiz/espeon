#pragma once

#include "CommunicationQueue.hpp"

namespace espeon
{

template <
	typename MessageInTemplate,
	typename MessageOutTemplate
>
class CommunicationAble
{
	public:
		void childSendMessage(MessageOutTemplate message)
		{
			messagesOut.push(message);
		}
		MessageInTemplate childGetMessage()
		{
			return messagesIn.pop();
		}

		void parentSendMessage(MessageInTemplate message)
		{
			messagesIn.push(message);
		}
		MessageOutTemplate parentGetMessage()
		{
			return messagesOut.pop();
		}
	protected:
		CommunicationQueue<MessageInTemplate> messagesIn;
		CommunicationQueue<MessageOutTemplate> messagesOut;
};

} // namespace espeon
