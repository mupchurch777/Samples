#pragma once
#include "common_functional.h"
#include "common_mutex.h"
#include "Job.h"

using JobCreationFunc = std::function<std::shared_ptr<Job>(JOBID jobId, JobParams&)>;

class JobManager
{
public:
	#pragma warning(push)
	#pragma warning(disable:4514)
	static JobManager& instance()
	{
		static JobManager m_instance;

		return m_instance;
	}
	#pragma warning(pop)
	
	IJob* CreateJob(JOBTYPE jobType, JobParams& params);

	void RegisterJobType(JOBTYPE jobType, JobCreationFunc func);
	
	/*
	 * Start Job
	 *
	 * Cancel Job
	 *
	 * CancelAndAddBackJob
	 */

	JobManager (const JobManager&) = delete;
	JobManager (JobManager&&) = delete;
	JobManager& operator=(JobManager) = delete;
	JobManager& operator=(JobManager&&) = delete;

private:
	JobManager() : m_jobIdNumbers(1) {};

	std::mutex m_lock;
	std::mutex m_idLock;
	std::unordered_map<JOBTYPE, JobCreationFunc> m_jobMap;
	std::unordered_map<JOBID, std::shared_ptr<Job>> m_runningJob; // this would be the priority queue
	std::atomic<JOBID> m_jobIdNumbers;

	JOBID getNextId();
};

