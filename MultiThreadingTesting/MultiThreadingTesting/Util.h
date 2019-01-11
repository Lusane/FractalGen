#define VERITAS_FACTA 420
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#define _WIN32_WINNT  0x0501
#include <ios>
#include <iostream>
//#include <istream>
//#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
//#include <atomic>
#include <vector>
#include <time.h>
#include <ratio>
#include <chrono>
//#include <WinBase.h>
//#include <malloc.h>
//#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#pragma comment(lib, "psapi.lib")
#include <stdlib.h>
#include <setjmp.h>
#include "png.h"
#ifdef PNG_ZLIB_HEADER
#include PNG_ZLIB_HEADER
#else
#include "zlib.h"
#endif
#include "ini.h"
#include "Version.h"
int ncpu = 1;
int _WIN_getCPUcount();
#if _WIN32 || _WIN64
	const bool isWIN = true;
	const bool isLinux = false;
	#if _WIN64
		#define ENVIRONMENT64
		const bool is64bit = true;
	#else
		#define ENVIRONMENT32
		const bool is64bit = false;
	#endif
#else
	#if __x86_64__ || __ppc64__
	const bool isWIN = false;
	const bool isLinux = true;
		#define ENVIRONMENT64
		const bool is64Bit = true;
	#else
		#define ENVIRONMENT32
		const bool is64bit = false;
	#endif
#endif
typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); LPFN_ISWOW64PROCESS fnIsWow64Process;
BOOL isWow64;
bool getWindowsBit(bool & isWindows64bit) {
#if _WIN64
	isWindows64bit = true;
	return true;
#elif _WIN32
	isWindows64bit = false;
	LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)
		GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
	if (fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(), &isWow64))
			return false;
		if (isWow64)
			isWindows64bit = true;
		else
			isWindows64bit = false;
		return true;
	}
	else
		return false;
#else
	assert(0);
	return false;
#endif
}
const double PI = 3.141592653589793;
std::vector<std::vector<std::vector<std::string>>> Thread_RGB;
std::vector<std::thread> threads;
std::vector<std::thread> MATs;
std::vector<std::thread> MDATs;
bool InitAll = true;
std::vector<std::vector<int>> threadValues;
std::vector<std::vector<float>> threadProgs;
std::vector<float> ImageProg;
bool *Geni;
bool *Done_Geni;
bool _MemAllocationDone;
bool _MemDeallocationDone;
bool *MemAllocating;
bool *MemAllocationDone;
bool *MemDeallocating;
bool *MemDeallocationDone;
bool trackProg = false;
bool ImageMaking = false;
bool ImageAssembled = false;
bool ContinueRunning = true;
bool ForceShutDown = false;
bool ReInitThreads = false;
void genFrac(int InitX, int FinalX, int InitY, int FinalY, int id);
void coutProgress();
void AssemableImage();
int threadCount;
void Timestamp(std::string text);
time_t getCurrentTimeInSec();
int iRandomNum(int randSeed, int low, int high);
float fRandomNum(int randSeed, float low, float high);
double dRandomNum(int randSeed, double low, double high);