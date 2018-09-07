#define VERITAS_FACTA 420

#define _CRT_SECURE_NO_WARNINGS 1
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
//#include <stdlib.h>
#include "ini.h"

int ncpu = 1;

void _WIN_getCPUcount () {
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	ncpu = (INT8)sysinfo.dwNumberOfProcessors;
}


// Check windows
#if _WIN32 || _WIN64
bool isWIN = true;
bool isLinux = false;
#if _WIN64
#define ENVIRONMENT64
bool is64bit = true;
#else
#define ENVIRONMENT32
bool is64bit = false;
#endif
#endif

typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); LPFN_ISWOW64PROCESS fnIsWow64Process;
bool getWindowsBit(bool & isWindows64bit) {
#if _WIN64

	isWindows64bit = true;
	return true;

#elif _WIN32

	BOOL isWow64 = false;

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


// Check GCC
/**#if __GNUC__
#if __x86_64__ || __ppc64__
bool isWIN = false;
bool isLinux = true;
#define ENVIRONMENT64
bool is64Bit = true;
#else
#define ENVIRONMENT32
bool is64bit = false;
#endif
#endif**/

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

void Timestamp(std::string text) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	std::cout << "Time: ";
	std::cout << now->tm_hour << ":";
	std::cout << now->tm_min << ":";
	std::cout << now->tm_sec << std::endl;
}