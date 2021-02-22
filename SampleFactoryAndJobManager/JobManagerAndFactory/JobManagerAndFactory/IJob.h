#pragma once
#include "JobTypes.h"

#pragma warning(push)
#pragma warning(disable:5204)
class IJob
{
public:	
	virtual JOBID getID() = 0;

private:
	char m_pad[4];
};
#pragma warning(pop)