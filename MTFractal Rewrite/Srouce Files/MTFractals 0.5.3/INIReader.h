#define VERITAS_FACTA 420
#include "Util.h"
#include <stdlib.h>
///*****FOR PROGRAM.INI*****
typedef struct 
{
	///For Protocols
	int ThreadCount;
	bool CoutProgress;
	bool skipPauses;
	bool addImageDetailsToName;
	///For File
	char* name;
	int width;
	int height;
	char* fileExtension;
} mainConfiguration;
static int mainHandler(void* user, const char* section, const char* name, const char* value);
///*****FOR FRACTAL.INI*****
typedef struct 
{
	///For Main Section
	int setCount;
	bool useDefaults;
	bool useSetDefaults;
	int colorBitMulti;
	bool randomFractalValues;
	bool randomColorValues;
	bool Inverted;
	bool Intensify;
	float Intensity;
	bool FaverRed;
	bool FaverGreen;
	bool FaverBlue;
	///For RFC Section
	double zrSafty;
	double zrLimit;
	int zrSeed;
	double ziSafty;
	double ziLimit;
	int ziSeed;
	double maxRSafty;
	double maxRLimit;
	int maxRSeed;
	double minRSafty;
	double minRLimit;
	int minRSeed;
	double maxISafty;
	double maxILimit;
	int maxISeed;
	double minISafty;
	double minILimit;
	int minISeed;
	int maxNSafty;
	int maxNLimit;
	int maxNSeed;
	float zSafty;
	float zLimit;
	int zSeed;
	float maxZSafty;
	float maxZLimit;
	int maxZSeed;
	///For RCC Section
	double rMltLimit;
	double rMltSafty;
	int rMltSeed;
	int rDivLimit;
	int rDivSafty;
	int rDivSeed;
	double gMltLimit;
	double gMltSafty;
	int gMltSeed;
	int gDivLimit;
	int gDivSafty;
	int gDivSeed;
	double bMltLimit;
	double bMltSafty;
	int bMltSeed;
	int bDivLimit;
	int bDivSafty;
	int bDivSeed;
	///For Sets Section
	int set1;
	int set2;
	int set3;
	int set4;
	int set5;
	int set6;
	int set7;
	int set8;
} fractalConfiguration;
static int fractalHandler(void* user, const char* section, const char* name, const char* value);
typedef struct 
{
	///For Set Sections
	double zr[8];
	double zi[8];
	double maxR[8];
	double minR[8];
	double maxI[8];
	double minI[8];
	int maxN[8];
	float z[8];
	float maxZ[8];
	float rMlt[8];
	int rDiv[8];
	float gMlt[8];
	int gDiv[8];
	float bMlt[8];
	int bDiv[8];
}FracSets;
static int fracSetHandler(void* user, const char* section, const char* name, const char* value);