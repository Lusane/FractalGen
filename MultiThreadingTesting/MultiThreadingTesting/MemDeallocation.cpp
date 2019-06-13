#include "MemDeallocation.h"
void RTA_Deallocate() 
{
	MemDeallocating[1] = true;
	slp(10);
	for (int td = 0; td < (int)Thread_RGB.capacity(); ++td)
	{
		for (int ht = 0; ht < (int)Thread_RGB[td].capacity(); ++ht)
		{
			for (int wd = 0; wd < (int)Thread_RGB[td][ht].capacity(); ++wd)
			{
				Thread_RGB[td][ht][wd].clear();
			}
			Thread_RGB[td][ht].resize(0);
		}
		Thread_RGB[td].resize(0);
	}
	Thread_RGB.resize(0);
	MemDeallocating[1] = false;
	MemDeallocationDone[1] = true;
	slp(10);
	std::this_thread::yield();
}
void TVA_Deallocate() 
{
	MemDeallocating[2] = true;
	slp(10);
	for (int td = 0; td < (int)threadValues.capacity(); ++td)
	{
		threadValues[td].clear();
	}
	threadValues.resize(0);
	MemDeallocating[2] = false;
	MemDeallocationDone[2] = true;
	slp(10);
}
void RemoveFrac() 
{
	slp(10);
	MemDeallocating[3] = true;
	frac.width = mConfig.width;
	frac.height = mConfig.height;
	for (int td = 0; td < threadCount; ++td)
	{
		frac._zr[td].clear();
		frac.maxR[td].clear();
		frac.minR[td].clear();
		frac._zi[td].clear();
		frac.maxI[td].clear();
		frac.minI[td].clear();
		frac.maxN[td].clear();
		frac.z[td].clear();
		frac.maxZ[td].clear();
		frac.rMlt[td].clear();
		frac.rDiv[td].clear();
		frac.gMlt[td].clear();
		frac.gDiv[td].clear();
		frac.bMlt[td].clear();
		frac.bDiv[td].clear();
	}
	frac._zr.resize(0);
	frac.maxR.resize(0);
	frac.minR.resize(0);
	frac._zi.resize(0);
	frac.maxI.resize(0);
	frac.minI.resize(0);
	frac.maxN.resize(0);
	frac.z.resize(0);
	frac.maxZ.resize(0);
	frac.rMlt.resize(0);
	frac.rDiv.resize(0);
	frac.gMlt.resize(0);
	frac.gDiv.resize(0);
	frac.bMlt.resize(0);
	frac.bDiv.resize(0);
	MemDeallocating[3] = false;
	MemDeallocationDone[3] = true;
	slp(10);
}
void MemDeallocationThreadCreation() 
{
	MDATs.push_back(std::thread(RemoveFrac));
	MDATs.push_back(std::thread(RTA_Deallocate));
	MDATs.push_back(std::thread(TVA_Deallocate));
}
void MemDeallocationThreadDestruction() 
{
	for (auto& mdt : MDATs)
	{
		mdt.~thread();
	}
	MDATs.resize(0);
}
void JoinMemDeallocationThreads() 
{
	for (auto& mdt : MDATs)
	{
		mdt.join();
	}
}
void DeallocateMem() 
{
	slp(10);
	std::cout << "Deallocating Memory.." << std::endl;
	MemDeallocating[0] = true;
	MemDeallocationThreadCreation();
	slp(55);
	JoinMemDeallocationThreads();
	slp(55);
	MemDeallocationThreadDestruction();
	MemDeallocating[0] = false;
	MemDeallocationDone[0] = true;
	std::cout << "Memory Deallocated" << std::endl;
	slp(10);
}