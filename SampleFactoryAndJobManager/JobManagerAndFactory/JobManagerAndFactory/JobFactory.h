#pragma once
#include "JobTypes.h"

class JobFactory
{
public:	
	static JOBID CreateJob(JOBID jobType, JobParams& params);
	JobFactory() = default;
};

