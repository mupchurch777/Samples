#pragma once
#include "Job.h"
#include "JobManager.h"
#include "common_memory.h"

class PatchJobService
{
public:
	static uint64_t PerformPatchJob(JobParams& params);

	#pragma warning(push)
	#pragma warning(disable:4514)
	static void RegisterCreateJobType(  )
	{
		JobManager::instance().RegisterJobType(static_cast<JOBTYPE>(JobTypesEnum::PatchJob), &PatchJobService::CreatePatchJob);
	}
	#pragma warning(pop)
	
	static std::shared_ptr<Job> CreatePatchJob(JOBID jobId, JobParams& params)
	{
		return std::make_shared<Job>(jobId, params, &PatchJobService::PerformPatchJob);
	}
};

