#include "JobManager.h"

IJob* JobManager::CreateJob(JOBTYPE jobType, JobParams& params)
{
	auto it = m_jobMap.find(jobType);
	if (it != m_jobMap.end())
	{
		std::shared_ptr<Job> job = m_jobMap[jobType](this->getNextId(), params);
		if (job != nullptr)
		{
			m_runningJob.emplace(job->getID(), job);

			return static_cast<IJob*>(job.get());
		}
	}

	return nullptr;
}

void JobManager::RegisterJobType(JOBTYPE jobType, JobCreationFunc func)
{
	auto it = m_jobMap.find(jobType);
	if (it == m_jobMap.end())
	{
		std::lock_guard<std::mutex> lock(m_lock) ;
		m_jobMap.emplace(jobType, func);
	}
}

JOBID JobManager::getNextId()
{
	return m_jobIdNumbers++;
}
