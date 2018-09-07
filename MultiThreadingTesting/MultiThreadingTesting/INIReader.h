#define VERITAS_FACTA 420
#include "Util.h"

//*****FOR PROGRAM.INI*****
typedef struct {
	//For Protocols
	int ThreadCount;
	bool CoutProgress;
	bool skipPauses;

	//For File
	char* name;
	int width;
	int height;
	char* fileExtension;
} mainConfiguration;

static int mainHandler(void* user, const char* section, const char* name, const char* value){
	mainConfiguration* pconfig = (mainConfiguration*)user;

	#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
	if (MATCH("Protocol", "ThreadCount")) {
		pconfig->ThreadCount = atoi(value);
	}
	else if (MATCH("Protocol", "coutProgress")) {
		pconfig->CoutProgress = atoi(value);
	}
	else if (MATCH("Protocol", "skipPauses")) {
		pconfig->skipPauses = atoi(value);
	}
	else if (MATCH("File", "name")) {
		pconfig->name = _strdup(value);
	}
	else if (MATCH("File", "width")) {
		pconfig->width = atoi(value);
	}
	else if (MATCH("File", "height")) {
		pconfig->height = atoi(value);
	}
	else if(MATCH("File", "fileExtension")) {
		pconfig->fileExtension = _strdup(value);
	}
	else {
		return 0;  /* unknown section/name, error */
	}
	return 1;
}


//*****FOR FRACTAL.INI*****
typedef struct {
	//For Main Section
	int setCount;
	bool useDefaults;
	bool useSetDeaults;
	bool randomColorValues;
	bool Inverted;
	bool Intensify;
	float Intensity;

	//For RCC Section
	int rMltLimit;
	int rDivLimit;
	int gMltLimit;
	int gDivLimit;
	int bMltLimit;
	int bDivLimit;

	//For Sets Section
	int set1;
	int set2;
	int set3;
	int set4;
	int set5;
	int set6;
	int set7;
	int set8;

} fractalConfiguration;

static int fractalHandler(void* user, const char* section, const char* name, const char* value) {
	fractalConfiguration* fconfig = (fractalConfiguration*)user;

	#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
	//Main
	if (MATCH("Main", "SetCount")) {
		fconfig->setCount = atoi(value);
	}
	else if (MATCH("Main", "useDefaults")) {
		fconfig->useDefaults = atoi(value);
	}
	else if (MATCH("Main", "useSetDefaults")) {
		fconfig->useSetDeaults = atoi(value);
	}
	else if (MATCH("Main", "randomColorValues")) {
		fconfig->randomColorValues = atoi(value);
	}
	else if (MATCH("Main", "Inverted")) {
		fconfig->Inverted = atoi(value);
	}
	else if (MATCH("Main", "Intensify")) {
		fconfig->Intensify = atoi(value);
	}
	else if (MATCH("Main", "Intensity")) {
		fconfig->Intensity = (float)atof(value);
	}
	//RCC
	else if (MATCH("RCC", "rMltLimit")) {
		fconfig->rMltLimit = atoi(value);
	}
	else if (MATCH("RCC", "rDivLimit")) {
		fconfig->rDivLimit = atoi(value);
	}
	else if (MATCH("RCC", "gMltLimit")) {
		fconfig->gMltLimit = atoi(value);
	}
	else if (MATCH("RCC", "gDivLimit")) {
		fconfig->gDivLimit = atoi(value);
	}
	else if (MATCH("RCC", "bMltLimit")) {
		fconfig->bMltLimit = atoi(value);
	}
	else if (MATCH("RCC", "bDivLimit")) {
		fconfig->bDivLimit = atoi(value);
	}
	//Sets
	else if (MATCH("Sets", "set1")) {
		fconfig->set1 = atoi(value);
	}
	else if (MATCH("Sets", "set2")) {
		fconfig->set2 = atoi(value);
	}
	else if (MATCH("Sets", "set3")) {
		fconfig->set3 = atoi(value);
	}
	else if (MATCH("Sets", "set4")) {
		fconfig->set4 = atoi(value);
	}
	else if (MATCH("Sets", "set5")) {
		fconfig->set5 = atoi(value);
	}
	else if (MATCH("Sets", "set6")) {
		fconfig->set6 = atoi(value);
	}
	else if (MATCH("Sets", "set7")) {
		fconfig->set7 = atoi(value);
	}
	else if (MATCH("Sets", "set8")) {
		fconfig->set8 = atoi(value);
	}
	else {
		return 0;  /* unknown section/name, error */
	}
	return 1;
}

typedef struct {
	//For Set Sections
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

static int fracSetHandler(void* user, const char* section, const char* name, const char* value) {
	FracSets* fconfig = (FracSets*)user;
	//Set 1
	if (MATCH("Set1", "zr")) {
		fconfig->zr[0] = atoi(value);
	}
	else if (MATCH("Set1", "zi")) {
		fconfig->zi[0] = atoi(value);
	}
	else if (MATCH("Set1", "maxR")) {
		fconfig->maxR[0] = atoi(value);
	}
	else if (MATCH("Set1", "minR")) {
		fconfig->minR[0] = atoi(value);
	}
	else if (MATCH("Set1", "maxI")) {
		fconfig->maxI[0] = atoi(value);
	}
	else if (MATCH("Set1", "minI")) {
		fconfig->minI[0] = atoi(value);
	}
	else if (MATCH("Set1", "maxN")) {
		fconfig->maxN[0] = atoi(value);
	}
	else if (MATCH("Set1", "z")) {
		fconfig->z[0] = (float)atof(value);
	}
	else if (MATCH("Set1", "maxZ")) {
		fconfig->maxZ[0] = (float)atof(value);
	}
	else if (MATCH("Set1", "rMlt")) {
		fconfig->rMlt[0] = (float)atof(value);
	}
	else if (MATCH("Set1", "rDiv")) {
		fconfig->rDiv[0] = atoi(value);
	}
	else if (MATCH("Set1", "gMlt")) {
		fconfig->gMlt[0] = (float)atof(value);
	}
	else if (MATCH("Set1", "gDiv")) {
		fconfig->gDiv[0] = atoi(value);
	}
	else if (MATCH("Set1", "bMlt")) {
		fconfig->bMlt[0] = (float)atof(value);
	}
	else if (MATCH("Set1", "bDiv")) {
		fconfig->bDiv[0] = atoi(value);
	}
	//Set 2
	else if (MATCH("Set2", "zr")) {
		fconfig->zr[1] = atoi(value);
	}
	else if (MATCH("Set2", "zi")) {
		fconfig->zi[1] = atoi(value);
	}
	else if (MATCH("Set2", "maxR")) {
		fconfig->maxR[1] = atoi(value);
	}
	else if (MATCH("Set2", "minR")) {
		fconfig->minR[1] = atoi(value);
	}
	else if (MATCH("Set2", "maxI")) {
		fconfig->maxI[1] = atoi(value);
	}
	else if (MATCH("Set2", "minI")) {
		fconfig->minI[1] = atoi(value);
	}
	else if (MATCH("Set2", "maxN")) {
		fconfig->maxN[1] = atoi(value);
	}
	else if (MATCH("Set2", "z")) {
		fconfig->z[1] = (float)atof(value);
	}
	else if (MATCH("Set2", "maxZ")) {
		fconfig->maxZ[1] = (float)atof(value);
	}
	else if (MATCH("Set2", "rMlt")) {
		fconfig->rMlt[1] = (float)atof(value);
	}
	else if (MATCH("Set2", "rDiv")) {
		fconfig->rDiv[1] = atoi(value);
	}
	else if (MATCH("Set2", "gMlt")) {
		fconfig->gMlt[1] = (float)atof(value);
	}
	else if (MATCH("Set2", "gDiv")) {
		fconfig->gDiv[1] = atoi(value);
	}
	else if (MATCH("Set2", "bMlt")) {
		fconfig->bMlt[1] = (float)atof(value);
	}
	else if (MATCH("Set2", "bDiv")) {
		fconfig->bDiv[1] = atoi(value);
	}
	//Set 3
	else if (MATCH("Set3", "zr")) {
		fconfig->zr[2] = atoi(value);
	}
	else if (MATCH("Set3", "zi")) {
		fconfig->zi[2] = atoi(value);
	}
	else if (MATCH("Set3", "maxR")) {
		fconfig->maxR[2] = atoi(value);
	}
	else if (MATCH("Set3", "minR")) {
		fconfig->minR[2] = atoi(value);
	}
	else if (MATCH("Set3", "maxI")) {
		fconfig->maxI[2] = atoi(value);
	}
	else if (MATCH("Set3", "minI")) {
		fconfig->minI[2] = atoi(value);
	}
	else if (MATCH("Set3", "maxN")) {
		fconfig->maxN[2] = atoi(value);
	}
	else if (MATCH("Set3", "z")) {
		fconfig->z[2] = (float)atof(value);
	}
	else if (MATCH("Set3", "maxZ")) {
		fconfig->maxZ[2] = (float)atof(value);
	}
	else if (MATCH("Set3", "rMlt")) {
		fconfig->rMlt[2] = (float)atof(value);
	}
	else if (MATCH("Set3", "rDiv")) {
		fconfig->rDiv[2] = atoi(value);
	}
	else if (MATCH("Set3", "gMlt")) {
		fconfig->gMlt[2] = (float)atof(value);
	}
	else if (MATCH("Set3", "gDiv")) {
		fconfig->gDiv[2] = atoi(value);
	}
	else if (MATCH("Set3", "bMlt")) {
		fconfig->bMlt[2] = (float)atof(value);
	}
	else if (MATCH("Set3", "bDiv")) {
		fconfig->bDiv[2] = atoi(value);
	}
	//Set4
	else if (MATCH("Set4", "zr")) {
		fconfig->zr[3] = atoi(value);
	}
	else if (MATCH("Set4", "zi")) {
		fconfig->zi[3] = atoi(value);
	}
	else if (MATCH("Set4", "maxR")) {
		fconfig->maxR[3] = atoi(value);
	}
	else if (MATCH("Set4", "minR")) {
		fconfig->minR[3] = atoi(value);
	}
	else if (MATCH("Set4", "maxI")) {
		fconfig->maxI[3] = atoi(value);
	}
	else if (MATCH("Set4", "minI")) {
		fconfig->minI[3] = atoi(value);
	}
	else if (MATCH("Set4", "maxN")) {
		fconfig->maxN[3] = atoi(value);
	}
	else if (MATCH("Set4", "z")) {
		fconfig->z[3] = (float)atof(value);
	}
	else if (MATCH("Set4", "maxZ")) {
		fconfig->maxZ[3] = (float)atof(value);
	}
	else if (MATCH("Set4", "rMlt")) {
		fconfig->rMlt[3] = (float)atof(value);
	}
	else if (MATCH("Set4", "rDiv")) {
		fconfig->rDiv[3] = atoi(value);
	}
	else if (MATCH("Set4", "gMlt")) {
		fconfig->gMlt[3] = (float)atof(value);
	}
	else if (MATCH("Set4", "gDiv")) {
		fconfig->gDiv[3] = atoi(value);
	}
	else if (MATCH("Set4", "bMlt")) {
		fconfig->bMlt[3] = (float)atof(value);
	}
	else if (MATCH("Set4", "bDiv")) {
		fconfig->bDiv[3] = atoi(value);
	}
	//Set5
	else if (MATCH("Set5", "zr")) {
		fconfig->zr[4] = atoi(value);
	}
	else if (MATCH("Set5", "zi")) {
		fconfig->zi[4] = atoi(value);
	}
	else if (MATCH("Set5", "maxR")) {
		fconfig->maxR[4] = atoi(value);
	}
	else if (MATCH("Set5", "minR")) {
		fconfig->minR[4] = atoi(value);
	}
	else if (MATCH("Set5", "maxI")) {
		fconfig->maxI[4] = atoi(value);
	}
	else if (MATCH("Set5", "minI")) {
		fconfig->minI[4] = atoi(value);
	}
	else if (MATCH("Set5", "maxN")) {
		fconfig->maxN[4] = atoi(value);
	}
	else if (MATCH("Set5", "z")) {
		fconfig->z[4] = (float)atof(value);
	}
	else if (MATCH("Set5", "maxZ")) {
		fconfig->maxZ[4] = (float)atof(value);
	}
	else if (MATCH("Set5", "rMlt")) {
		fconfig->rMlt[4] = (float)atof(value);
	}
	else if (MATCH("Set5", "rDiv")) {
		fconfig->rDiv[4] = atoi(value);
	}
	else if (MATCH("Set5", "gMlt")) {
		fconfig->gMlt[4] = (float)atof(value);
	}
	else if (MATCH("Set5", "gDiv")) {
		fconfig->gDiv[4] = atoi(value);
	}
	else if (MATCH("Set5", "bMlt")) {
		fconfig->bMlt[4] = (float)atof(value);
	}
	else if (MATCH("Set5", "bDiv")) {
		fconfig->bDiv[4] = atoi(value);
	}
	//Set6
	else if (MATCH("Set6", "zr")) {
		fconfig->zr[5] = atoi(value);
	}
	else if (MATCH("Set6", "zi")) {
		fconfig->zi[5] = atoi(value);
	}
	else if (MATCH("Set6", "maxR")) {
		fconfig->maxR[5] = atoi(value);
	}
	else if (MATCH("Set6", "minR")) {
		fconfig->minR[5] = atoi(value);
	}
	else if (MATCH("Set6", "maxI")) {
		fconfig->maxI[5] = atoi(value);
	}
	else if (MATCH("Set6", "minI")) {
		fconfig->minI[5] = atoi(value);
	}
	else if (MATCH("Set6", "maxN")) {
		fconfig->maxN[5] = atoi(value);
	}
	else if (MATCH("Set6", "z")) {
		fconfig->z[5] = (float)atof(value);
	}
	else if (MATCH("Set6", "maxZ")) {
		fconfig->maxZ[5] = (float)atof(value);
	}
	else if (MATCH("Set6", "rMlt")) {
		fconfig->rMlt[5] = (float)atof(value);
	}
	else if (MATCH("Set6", "rDiv")) {
		fconfig->rDiv[5] = atoi(value);
	}
	else if (MATCH("Set6", "gMlt")) {
		fconfig->gMlt[5] = (float)atof(value);
	}
	else if (MATCH("Set6", "gDiv")) {
		fconfig->gDiv[5] = atoi(value);
	}
	else if (MATCH("Set6", "bMlt")) {
		fconfig->bMlt[5] = (float)atof(value);
	}
	else if (MATCH("Set6", "bDiv")) {
		fconfig->bDiv[5] = atoi(value);
	}
	//Set7
	else if (MATCH("Set7", "zr")) {
		fconfig->zr[6] = atoi(value);
	}
	else if (MATCH("Set7", "zi")) {
		fconfig->zi[6] = atoi(value);
	}
	else if (MATCH("Set7", "maxR")) {
		fconfig->maxR[6] = atoi(value);
	}
	else if (MATCH("Set7", "minR")) {
		fconfig->minR[6] = atoi(value);
	}
	else if (MATCH("Set7", "maxI")) {
		fconfig->maxI[6] = atoi(value);
	}
	else if (MATCH("Set7", "minI")) {
		fconfig->minI[6] = atoi(value);
	}
	else if (MATCH("Set7", "maxN")) {
		fconfig->maxN[6] = atoi(value);
	}
	else if (MATCH("Set7", "z")) {
		fconfig->z[6] = (float)atof(value);
	}
	else if (MATCH("Set7", "maxZ")) {
		fconfig->maxZ[6] = (float)atof(value);
	}
	else if (MATCH("Set7", "rMlt")) {
		fconfig->rMlt[6] = (float)atof(value);
	}
	else if (MATCH("Set7", "rDiv")) {
		fconfig->rDiv[6] = atoi(value);
	}
	else if (MATCH("Set7", "gMlt")) {
		fconfig->gMlt[6] = (float)atof(value);
	}
	else if (MATCH("Set7", "gDiv")) {
		fconfig->gDiv[6] = atoi(value);
	}
	else if (MATCH("Set7", "bMlt")) {
		fconfig->bMlt[6] = (float)atof(value);
	}
	else if (MATCH("Set7", "bDiv")) {
		fconfig->bDiv[6] = atoi(value);
	}
	//Set8
	else if (MATCH("Set8", "zr")) {
		fconfig->zr[7] = atoi(value);
	}
	else if (MATCH("Set8", "zi")) {
		fconfig->zi[7] = atoi(value);
	}
	else if (MATCH("Set8", "maxR")) {
		fconfig->maxR[7] = atoi(value);
	}
	else if (MATCH("Set8", "minR")) {
		fconfig->minR[7] = atoi(value);
	}
	else if (MATCH("Set8", "maxI")) {
		fconfig->maxI[7] = atoi(value);
	}
	else if (MATCH("Set8", "minI")) {
		fconfig->minI[7] = atoi(value);
	}
	else if (MATCH("Set8", "maxN")) {
		fconfig->maxN[7] = atoi(value);
	}
	else if (MATCH("Set8", "z")) {
		fconfig->z[7] = (float)atof(value);
	}
	else if (MATCH("Set8", "maxZ")) {
		fconfig->maxZ[7] = (float)atof(value);
	}
	else if (MATCH("Set8", "rMlt")) {
		fconfig->rMlt[7] = (float)atof(value);
	}
	else if (MATCH("Set8", "rDiv")) {
		fconfig->rDiv[7] = atoi(value);
	}
	else if (MATCH("Set8", "gMlt")) {
		fconfig->gMlt[7] = (float)atof(value);
	}
	else if (MATCH("Set8", "gDiv")) {
		fconfig->gDiv[7] = atoi(value);
	}
	else if (MATCH("Set8", "bMlt")) {
		fconfig->bMlt[7] = (float)atof(value);
	}
	else if (MATCH("Set8", "bDiv")) {
		fconfig->bDiv[7] = atoi(value);
	}
	else {
		return 0;  /* unknown section/name, error */
	}
	return 1;
}
