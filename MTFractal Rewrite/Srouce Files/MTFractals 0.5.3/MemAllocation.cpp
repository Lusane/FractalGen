#include "MemAllocation.h"
void RTA_Init() 
{
	#if __DBG && (___MEMORY||__THREAD||__COLOR)  && __LOG
	std::ofstream RTAALog;
	RTAALog.open("RTA_A.log.txt");
	#endif
	MemAllocating[1] = true;
	slp(10);
	Thread_RGB.resize(threadCount);
	#if __DBG && (___MEMORY||__THREAD||__COLOR) && __LOG
	const char *_Name = "Thread_RGB zAxis Cap: ";
	log2txt(RTAALog, _Name, (int)Thread_RGB.capacity());
	#endif
	for (int td = 0; td < threadCount; ++td)
	{
		Thread_RGB[td].resize((int)ceil(frac.height / threadCount) + 1);
		#if __DBG && (___MEMORY||__THREAD||__COLOR) && __LOG
		char __tmp[80];
		const char *_tmp_ = "Thread_RGB[";
		strCat(__tmp,_tmp_);
		strCat(__tmp,td);
		const char *tmp__ = "] yAxis Cap: ";
		strCat(__tmp,tmp__);
		log2txt(RTAALog, __tmp, (int)Thread_RGB[td].capacity());
		#endif
		for (int ht = 0; ht < (int)(ceil(frac.height / threadCount) + 1); ++ht)
		{
			Thread_RGB[td][ht].resize(frac.width);
			#if __DBG && (___MEMORY||__THREAD||__COLOR) && __LOG
			char __tmp_[80];
			const char *_tmp_ = "Thread_RGB[";
			strCat(__tmp_,_tmp_);
			strCat(__tmp_,td);
			const char *tmp__ = "][";
			strCat(__tmp_,tmp__);
			strCat(__tmp_,ht);
			const char *_tmp__ = "] xAxis Cap: ";
			strCat(__tmp_,_tmp__);
			log2txt(RTAALog, __tmp_, (int)Thread_RGB[td].capacity());
			#endif
		}
	}
	MemAllocating[1] = false;
	MemAllocationDone[1] = true;
	slp(10);
	#if __DBG && (___MEMORY||__THREAD||__COLOR) && __LOG
	RTAALog.close();
	#endif
}
void TVA_Init() 
{
	#if __DBG && __MEMORY && __LOG
	std::ofstream TVAALog;
	TVAALog.open("TVA_A.log.txt");
	#endif
	MemAllocating[2] = true;
	slp(10);
	threadValues.resize(threadCount);
	for (int td = 0; td < threadCount; ++td)
	{
		threadValues[td].resize(4);
	}
	MemAllocating[2] = false;
	MemAllocationDone[2] = true;
	slp(10);
	#if __DBG && __MEMORY && __LOG
	TVAALog.close();
	#endif
}
void setFrac() 
{
	#if __DBG && (__MEMORY||__FRACTAL||__COLOR) && __LOG
	std::ofstream setFracALog;
	setFracALog.open("setFrac_A.log.txt");
	#endif
	MemAllocating[3] = true;
	slp(10);
	frac.width = mConfig.width;
	frac.height = mConfig.height;
	if (!is64bit) 
	{
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
	frac._zr.resize(threadCount);
	frac.maxR.resize(threadCount);
	frac.minR.resize(threadCount);
	frac._zi.resize(threadCount);
	frac.maxI.resize(threadCount);
	frac.minI.resize(threadCount);
	frac.maxN.resize(threadCount);
	frac.z.resize(threadCount);
	frac.maxZ.resize(threadCount);
	frac.rMlt.resize(threadCount);
	frac.rDiv.resize(threadCount);
	frac.gMlt.resize(threadCount);
	frac.gDiv.resize(threadCount);
	frac.bMlt.resize(threadCount);
	frac.bDiv.resize(threadCount);
	#if __DBG && (__MEMORY||__FRACTAL||__COLOR) && __LOG
	char __zrtmp[80];
	const char *___tmp = "Fractal _zr Cap";
	strCat(__zrtmp, ___tmp);
	log2txt(setFracALog, __zrtmp, (int)frac._zi.capacity());
	char __zitmp[80];
	___tmp = "Fractal _zi Cap";
	strCat(__zitmp, ___tmp);
	log2txt(setFracALog, __zitmp, (int)frac._zi.capacity());
	char __mxRtmp[80];
	___tmp = "Fractal maxR Cap";
	strCat(__mxRtmp, ___tmp);
	log2txt(setFracALog, __mxRtmp, (int)frac.maxR.capacity());
	char __mnRtmp[80];
	___tmp = "Fractal minR Cap";
	strCat(__mnRtmp, ___tmp);
	log2txt(setFracALog, __mnRtmp, (int)frac.minR.capacity());
	char __mxItmp[80];
	___tmp = "Fractal maxI Cap";
	strCat(__mxItmp, ___tmp);
	log2txt(setFracALog, __mxItmp, (int)frac.maxI.capacity());
	char __mnItmp[80];
	___tmp = "Fractal minI Cap";
	strCat(__mnItmp, ___tmp);
	log2txt(setFracALog, __mnItmp, (int)frac.minI.capacity());
	char __mxNtmp[80];
	___tmp = "Fractal maxN Cap";
	strCat(__mxNtmp, ___tmp);
	log2txt(setFracALog, __mxNtmp, (int)frac.maxN.capacity());
	char __ztmp[80];
	___tmp = "Fractal z Cap";
	strCat(__ztmp, ___tmp);
	log2txt(setFracALog, __ztmp, (int)frac.z.capacity());
	char __mxZtmp[80];
	___tmp = "Fractal maxZ Cap";
	strCat(__mxZtmp, ___tmp);
	log2txt(setFracALog, __mxZtmp, (int)frac.maxZ.capacity());
	char __rMttmp[80];
	___tmp = "Fractal rMlt Cap";
	strCat(__rMttmp, ___tmp);
	log2txt(setFracALog, __rMttmp, (int)frac.rMlt.capacity());
	char __rDvtmp[80];
	___tmp = "Fractal rDiv Cap";
	strCat(__rDvtmp, ___tmp);
	log2txt(setFracALog, __rDvtmp, (int)frac.rDiv.capacity());
	char __gMttmp[80];
	___tmp = "Fractal gMlt Cap";
	strCat(__gMttmp, ___tmp);
	log2txt(setFracALog, __gMttmp, (int)frac.gMlt.capacity());
	char __gDvtmp[80];
	___tmp = "Fractal gDiv Cap";
	strCat(__gDvtmp, ___tmp);
	log2txt(setFracALog, __gDvtmp, (int)frac.gDiv.capacity());
	char __bMttmp[80];
	___tmp = "Fractal bMlt Cap";
	strCat(__bMttmp, ___tmp);
	log2txt(setFracALog, __bMttmp, (int)frac.bMlt.capacity());
	char __bDvtmp[80];
	___tmp = "Fractal bDiv Cap";
	strCat(__bDvtmp, ___tmp);
	log2txt(setFracALog, __bDvtmp, (int)frac.bDiv.capacity());
	#endif
	for (int td = 0; td < threadCount; ++td)
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
		#if __DBG && (__MEMORY||__FRACTAL||__COLOR) && __LOG
		char __zrtmp_[80];
		const char *___tmp_ = "Fractal _zr[";
		strCat(__zrtmp_, ___tmp_);
		strCat(__zrtmp_, td);
		const char *__tmp__ = "] Cap: ";
		strCat(__zrtmp_, __tmp__);
		log2txt(setFracALog, __zrtmp_, (int)frac._zi.capacity());
		char __zitmp_[80];
		___tmp_ = "Fractal _zi[";
		strCat(__zitmp_, ___tmp_);
		strCat(__zitmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__zitmp_, __tmp__);
		log2txt(setFracALog, __zitmp_, (int)frac._zi.capacity());
		char __mxRtmp_[80];
		___tmp_ = "Fractal maxR[";
		strCat(__mxRtmp_, ___tmp_);
		strCat(__mxRtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__mxRtmp_, __tmp__);
		log2txt(setFracALog, __mxRtmp_, (int)frac.maxR.capacity());
		char __mnRtmp_[80];
		___tmp_ = "Fractal minR[";
		strCat(__mnRtmp_, ___tmp_);
		strCat(__mnRtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__mnRtmp_, __tmp__);
		log2txt(setFracALog, __mnRtmp_, (int)frac.minR.capacity());
		char __mxItmp_[80];
		___tmp_ = "Fractal maxI[";
		strCat(__mxItmp_, ___tmp_);
		strCat(__mxItmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__mxItmp_, __tmp__);
		log2txt(setFracALog, __mxItmp_, (int)frac.maxI.capacity());
		char __mnItmp_[80];
		___tmp_ = "Fractal minI[";
		strCat(__mnItmp_, ___tmp_);
		strCat(__mnItmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__mnItmp_, __tmp__);
		log2txt(setFracALog, __mnItmp_, (int)frac.minI.capacity());
		char __mxNtmp_[80];
		___tmp_ = "Fractal maxN[";
		strCat(__mxNtmp_, ___tmp_);
		strCat(__mxNtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__mxNtmp_, __tmp__);
		log2txt(setFracALog, __mxNtmp_, (int)frac.maxN.capacity());
		char __ztmp_[80];
		___tmp_ = "Fractal z[";
		strCat(__ztmp_, ___tmp_);
		strCat(__ztmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__ztmp_, __tmp__);
		log2txt(setFracALog, __ztmp_, (int)frac.z.capacity());
		char __mxZtmp_[80];
		___tmp_ = "Fractal maxZ[";
		strCat(__mxZtmp_, ___tmp_);
		strCat(__mxZtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__mxZtmp_, __tmp__);
		log2txt(setFracALog, __mxZtmp_, (int)frac.maxZ.capacity());
		char __rMttmp_[80];
		___tmp_ = "Fractal rMlt[";
		strCat(__rMttmp_, ___tmp_);
		strCat(__rMttmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__rMttmp_, __tmp__);
		log2txt(setFracALog, __rMttmp_, (int)frac.rMlt.capacity());
		char __rDvtmp_[80];
		___tmp_ = "Fractal rDiv[";
		strCat(__rDvtmp_, ___tmp_);
		strCat(__rDvtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__rDvtmp_, __tmp__);
		log2txt(setFracALog, __rDvtmp_, (int)frac.rDiv.capacity());
		char __gMttmp_[80];
		___tmp_ = "Fractal gMlt[";
		strCat(__gMttmp_, ___tmp_);
		strCat(__gMttmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__gMttmp_, __tmp__);
		log2txt(setFracALog, __gMttmp_, (int)frac.gMlt.capacity());
		char __gDvtmp_[80];
		___tmp_ = "Fractal gDiv[";
		strCat(__gDvtmp_, ___tmp_);
		strCat(__gDvtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__gDvtmp_, __tmp__);
		log2txt(setFracALog, __gDvtmp_, (int)frac.gDiv.capacity());
		char __bMttmp_[80];
		___tmp_ = "Fractal bMlt[";
		strCat(__bMttmp_, ___tmp_);
		strCat(__bMttmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__bMttmp_, __tmp__);
		log2txt(setFracALog, __bMttmp_, (int)frac.bMlt.capacity());
		char __bDvtmp_[80];
		___tmp_ = "Fractal bDiv[";
		strCat(__bDvtmp_, ___tmp_);
		strCat(__bDvtmp_, td);
		__tmp__ = "] Cap: ";
		strCat(__bDvtmp_, __tmp__);
		log2txt(setFracALog, __bDvtmp_, (int)frac.bDiv.capacity());
		#endif
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
			#if __DBG && (__MEMORY||__FRACTAL||__COLOR) && __LOG
			char __zrtmp_[80];
			const char *___tmp_ = "Fractal _zr[";
			strCat(__zrtmp_, ___tmp_);
			strCat(__zrtmp_, td);
			const char *__tmp__ = "][";
			strCat(__zrtmp_, __tmp__);
			strCat(__zrtmp_, st);
			const char *_tmp___ = "] Cap: ";
			strCat(__zrtmp_, _tmp___);
			log2txt(setFracALog, __zrtmp_, (int)frac._zi.capacity());
			char __zitmp_[80];
			___tmp_ = "Fractal _zi[";
			strCat(__zitmp_, ___tmp_);
			strCat(__zitmp_, td);
			__tmp__ = "][";
			strCat(__zitmp_, __tmp__);
			strCat(__zitmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__zitmp_, _tmp___);
			log2txt(setFracALog, __zitmp_, (int)frac._zi.capacity());
			char __mxRtmp_[80];
			___tmp_ = "Fractal maxR[";
			strCat(__mxRtmp_, ___tmp_);
			strCat(__mxRtmp_, td);
			__tmp__ = "][";
			strCat(__mxRtmp_, __tmp__);
			strCat(__mxRtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__mxRtmp_, _tmp___);
			log2txt(setFracALog, __mxRtmp_, (int)frac.maxR.capacity());
			char __mnRtmp_[80];
			___tmp_ = "Fractal minR[";
			strCat(__mnRtmp_, ___tmp_);
			strCat(__mnRtmp_, td);
			__tmp__ = "][";
			strCat(__mnRtmp_, __tmp__);
			strCat(__mnRtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__mnRtmp_, _tmp___);
			log2txt(setFracALog, __mnRtmp_, (int)frac.minR.capacity());
			char __mxItmp_[80];
			___tmp_ = "Fractal maxI[";
			strCat(__mxItmp_, ___tmp_);
			strCat(__mxItmp_, td);
			__tmp__ = "][";
			strCat(__mxItmp_, __tmp__);
			strCat(__mxItmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__mxItmp_, _tmp___);
			log2txt(setFracALog, __mxItmp_, (int)frac.maxI.capacity());
			char __mnItmp_[80];
			___tmp_ = "Fractal minI[";
			strCat(__mnItmp_, ___tmp_);
			strCat(__mnItmp_, td);
			__tmp__ = "][";
			strCat(__mnItmp_, __tmp__);
			strCat(__mnItmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__mnItmp_, _tmp___);
			log2txt(setFracALog, __mnItmp_, (int)frac.minI.capacity());
			char __mxNtmp_[80];
			___tmp_ = "Fractal maxN[";
			strCat(__mxNtmp_, ___tmp_);
			strCat(__mxNtmp_, td);
			__tmp__ = "][";
			strCat(__mxNtmp_, __tmp__);
			strCat(__mxNtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__mxNtmp_, _tmp___);
			log2txt(setFracALog, __mxNtmp_, (int)frac.maxN.capacity());
			char __ztmp_[80];
			___tmp_ = "Fractal z[";
			strCat(__ztmp_, ___tmp_);
			strCat(__ztmp_, td);
			__tmp__ = "][";
			strCat(__ztmp_, __tmp__);
			strCat(__ztmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__ztmp_, _tmp___);
			log2txt(setFracALog, __ztmp_, (int)frac.z.capacity());
			char __mxZtmp_[80];
			___tmp_ = "Fractal maxZ[";
			strCat(__mxZtmp_, ___tmp_);
			strCat(__mxZtmp_, td);
			__tmp__ = "][";
			strCat(__mxZtmp_, __tmp__);
			strCat(__mxZtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__mxZtmp_, _tmp___);
			log2txt(setFracALog, __mxZtmp_, (int)frac.maxZ.capacity());
			char __rMttmp_[80];
			___tmp_ = "Fractal rMlt[";
			strCat(__rMttmp_, ___tmp_);
			strCat(__rMttmp_, td);
			__tmp__ = "][";
			strCat(__rMttmp_, __tmp__);
			strCat(__rMttmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__rMttmp_, _tmp___);
			log2txt(setFracALog, __rMttmp_, (int)frac.rMlt.capacity());
			char __rDvtmp_[80];
			___tmp_ = "Fractal rDiv[";
			strCat(__rDvtmp_, ___tmp_);
			strCat(__rDvtmp_, td);
			__tmp__ = "][";
			strCat(__rDvtmp_, __tmp__);
			strCat(__rDvtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__rDvtmp_, _tmp___);
			log2txt(setFracALog, __rDvtmp_, (int)frac.rDiv.capacity());
			char __gMttmp_[80];
			___tmp_ = "Fractal gMlt[";
			strCat(__gMttmp_, ___tmp_);
			strCat(__gMttmp_, td);
			__tmp__ = "][";
			strCat(__gMttmp_, __tmp__);
			strCat(__gMttmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__gMttmp_, _tmp___);
			log2txt(setFracALog, __gMttmp_, (int)frac.gMlt.capacity());
			char __gDvtmp_[80];
			___tmp_ = "Fractal gDiv[";
			strCat(__gDvtmp_, ___tmp_);
			strCat(__gDvtmp_, td);
			__tmp__ = "][";
			strCat(__gDvtmp_, __tmp__);
			strCat(__gDvtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__gDvtmp_, _tmp___);
			log2txt(setFracALog, __gDvtmp_, (int)frac.gDiv.capacity());
			char __bMttmp_[80];
			___tmp_ = "Fractal bMlt[";
			strCat(__bMttmp_, ___tmp_);
			strCat(__bMttmp_, td);
			__tmp__ = "][";
			strCat(__bMttmp_, __tmp__);
			strCat(__bMttmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__bMttmp_, _tmp___);
			log2txt(setFracALog, __bMttmp_, (int)frac.bMlt.capacity());
			char __bDvtmp_[80];
			___tmp_ = "Fractal bDiv[";
			strCat(__bDvtmp_, ___tmp_);
			strCat(__bDvtmp_, td);
			__tmp__ = "][";
			strCat(__bDvtmp_, __tmp__);
			strCat(__bDvtmp_, st);
			_tmp___ = "] Cap: ";
			strCat(__bDvtmp_, _tmp___);
			log2txt(setFracALog, __bDvtmp_, (int)frac.bDiv.capacity());
			#endif
		}
	}
	MemAllocating[3] = false;
	MemAllocationDone[3] = true;
	slp(10);
	#if __DBG && (__MEMORY||__FRACTAL||__COLOR) && __LOG
	setFracALog.close();
	#endif
}
void MemAllocationThreadCreation() 
{
	MATs.push_back(std::thread(setFrac));
	MATs.push_back(std::thread(RTA_Init));
	MATs.push_back(std::thread(TVA_Init));
}
void MemAllocationThreadDestruction() 
{
	for (auto& mt : MATs)
	{
		mt.~thread();
	}
	MATs.resize(0);
}
void JoinMemAllocationThreads() 
{
	for (auto& mt : MATs)
	{
		mt.join();
	}
}
void InitMem() 
{
	slp(10);
	std::cout << "Allocating Memory.." << std::endl;
	MemAllocating[0] = true;
	MemAllocationThreadCreation();
	slp(55);
	JoinMemAllocationThreads();
	slp(55);
	MemAllocationThreadDestruction();
	MemAllocating[0] = false;
	MemAllocationDone[0] = true;
	std::cout << "Memory Allocated" << std::endl;
	slp(10);
}