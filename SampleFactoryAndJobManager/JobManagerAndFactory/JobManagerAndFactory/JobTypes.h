#pragma once

#include "common_cstdint.h"

using JOBID = uint64_t;
using JOBTYPE = uint64_t;

struct JobParams
{
	int64_t buildId;
	const char* szPath;
private:
	char pad[4]; // padding for memory alignment
};


enum class JobTypesEnum : JOBTYPE
{
	PatchJob = 0,
	RepairJob = 1
};