// JobManagerAndFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "common_iostream.h"
#include "PatchJobService.h"

int main()
{
    std::cout << "Hello World!\n";

	PatchJobService::RegisterCreateJobType();
}

