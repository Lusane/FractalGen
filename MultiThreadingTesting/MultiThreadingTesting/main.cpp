#define VERITAS_FACTA 420
#include "ThreadHandler.h"
std::vector<std::thread> MTs;
int _WIN_getCPUcount() 
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	return (INT8)sysinfo.dwNumberOfProcessors;
}
void checkForDefaultsUse() 
{
	if (fConfig.useDefaults || fConfig.useSetDeaults) 
	{
		int Sets[8] = 
		{
			fConfig.set1,
			fConfig.set2,
			fConfig.set3,
			fConfig.set4,
			fConfig.set5,
			fConfig.set6,
			fConfig.set7,
			fConfig.set8
		};
		for (int TID = 0; TID < threadCount; TID++) 
		{
			for (int set = 0; set < fConfig.setCount; set++) 
			{
				switch (Sets[set]) 
				{
					case 0:	frac._zr[TID][set] = MandelBrot::zr_[set];
						frac._zi[TID][set] = MandelBrot::zi_[set];
						frac.maxR[TID][set] = MandelBrot::maxR_[set];
						frac.minR[TID][set] = MandelBrot::minR_[set];
						frac.maxI[TID][set] = MandelBrot::maxI_[set];
						frac.minI[TID][set] = MandelBrot::minI_[set];
						frac.maxN[TID][set] = MandelBrot::maxN_[set];
						frac.z[TID][set] = MandelBrot::z_[set];
						frac.maxZ[TID][set] = MandelBrot::maxZ_[set];
						break;
					case 1:	frac._zr[TID][set] = Castle::zr_[set];
						frac._zi[TID][set] = Castle::zi_[set];
						frac.maxR[TID][set] = Castle::maxR_[set];
						frac.minR[TID][set] = Castle::minR_[set];
						frac.maxI[TID][set] = Castle::maxI_[set];
						frac.minI[TID][set] = Castle::minI_[set];
						frac.maxN[TID][set] = Castle::maxN_[set];
						frac.z[TID][set] = Castle::z_[set];
						frac.maxZ[TID][set] = Castle::maxZ_[set];
						break;
					case 2:	frac._zr[TID][set] = HalCorrupted::zr_[set];
						frac._zi[TID][set] = HalCorrupted::zi_[set];
						frac.maxR[TID][set] = HalCorrupted::maxR_[set];
						frac.minR[TID][set] = HalCorrupted::minR_[set];
						frac.maxI[TID][set] = HalCorrupted::maxI_[set];
						frac.minI[TID][set] = HalCorrupted::minI_[set];
						frac.maxN[TID][set] = HalCorrupted::maxN_[set];
						frac.z[TID][set] = HalCorrupted::z_[set];
						frac.maxZ[TID][set] = HalCorrupted::maxZ_[set];
						break;
					case 3:	frac._zr[TID][set] = HourGlass::zr_[set];
						frac._zi[TID][set] = HourGlass::zi_[set];
						frac.maxR[TID][set] = HourGlass::maxR_[set];
						frac.minR[TID][set] = HourGlass::minR_[set];
						frac.maxI[TID][set] = HourGlass::maxI_[set];
						frac.minI[TID][set] = HourGlass::minI_[set];
						frac.maxN[TID][set] = HourGlass::maxN_[set];
						frac.z[TID][set] = HourGlass::z_[set];
						frac.maxZ[TID][set] = HourGlass::maxZ_[set];
						break;
					case 4:	frac._zr[TID][set] = StarBurst::zr_[set];
						frac._zi[TID][set] = StarBurst::zi_[set];
						frac.maxR[TID][set] = StarBurst::maxR_[set];
						frac.minR[TID][set] = StarBurst::minR_[set];
						frac.maxI[TID][set] = StarBurst::maxI_[set];
						frac.minI[TID][set] = StarBurst::minI_[set];
						frac.maxN[TID][set] = StarBurst::maxN_[set];
						frac.z[TID][set] = StarBurst::z_[set];
						frac.maxZ[TID][set] = StarBurst::maxZ_[set];
						break;
				}
				if (fConfig.useDefaults) 
				{
					frac.rMlt[TID][set] = Color::rMlt_[set];
					frac.rDiv[TID][set] = Color::rDiv_[set];
					frac.gMlt[TID][set] = Color::gMlt_[set];
					frac.gDiv[TID][set] = Color::gDiv_[set];
					frac.bMlt[TID][set] = Color::bMlt_[set];
					frac.bDiv[TID][set] = Color::bDiv_[set];
				}
			}
		}
	}
}
void randomFracValues() 
{
	if (fConfig.randomFractalValues) 
	{
		std::vector<double> temp_zr, temp_zi, temp_maxR, temp_minR, temp_maxI, temp_minI;
		std::vector<int> temp_maxN;
		std::vector<float> temp_z, temp_maxZ;
		temp_zr.resize(fConfig.setCount);
		temp_zi.resize(fConfig.setCount);
		temp_maxR.resize(fConfig.setCount);
		temp_minR.resize(fConfig.setCount);
		temp_maxI.resize(fConfig.setCount);
		temp_minI.resize(fConfig.setCount);
		temp_maxN.resize(fConfig.setCount);
		temp_z.resize(fConfig.setCount);
		temp_maxZ.resize(fConfig.setCount);
		int zrSeed = frac.fractalSaftyNet(fConfig.zrSeed), ziSeed = frac.fractalSaftyNet(fConfig.ziSeed);
		double zrSafty = fConfig.zrSafty, zrLimit = fConfig.zrLimit;
		double ziSafty = fConfig.ziSafty, ziLimit = fConfig.ziLimit;
		int maxRSeed = frac.fractalSaftyNet(fConfig.maxRSeed), minRSeed = frac.fractalSaftyNet(fConfig.minRSeed);
		double maxRSafty = frac.fractalSaftyNet(fConfig.maxRSafty), maxRLimit = frac.fractalSaftyNet(fConfig.maxRLimit);
		double minRSafty = frac.fractalSaftyNet(fConfig.minRSafty), minRLimit = frac.fractalSaftyNet(fConfig.minRLimit);
		int maxISeed = frac.fractalSaftyNet(fConfig.maxISeed), minISeed = frac.fractalSaftyNet(fConfig.minISeed);
		double maxISafty = frac.fractalSaftyNet(fConfig.maxISafty), maxILimit = frac.fractalSaftyNet(fConfig.maxILimit);
		double minISafty = frac.fractalSaftyNet(fConfig.minISafty), minILimit = frac.fractalSaftyNet(fConfig.minILimit);
		int maxNSeed = frac.fractalSaftyNet(fConfig.maxNSeed), zSeed = frac.fractalSaftyNet(fConfig.zSeed), maxZSeed = frac.fractalSaftyNet(fConfig.maxZSeed);
		int maxNSafty = frac.fractalSaftyNet(fConfig.maxNSafty), maxNLimit = frac.fractalSaftyNet(fConfig.maxNLimit);
		float zSafty = frac.fractalSaftyNet(fConfig.zSafty), zLimit = frac.fractalSaftyNet(fConfig.zLimit);
		float maxZSafty = frac.fractalSaftyNet(fConfig.maxZSafty), maxZLimit = frac.fractalSaftyNet(fConfig.maxZLimit);
		for (int set = 0; set < fConfig.setCount; set++) 
		{
			temp_zr[set] = dRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / zrSeed)) + 1), dRandomNum(frac.fractalSaftyNet((int)time(0) / zrSeed), zrSafty, zrLimit), double(rand() % (int)zrLimit) + 1) * zrSafty;
			temp_zi[set] = dRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / ziSeed)) + 1), dRandomNum(frac.fractalSaftyNet((int)time(0) / ziSeed), ziSafty, ziLimit), double(rand() % (int)ziLimit) + 1) * ziSafty;
			temp_maxR[set] = frac.fractalSaftyNet(dRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / maxRSeed)) + 1), dRandomNum(frac.fractalSaftyNet((int)time(0) / maxRSeed), maxRSafty, maxRLimit), double(rand() % (int)maxRLimit) + 1) / maxRSafty);
			temp_minR[set] = frac.fractalSaftyNet(dRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / minRSeed)) + 1), dRandomNum(frac.fractalSaftyNet((int)time(0) / minRSeed), minRSafty, minRLimit), double(rand() % (int)minRLimit) + 1) / minRSafty);
			temp_maxI[set] = frac.fractalSaftyNet(dRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / maxISeed)) + 1), dRandomNum(frac.fractalSaftyNet((int)time(0) / maxISeed), maxISafty, maxILimit), double(rand() % (int)maxILimit) + 1) / maxISafty);
			temp_minI[set] = frac.fractalSaftyNet(dRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / minISeed)) + 1), dRandomNum(frac.fractalSaftyNet((int)time(0) / minISeed), minISafty, minILimit), double(rand() % (int)minILimit) + 1) / minISafty);
			temp_maxN[set] = frac.fractalSaftyNet(iRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / maxNSeed)) + 1), iRandomNum(frac.fractalSaftyNet((int)time(0) / maxNSeed), maxNSafty, maxNLimit), (rand() % maxNLimit) + 1) / maxNSafty);
			temp_z[set] = frac.fractalSaftyNet(fRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / zSeed)) + 1), fRandomNum(frac.fractalSaftyNet((int)time(0) / zSeed), zSafty, zLimit), float(rand() % (int)zLimit) + 1) / zSafty);
			temp_maxZ[set] = frac.fractalSaftyNet(fRandomNum((rand() % frac.fractalSaftyNet((int)(time(0) / maxZSeed)) + 1), fRandomNum(frac.fractalSaftyNet((int)time(0) / maxZSeed), maxZSafty, maxZLimit), float(rand() % (int)maxZLimit) + 1) / maxZSafty);
		}
		for (int td = 0; td < threadCount; td++) 
		{
			for (int st = 0; st < fConfig.setCount; st++) 
			{
				frac._zr[td][st] += temp_zr[st];
				frac._zi[td][st] += temp_zi[st];
				frac.maxR[td][st] += temp_maxR[st];
				frac.minR[td][st] -= temp_minR[st];
				frac.maxI[td][st] += temp_maxI[st];
				frac.minI[td][st] -= temp_minI[st];
				frac.maxN[td][st] += temp_maxN[st];
				frac.z[td][st] += temp_z[st];
				frac.maxZ[td][st] += temp_maxZ[st];
			}
		}
	}
}
void randomColors() 
{
	if (fConfig.randomColorValues) 
	{
		std::vector<double> temp_rMlt, temp_gMlt, temp_bMlt;
		std::vector<int> temp_rDiv, temp_gDiv, temp_bDiv;
		temp_rMlt.resize(fConfig.setCount);
		temp_gMlt.resize(fConfig.setCount);
		temp_bMlt.resize(fConfig.setCount);
		temp_rDiv.resize(fConfig.setCount);
		temp_gDiv.resize(fConfig.setCount);
		temp_bDiv.resize(fConfig.setCount);
		for (int sets = 0; sets < fConfig.setCount; sets++) 
		{
			temp_rMlt[sets] = dRandomNum((rand() % (int)(time(0) / fConfig.rMltSeed)), dRandomNum((int)time(0) / fConfig.rMltSeed, fConfig.rMltSafty, fConfig.rMltLimit), (rand() % (int)fConfig.rMltLimit) + 1);
			temp_rDiv[sets] = iRandomNum((rand() % (int)(time(0) / fConfig.rDivSeed)), iRandomNum((int)time(0) / fConfig.rDivSeed, fConfig.rDivSafty, fConfig.rDivLimit), (rand() % (int)fConfig.rDivLimit) + 1);
			temp_gMlt[sets] = dRandomNum((rand() % (int)(time(0) / fConfig.gMltSeed)), dRandomNum((int)time(0) / fConfig.gMltSeed, fConfig.gMltSafty, fConfig.gMltLimit), (rand() % (int)fConfig.gMltLimit) + 1);
			temp_gDiv[sets] = iRandomNum((rand() % (int)(time(0) / fConfig.gDivSeed)), iRandomNum((int)time(0) / fConfig.gDivSeed, fConfig.gDivSafty, fConfig.gDivLimit), (rand() % (int)fConfig.gDivLimit) + 1);
			temp_bMlt[sets] = dRandomNum((rand() % (int)(time(0) / fConfig.bMltSeed)), dRandomNum((int)time(0) / fConfig.bMltSeed, fConfig.bMltSafty, fConfig.bMltLimit), (rand() % (int)fConfig.bMltLimit) + 1);
			temp_bDiv[sets] = iRandomNum((rand() % (int)(time(0) / fConfig.bDivSeed)), iRandomNum((int)time(0) / fConfig.bDivSeed, fConfig.bDivSafty, fConfig.bDivLimit), (rand() % (int)fConfig.bDivLimit) + 1);
		}
		for (int td = 0; td < threadCount; td++) 
		{
			for (int st = 0; st < fConfig.setCount; st++) 
			{
				frac.rMlt[td][st] = temp_rMlt[st];
				frac.rDiv[td][st] = temp_rDiv[st];
				frac.gMlt[td][st] = temp_gMlt[st];
				frac.gDiv[td][st] = temp_gDiv[st];
				frac.bMlt[td][st] = temp_bMlt[st];
				frac.bDiv[td][st] = temp_bDiv[st];
			}
		}
		temp_rMlt.resize(0);
		temp_gMlt.resize(0);
		temp_bMlt.resize(0);
		temp_rDiv.resize(0);
		temp_gDiv.resize(0);
		temp_bDiv.resize(0);
	}
}
void genFrac(int InitX, int FinalX, int InitY, int FinalY, int id)
{
	std::stringstream ID;
	ID << id;
	Geni[id] = true;
	int Set[8] = { fConfig.set1, fConfig.set2, fConfig.set3, fConfig.set4, fConfig.set5, fConfig.set6, fConfig.set7, fConfig.set8 };
	Sleep(10);
	int y;
	int x;
	int _x = InitX;
	int _y = InitY;
	float PerY1;
	float PerY2;
	float PerX1;
	float PerX2;
	double* cr;
	double* ci;
	cr = new double[fConfig.setCount];
	ci = new double[fConfig.setCount];
	int* n;
	n = new int[fConfig.setCount];
	double* dRed;
	double* dGreen;
	double* dBlue;
	dRed = new double[fConfig.setCount];
	dGreen = new double[fConfig.setCount];
	dBlue = new double[fConfig.setCount];
	for (y = 0; y < (int)(ceil(frac.height / threadCount) + 1); y++)
	{
		if (_y >= FinalY)
		{
			_y = InitY;
		}
		for (x = 0; x < frac.width; x++)
		{
			if (_x >= FinalX)
			{
				_x = InitX;
			}
			for (int st = 0; st < fConfig.setCount; st++)
			{
				cr[st] = frac.mapTo(_x, frac.width, frac.maxR[id][st], frac.minR[id][st]);
				ci[st] = frac.mapTo(_y, frac.height, frac.maxI[id][st], frac.minI[id][st]);
				switch (Set[st])
				{
				case 0: n[st] = MandelBrot::mandelBrot(frac._zr[id][st], cr[st], frac._zi[id][st], ci[st], frac.maxN[id][st], frac.z[id][st], frac.maxZ[id][st]);
					break;
				case 1: n[st] = Castle::castle(frac._zr[id][st], cr[st], frac._zi[id][st], ci[st], frac.maxN[id][st], frac.z[id][st], frac.maxZ[id][st]);
					break;
				case 2: n[st] = HalCorrupted::halCorrupted(frac._zr[id][st], cr[st], frac._zi[id][st], ci[st], frac.maxN[id][st], frac.z[id][st], frac.maxZ[id][st]);
					break;
				case 3: n[st] = HourGlass::hourGlass(frac._zr[id][st], cr[st], frac._zi[id][st], ci[st], frac.maxN[id][st], frac.z[id][st], frac.maxZ[id][st]);
					break;
				case 4: n[st] = StarBurst::starBurst(frac._zr[id][st], cr[st], frac._zi[id][st], ci[st], frac.maxN[id][st], frac.z[id][st], frac.maxZ[id][st]);
					break;
				}
				dRed[st] = frac.ColorSaftyNet((double)(((int)((double)n[st] * frac.rMlt[id][st]) % frac.rDiv[id][st]) + (int)PI));
				dGreen[st] = frac.ColorSaftyNet((double)(((int)((double)n[st] * frac.gMlt[id][st]) % frac.gDiv[id][st]) + (int)PI));
				dBlue[st] = frac.ColorSaftyNet((double)(((int)((double)n[st] * frac.bMlt[id][st]) % frac.bDiv[id][st]) + (int)PI));
			}
			Thread_RGB[id][y][x] = frac.getRGB(dRed,dGreen,dBlue,ID.str());
			if (x != 0 && y != 0)
			{
				PerX1 = (float)((x + 1)) / (float)(frac.width + 1);
				PerX2 = PerX1 * (float)100.0f;
				threadProgs[id][0] = floor(PerX2);
			}
			_x++;
		}
		if(y != 0)
		{
			PerY1 = (float)((y + 1)) / (float)((ceil(frac.height / threadCount) + 1));
			PerY2 = PerY1 * (float)100.0f;
			threadProgs[id][1] = floor(PerY2);
		}
		_y++;
	}
	Geni[id] = false;
	Done_Geni[id] = true;
	Sleep(10);
	std::this_thread::yield();
}
void AssemableImage()
{
	ImageMaking = true;
	Sleep(10);
	std::stringstream Name;
	Name << mConfig.name;
	std::stringstream FileExt;
	FileExt << mConfig.fileExtension;
	std::string imageName = Name.str() + FileExt.str();
	std::cout << "Making " + FileExt.str() << std::endl;
	std::ofstream Image(imageName);
	Image << "P3" << std::endl;
	Image << frac.width << " " << frac.height << std::endl;
	float PerY1;
	float PerY2;
	float PerX1;
	float PerX2;
	for (int td = 0; td < threadCount; td++)
	{
		for (int y = 0; y < (int)(ceil(frac.height / threadCount) + 1); y++)
		{
			for (int x = 0; x < frac.width; x++)
			{
				Image << Thread_RGB[td][y][x];
				if (x != 0 && y != 0)
				{
					PerX1 = (float)((x + 1)) / (float)(frac.width);
					PerX2 = PerX1 * (float)100.0f;
					ImageProg[0] = floor(PerX2);
				}
			}
			if (y != 0) 
			{
				PerY1 = (float)((y + 1)) / (float)((ceil(frac.height / threadCount) + 1));
				PerY2 = PerY1 * (float)100.0f;
				ImageProg[1] = floor(PerY2);
			}
			Image << std::endl;
		}
	}
	Image.close();
	ImageMaking = false;
	ImageAssembled = true;
	Sleep(10);
	std::cout << FileExt.str() << " Finished" << std::endl;
}
void coutProgress() {
	while (ContinueRunning && !ForceShutDown)
	{
		while (trackProg)
		{
			for (int FT = 0; FT < threadCount; ++FT)
			{
				if (Geni[FT])
				{
					std::cout << "Fractal Thread " << FT << ": " << threadProgs[FT][1] << "." << threadProgs[FT][0] << "%" << std::endl;
				}
			}
			if (ImageMaking)
			{
				std::cout << "Image Compiling: " << ImageProg[1] << "." << ImageProg[0] << "%" << std::endl;
			}
			Sleep(40);
		}
	}
	std::this_thread::yield();
}
void quit() 
{
	char input;
	std::cout << "To veiw the LICENSE.txt enter l, To veiw the README.md enter r." << std::endl << "Do You want to generate a fractal or close the program?(f, c)" << std::endl;
	std::cin >> input;
	switch (input) 
	{
	case 'f':
	case 'F':
		ContinueRunning = true;
		break;
	case 'c':
	case 'C':
		ContinueRunning = false;
		break;
	case 'l':
	case 'L':
		system("START LICENSE.txt");
		quit();
		break;
	case 'r':
	case 'R':
		system("START README.md");
		quit();
		break;
	default:
		std::cout << "Not possible, try again." << std::endl;
		quit();
		break;
	}
}
void pause()
{
	if (!mConfig.skipPauses)
	{
		std::cout << "Press Any Key..." << std::endl;
		std::cin.ignore();
	}
}
void loop() 
{
	trackProg = true;
	InitMem();
	Sleep(10);
	checkForDefaultsUse();
	randomFracValues();
	randomColors();
	pause();
	Timestamp("Start Time: ");
	InitThreads();
	Sleep(10);
	pause();
	initImageThread();
	Timestamp("End Time: ");
	Sleep(10);
	DeallocateMem();
	Sleep(10);
	trackProg = false;
}
void MainLoopControl() 
{
	while (ContinueRunning && !ForceShutDown && !ReInitThreads)
	{
		bool bCProg = mConfig.CoutProgress;
		Sleep(10);
		ini_parse("Program.ini", mainHandler, &mConfig);
		ini_parse("Fractal.ini", fractalHandler, &fConfig);
		ini_parse("Sets.ini", fracSetHandler, &fSets);
		Sleep(10);
		if (mConfig.CoutProgress != bCProg)
		{
			ReInitThreads = true;
			ForceShutDown = true;
		}
		Sleep(10);
		frac.width = mConfig.width;
		frac.height = mConfig.height;
		loop();
		quit();
	}
	std::this_thread::yield();
}
void ControlValueInit()
{
	threadCount = mConfig.ThreadCount;
	if (isWIN)
	{
		std::cout << "Counting CPU Cores..." << std::endl;
		int ncpu = _WIN_getCPUcount();
		if (threadCount > ncpu)
		{
			std::cout << "thread count is to high reducing from " << threadCount << " to " << ncpu << std::endl;
			threadCount = ncpu;
		}
	}
	MemAllocating = new bool[4];
	MemAllocationDone = new bool[4];
	MemDeallocating = new bool[4];
	MemDeallocationDone = new bool[4];
	Sleep(10);
	for (int Mem = 0; Mem < 4; ++Mem) 
	{
		MemAllocating[4] = false;
		MemAllocationDone[4] = false;
		MemDeallocating[4] = false;
		MemDeallocationDone[4] = false;
	}
	Geni = new bool[threadCount];
	for (int gRe = 0; gRe < threadCount; ++gRe)
	{
		Geni[gRe] = false;
	}
	Done_Geni = new bool[threadCount];
	for (int dgRe = 0; dgRe < threadCount; ++dgRe)
	{
		Done_Geni[dgRe] = false;
	}
	threadProgs.resize(threadCount);
	for (int tpCap = 0; tpCap < threadCount; tpCap++)
	{
		threadProgs[tpCap].resize(2);
	}
	ImageProg.resize(2);
}
void MainThreadDestruction()
{
	for (auto& mt : MTs)
	{
		mt.~thread();
	}
	MTs.clear();
	MTs.resize(0);
}
void joiningofMainThreads()
{
	for (auto& mt : MTs)
	{
		mt.join();
	}
	Sleep(50);
	MainThreadDestruction();
}
void MainThreadCreation()
{
	if (MTs.capacity() == 2)
	{
		MTs.resize(0);
	}
	MTs.push_back(std::thread(MainLoopControl));
	if (mConfig.CoutProgress) 
	{
		MTs.push_back(std::thread(coutProgress));
	}
	Sleep(50);
	joiningofMainThreads();
}
void Timestamp(std::string text) 
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	std::cout << "Time: ";
	std::cout << now->tm_hour << ":";
	std::cout << now->tm_min << ":";
	std::cout << now->tm_sec << std::endl;
}
time_t getCurrentTimeInSec() 
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	return now->tm_sec;
}
int iRandomNum(int randSeed, int low, int high) 
{
	srand((unsigned)randSeed);
	int lowest = low, highest = high;
	int range = (highest - lowest) + 1;
	return (lowest + int(range*rand() / (RAND_MAX + 1.0)));
}
float fRandomNum(int randSeed, float low, float high) 
{
	srand((unsigned)randSeed);
	float lowest = low, highest = high;
	float range = (highest - lowest) + 1;
	return (lowest + float(range*rand() / (RAND_MAX + 1.0)));
}
double dRandomNum(int randSeed, double low, double high) 
{
	srand((unsigned)randSeed);
	double lowest = low, highest = high;
	double range = (highest - lowest) + 1;
	return (lowest + double(range*rand() / (RAND_MAX + 1.0)));
}
int main()
{
	std::cout << "ini.h/ini.c Copyright (c) 2009, Ben Hoyt" << std::endl << std::endl;
	std::cout << "Copyright (C) 2018  Donovan McEnnerney" << std::endl << "This program comes with ABSOLUTELY NO WARRANTY!" << std::endl << "This is free software, and you are welcome to redistribute it under certain conditions, See LICENSE.txt for details." << std::endl << std::endl;
	std::cout << "Current Version: " << Version << std::endl;
	if ((ini_parse("Program.ini", mainHandler, &mConfig) < 0) || (ini_parse("Fractal.ini", fractalHandler, &fConfig) < 0) || (ini_parse("Sets.ini", fracSetHandler, &fSets) < 0)) 
	{
		return 1;
	}
	bool bCProg = mConfig.CoutProgress;
	if (InitAll)
	{
		ControlValueInit();
		InitAll = false;
	}
	quit();
	MainThreadCreation();
	if (ContinueRunning && ReInitThreads)
	{
		if (ForceShutDown)
		{
			ForceShutDown = false;
		}
		ReInitThreads = false;
		return main();
	}
	return 0;
}