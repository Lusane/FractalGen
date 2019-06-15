#define VERITAS_FACTA 420
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#define _WIN32_WINNT  0x0501
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <atomic>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
//#include <cstdio>
#include <cstdlib>
#include <csetjmp>
///#include "png.h"
///#ifdef PNG_ZLIB_HEADER
///#include PNG_ZLIB_HEADER
///#else
///#include "zlib.h"
///#endif
//#include "ini.h"
#include "Version.h"
int ncpu = 1;
#if _WIN32 || _WIN64
	#define isWindows 1
	#define isLinux 0
	#include <windows.h>
	#include <psapi.h>
	#pragma comment(lib, "psapi.lib")
	void slp(int t) {
		Sleep(t);
	};
	const bool isWIN = true;
	const bool isUNIX = false;
	#if __WIN64
		#define ENVIRONMENT64
		const bool is64bit = true;
	#else
		#define ENVIRONMENT32
		const bool is64bit = false;
	#endif
	typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); LPFN_ISWOW64PROCESS fnIsWow64Process;
	BOOL isWow64;
	int _WIN_getCPUcount() 
	{
		SYSTEM_INFO sysinfo;
		GetSystemInfo(&sysinfo);
		return (INT8)sysinfo.dwNumberOfProcessors;
	}
#else
	#if __linux__
		#define isLinux 1
		#define isWindows 0
		#include <cassert>
		#include <cstring>
		#include <cmath>
		#include <unistd.h>
		void slp(int t) {
			usleep(t);
		};
		const bool isWIN = false;
		const bool isUNIX = true;
		#if __LP64__
			#define ENVIRONMENT64 
			const bool is64bit = true;
		#else
			#define ENVIRONMENT32
			const bool is64bit = false;
		#endif
		int _LINUX_getCPUcount() {
			int numCPU = sysconf(_SC_NPROCESSORS_ONLN);
			return numCPU;
		}
	#endif
#endif
#if isWindows
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
		isWindows64bit=false;
		assert(0);
		return false;
	#endif
	}
#elif isLinux
	bool getLinuxBit(bool & isLinux64bit) {
	#if __LP64__
		isLinux64bit = true;
		return true;
	#elif __x86__
		isLinux64bit = false;
		return true;
	#else
		isLinux64bit=false;
		assert(0);
		return false;
	#endif
	}
#endif
const double PI = 3.141592653589793;
std::vector<std::vector<std::vector<std::string>>> Thread_RGB;
std::vector<std::vector<std::vector<std::vector<std::string>>>> Test_RGB;
bool isTest = false;
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
#define __DBG 1
#if __DBG
#define __FRACTAL 0
#define __RANDOM 0
#define __COLOR 0
#define __MEMORY 0
#define __THREAD 0
#define __OUTPUT 0
#define __INI 0
#define __TESTING 1
void log2txt(std::ofstream &__fsname, std::string __valName, char *__val) {
	char __tmp[80];
	strcat(__tmp, __valName.c_str());
	strcat(__tmp, __val);
	if(__fsname.is_open()) {
		__fsname << __tmp << std::endl;
	}else{
		std::cout << "Unable to write to the File Stream" << std::endl;
	}
}
void log2txt(std::ofstream &__fsname, std::string __valName, std::string __val) {
	char __tmp[80];
	strcat(__tmp,__valName.c_str());
	strcat(__tmp,__val.c_str());
	if(__fsname.is_open()) {
		__fsname << __tmp << std::endl;
	}else{
		std::cout << "Unable to write to the File Stream" << std::endl;
	}
}
void log2txt(std::ofstream &__fsname, std::string __valName, int __val) {
	char __tmp[80];
	strcat(__tmp,__valName.c_str());
	std::string _tmp_ = std::to_string(__val);
	strcat(__tmp,_tmp_.c_str());
	if(__fsname.is_open()) {
		__fsname << __tmp << std::endl;
	}else{
		std::cout << "Unable to write to the File Stream" << std::endl;
	}
}
void log2txt(std::ofstream &__fsname, std::string __valName, float __val) {
	char __tmp[80];
	strcat(__tmp,__valName.c_str());
	std::string _tmp_ = std::to_string(__val);
	strcat(__tmp,_tmp_.c_str());
	if(__fsname.is_open()) {
		__fsname << __tmp << std::endl;
	}else{
		std::cout << "Unable to write to the File Stream" << std::endl;
	}
}
void log2txt(std::ofstream &__fsname, std::string __valName, double __val) {
	char __tmp[80];
	strcat(__tmp,__valName.c_str());
	std::string _tmp_ = std::to_string(__val);
	strcat(__tmp,_tmp_.c_str());
	if(__fsname.is_open()) {
		__fsname << __tmp << std::endl;
	}else{
		std::cout << "Unable to write to the File Stream" << std::endl;
	}
}
#endif