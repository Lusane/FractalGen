#define VERITAS_FACTA 420
#include "Fractal.h"

bool isWindows64bit = getWindowsBit(isWindows64bit);

void RTA_Init() {
	MemAllocating[1] = true;
	Sleep(10);
	Thread_RGB.resize(mConfig.ThreadCount);
	for (int td = 0; td < mConfig.ThreadCount; ++td)
	{
		Thread_RGB[td].resize((int)ceil(frac.height / mConfig.ThreadCount) + 1);
		for (int ht = 0; ht < (int)(ceil(frac.height / mConfig.ThreadCount) + 1); ++ht)
		{
			Thread_RGB[td][ht].resize(frac.width);
		}
	}
	MemAllocating[1] = false;
	MemAllocationDone[1] = true;
	Sleep(10);
}

void TVA_Init() {
	MemAllocating[2] = true;
	Sleep(10);
	threadValues.resize(mConfig.ThreadCount);
	for (int td = 0; td < mConfig.ThreadCount; ++td)
	{
		threadValues[td].resize(4);
	}
	MemAllocating[2] = false;
	MemAllocationDone[2] = true;
	Sleep(10);
}

void setFrac() {
	MemAllocating[3] = true;
	Sleep(10);

	frac.width = mConfig.width;
	frac.height = mConfig.height;

	if (!is64bit && !isWindows64bit) {
		if (frac.width > 12288)
		{
			std::cout << "width is to large setting to 12288 from " << frac.width << std::endl;
			frac.width = 12288;
		}

		if (frac.height > 12288)
		{
			std::cout << "height is to large setting to 12288 from " << frac.height << std::endl;
			frac.height = 12288;
		}
	}

	frac._zr.resize(mConfig.ThreadCount);
	frac.maxR.resize(mConfig.ThreadCount);
	frac.minR.resize(mConfig.ThreadCount);

	frac._zi.resize(mConfig.ThreadCount);
	frac.maxI.resize(mConfig.ThreadCount);
	frac.minI.resize(mConfig.ThreadCount);

	frac.maxN.resize(mConfig.ThreadCount);
	frac.z.resize(mConfig.ThreadCount);
	frac.maxZ.resize(mConfig.ThreadCount);

	frac.rMlt.resize(mConfig.ThreadCount);
	frac.rDiv.resize(mConfig.ThreadCount);
	frac.gMlt.resize(mConfig.ThreadCount);
	frac.gDiv.resize(mConfig.ThreadCount);
	frac.bMlt.resize(mConfig.ThreadCount);
	frac.bDiv.resize(mConfig.ThreadCount);

	for (int td = 0; td < mConfig.ThreadCount; ++td)
	{
		frac._zr[td].resize(fConfig.setCount);
		frac.maxR[td].resize(fConfig.setCount);
		frac.minR[td].resize(fConfig.setCount);

		frac._zi[td].resize(fConfig.setCount);
		frac.maxI[td].resize(fConfig.setCount);
		frac.minI[td].resize(fConfig.setCount);

		frac.maxN[td].resize(fConfig.setCount);
		frac.z[td].resize(fConfig.setCount);
		frac.maxZ[td].resize(fConfig.setCount);

		frac.rMlt[td].resize(fConfig.setCount);
		frac.rDiv[td].resize(fConfig.setCount);
		frac.gMlt[td].resize(fConfig.setCount);
		frac.gDiv[td].resize(fConfig.setCount);
		frac.bMlt[td].resize(fConfig.setCount);
		frac.bDiv[td].resize(fConfig.setCount);

		for (int st = 0; st < fConfig.setCount; ++st)
		{
			frac._zr[td][st] = fSets.zr[st];
			frac.maxR[td][st] = fSets.maxR[st];
			frac.minR[td][st] = fSets.minR[st];


			frac._zi[td][st] = fSets.zi[st];
			frac.maxI[td][st] = fSets.maxI[st];
			frac.minI[td][st] = fSets.minI[st];

			frac.maxN[td][st] = fSets.maxN[st];
			frac.z[td][st] = fSets.z[st];
			frac.maxZ[td][st] = fSets.maxZ[st];


			frac.rMlt[td][st] = fSets.rMlt[st];
			frac.rDiv[td][st] = fSets.rDiv[st];
			frac.gMlt[td][st] = fSets.gMlt[st];
			frac.gDiv[td][st] = fSets.gDiv[st];
			frac.bMlt[td][st] = fSets.bMlt[st];
			frac.bDiv[td][st] = fSets.bDiv[st];
		}
	}

	MemAllocating[3] = false;
	MemAllocationDone[3] = true;
	Sleep(10);
}

void MemAllocationThreadCreation() {
	MATs.push_back(std::thread(setFrac));
	MATs.push_back(std::thread(RTA_Init));
	MATs.push_back(std::thread(TVA_Init));
}

void MemAllocationThreadDestruction() {
	for (auto& mt : MATs)
	{
		mt.~thread();
	}
	MATs.resize(0);
}

void JoinMemAllocationThreads() {
	for (auto& mt : MATs)
	{
		mt.join();
	}
}

void InitMem() {
	Sleep(10);
	std::cout << "Allocating Memory.." << std::endl;
	MemAllocating[0] = true;

	MemAllocationThreadCreation();
	Sleep(55);
	JoinMemAllocationThreads();
	Sleep(55);
	MemAllocationThreadDestruction();

	MemAllocating[0] = false;
	MemAllocationDone[0] = true;
	std::cout << "Memory Allocated" << std::endl;
	Sleep(10);
}