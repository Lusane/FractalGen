#define VERITAS_FACTA 420
#include "MemAllocation.h"

void RTA_Deallocate() {
	MemDeallocating[1] = true;
	Sleep(10);
	for (int td = 0; td < (int)Thread_RGB.capacity(); ++td)
	{
		for (int ht = 0; ht < (int)Thread_RGB[td].capacity(); ++ht)
		{
			for (int wd = 0; wd < (int)Thread_RGB[td][ht].capacity(); ++wd)
			{
				Thread_RGB[td][ht][wd].clear();
			}
			//Thread_RGB[td][ht].clear();
			Thread_RGB[td][ht].resize(0);
		}
		//Thread_RGB[td].clear();
		Thread_RGB[td].resize(0);
	}
	//Thread_RGB.clear();
	Thread_RGB.resize(0);
	MemDeallocating[1] = false;
	MemDeallocationDone[1] = true;
	Sleep(10);
	std::this_thread::yield();
}

void TVA_Deallocate() {
	MemDeallocating[2] = true;
	Sleep(10);
	for (int td = 0; td < (int)threadValues.capacity(); ++td)
	{
		for (int ht = 0; ht < (int)threadValues[td].capacity(); ++ht)
		{
			threadValues[td][ht] = NULL;
		}
		//threadValues[td].clear();
		threadValues[td].resize(0);
	}
	//threadValues.clear();
	threadValues.resize(0);
	MemDeallocating[2] = false;
	MemDeallocationDone[2] = true;
	Sleep(10);
}

void RemoveFrac() {
	Sleep(10);
	MemDeallocating[3] = true;
	frac.width = mConfig.width;
	frac.height = mConfig.height;
	for (int td = 0; td < mConfig.ThreadCount; ++td)
	{
		for (int st = 0; st < fConfig.setCount; ++st)
		{
			frac._zr[td][st] = NULL;
			frac.maxR[td][st] = NULL;
			frac.minR[td][st] = NULL;

			frac._zi[td][st] = NULL;
			frac.maxI[td][st] = NULL;
			frac.minI[td][st] = NULL;

			frac.maxN[td][st] = NULL;
			frac.z[td][st] = NULL;
			frac.maxZ[td][st] = NULL;

			frac.rMlt[td][st] = NULL;
			frac.rDiv[td][st] = NULL;
			frac.gMlt[td][st] = NULL;
			frac.gDiv[td][st] = NULL;
			frac.bMlt[td][st] = NULL;
			frac.bDiv[td][st] = NULL;
		}

		/**frac._zr[td].clear();
		frac.maxR[td].clear();
		frac.minR[td].clear();**/
		frac._zr[td].resize(0);
		frac.maxR[td].resize(0);
		frac.minR[td].resize(0);

		/**frac._zi[td].clear();
		frac.maxI[td].clear();
		frac.minI[td].clear();**/
		frac._zi[td].resize(0);
		frac.maxI[td].resize(0);
		frac.minI[td].resize(0);

		/**frac.maxN[td].clear();
		frac.z[td].clear();
		frac.maxZ[td].clear();**/
		frac.maxN[td].resize(0);
		frac.z[td].resize(0);
		frac.maxZ[td].resize(0);

		/**frac.rMlt[td].clear();
		frac.rDiv[td].clear();
		frac.gMlt[td].clear();
		frac.gDiv[td].clear();
		frac.bMlt[td].clear();
		frac.bDiv[td].clear();**/
		frac.rMlt[td].resize(0);
		frac.rDiv[td].resize(0);
		frac.gMlt[td].resize(0);
		frac.gDiv[td].resize(0);
		frac.bMlt[td].resize(0);
		frac.bDiv[td].resize(0);
	}

	/**frac._zr.clear();
	frac.maxR.clear();
	frac.minR.clear();**/
	frac._zr.resize(0);
	frac.maxR.resize(0);
	frac.minR.resize(0);

	/**frac._zi.clear();
	frac.maxI.clear();
	frac.minI.clear();**/
	frac._zi.resize(0);
	frac.maxI.resize(0);
	frac.minI.resize(0);

	/**frac.maxN.clear();
	frac.z.clear();
	frac.maxZ.clear();**/
	frac.maxN.resize(0);
	frac.z.resize(0);
	frac.maxZ.resize(0);

	/**frac.rMlt.clear();
	frac.rDiv.clear();
	frac.gMlt.clear();
	frac.gDiv.clear();
	frac.bMlt.clear();
	frac.bDiv.clear();**/
	frac.rMlt.resize(0);
	frac.rDiv.resize(0);
	frac.gMlt.resize(0);
	frac.gDiv.resize(0);
	frac.bMlt.resize(0);
	frac.bDiv.resize(0);

	MemDeallocating[3] = false;
	MemDeallocationDone[3] = true;
	Sleep(10);
}

void MemDeallocationThreadCreation() {
	MDATs.push_back(std::thread(RemoveFrac));
	MDATs.push_back(std::thread(RTA_Deallocate));
	MDATs.push_back(std::thread(TVA_Deallocate));
}

void MemDeallocationThreadDestruction() {
	for (auto& mdt : MDATs)
	{
		mdt.~thread();
	}
	//MDATs.clear();
	MDATs.resize(0);
}

void JoinMemDeallocationThreads() {
	for (auto& mdt : MDATs)
	{
		mdt.join();
	}
}

void DeallocateMem() {
	Sleep(10);
	std::cout << "Deallocating Memory.." << std::endl;
	MemDeallocating[0] = true;

	MemDeallocationThreadCreation();
	Sleep(55);
	JoinMemDeallocationThreads();
	Sleep(55);
	MemDeallocationThreadDestruction();

	MemDeallocating[0] = false;
	MemDeallocationDone[0] = true;
	std::cout << "Memory Deallocated" << std::endl;
	Sleep(10);
}