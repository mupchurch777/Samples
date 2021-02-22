#pragma once

#include "IJob.h"
#include "JobTypes.h"
#include "common_functional.h"

using JobFunction = std::function<uint64_t(JobParams& params)>;

#pragma warning(push)
#pragma warning(disable:4265)
#pragma warning(disable:5204)
#pragma warning(disable:4514)
class Job :
	public IJob
{
public:
	Job(JOBID id, JobParams& params, JobFunction jobFunc) :
		m_jobID(id),
		m_params(params),
		m_jobFunc(jobFunc)
	{}
	
	JOBID getID() override { return m_jobID; }

	Job (const Job&) = delete;
	Job (Job&& ) = delete;

	Job& operator= (Job) = delete;
	Job& operator= (Job&&) = delete;

	~Job() = default;

private:
	JOBID m_jobID;
	JobParams m_params;
	JobFunction m_jobFunc;
};
#pragma warning(pop)
