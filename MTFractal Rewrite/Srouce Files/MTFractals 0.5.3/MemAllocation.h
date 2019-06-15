#define VERITAS_FACTA 420
#include "Fractal.cpp"
#if isWindows
bool is64bit = getWindowsBit(is64bit);
#elif isLinux
bool is64Bit = getLinuxBit(is64Bit);
#endif
void RTA_Init();
void TVA_Init();
void setFrac();
void MemAllocationThreadCreation();
void MemAllocationThreadDestruction();
void JoinMemAllocationThreads();
void InitMem();