#include "JobFactory.h"
#include "JobManager.h"
#include "IJob.h"

JOBID JobFactory::CreateJob(JOBID jobType, JobParams& params)
{
	IJob* job = JobManager::instance().CreateJob(jobType, params);
	if (job != nullptr)
		return job->getID();
	
	return 0;
}


