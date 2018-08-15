#include <ios>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <atomic>
#include <vector>

std::ofstream mT_log("mT_log.txt");
std::ofstream mB_log("mB_log.txt");

std::atomic<const double> PI = 3.1416;

int width = 2048;
int height = 2048;

std::atomic<double> zr(0.0);
std::atomic<double> maxR(2.2);
std::atomic<double> minR(-2.2);

std::atomic<double> zi(0.0);
std::atomic<double> maxI(2.2);
std::atomic<double> minI(-2.2);

std::atomic<int> maxN(25);
std::atomic<float> z(2.0);
std::atomic<float> maxZ(4.0);

std::atomic<float> rMlt(8.0);
std::atomic<int> rDiv(256);
std::atomic<float> gMlt(8.0);
std::atomic<int> gDiv(256);
std::atomic<float> bMlt(8.0);
std::atomic<int> bDiv(256);

std::vector<std::thread> threads;
std::vector<std::thread> MATs;
std::vector<std::thread> MDATs;

bool Geni[3] = { false, false, false };
bool Done_Geni[3] = { false, false, false };

std::vector<std::vector<std::vector<std::string>>> Thread_RGB;

bool MemAllocating = false;
bool MemAllocated = false;
bool MemDeallocating = false;
bool MemDeallocated = false;

bool ImageMaking = false;
bool ImageAssembled = false;

std::vector<std::vector<int>> threadValues;
std::vector<float> threadValueS;

bool RTA_Allocating = false;
bool RTA_Deallocating = false;
bool RTA_Done = false;
bool RTA_Empty = true;
bool TVA_Allocating = false;
bool TVA_Deallocating = false;
bool TVA_Done = false;
bool TVA_Empty = true;

double mapTo(int axis, int size, double max, double min)
{
	//mT_log << "axis: " << axis << std::endl;
	//mT_log << "size: " << size << std::endl;
	//mT_log << "max: " << max << std::endl;
	//mT_log << "min: " << min << std::endl;

	double range = max - min;
	//mT_log << "range: " << range << std::endl;

	return axis * (range / size) + min;
}

int MandelBrot(double zR, double cr, double zI, double ci, int MaxN, float Z, float MaxZ)
{
	//mB_log << "zR: " << zR << std::endl;
	//mB_log << "cr: " << cr << std::endl;
	//mB_log << "zI: " << zI << std::endl;
	//mB_log << "ci: " << ci << std::endl;
	//mB_log << "MaxN: " << MaxN << std::endl;
	//mB_log << "Z: " << Z << std::endl;
	//mB_log << "MaxZ: " << MaxZ << std::endl;
	int i = 0;
	double zr = zR;
	double zi = zI;
	do
	{
		double temp = zr * zr - zi * zi + cr;
		//mB_log << "temp: " << temp << std::endl;

		zi = z * (zr*zi) + ci;
		zr = temp;

		//mB_log << "zi: " << zi << std::endl;
		//mB_log << "zr: " << zr << std::endl;

		i++;
		//mB_log << "do/while Control Equation: " << zr * zr - zi * zi << std::endl;
	} while (i < maxN && zr*zr - zi * zi < maxZ);

	return i;
}

void genFrac(int InitX, int FinalX, int InitY, int FinalY, int id, std::string Id)
{
	//std::ofstream log("log_"+Id+".txt");
	//log << "InitX: " << InitX << std::endl;
	//log << "FinalX: " << FinalX << std::endl;
	//log << "InitY: " << InitY << std::endl;
	//log << "FinalY: " << FinalY << std::endl;
	//log << "Thread id: " << id << std::endl;

	//std::ofstream Image("Multi_Thread_Dev_"+id+".ppm");
	//Image << "P3" << std::endl << width << " " << height << std::endl;
	Geni[id] = true;
	int y;
	int x;
	int _x = InitX;
	int _y = InitY;

	//log << "_x: " << _x << std::endl;
	//log << "_Fx: " << _Fx << std::endl;
	//log << "_y: " << _y << std::endl;
	//log << "_Fy: " << _Fy << std::endl;

	for (y = 0; y < (int)(ceil(height / 3) + 1); y++)
	{
		if (_y >= FinalY)
		{
			_y = InitY;
		}

		for (x = 0; x < width; x++)
		{
			if (_x >= FinalX)
			{
				_x = InitX;
			}

			double cr = mapTo(_x, width, maxR, minR);
			double ci = mapTo(_y, height, maxI, minI);
			//double cr = mapTo(x, width, maxR, minR);
			//double ci = mapTo(y, width, maxI, minI);

			//log << "cr mapTo results: " << cr << std::endl;
			//log << "ci mapTo results: " << ci << std::endl;

			int n = MandelBrot(zr, cr, zi, ci, maxN, z, maxZ);

			//log << "n MandelBrot results: " << n << std::endl;

			int red = (((n*(int)rMlt) % rDiv) + (int)PI);
			int green = (((n*(int)gMlt) % gDiv) + (int)PI);
			int blue = (((n*(int)bMlt) % bDiv) + (int)PI);

			//log << "red results: " << red << std::endl;
			//log << "green results: " << green << std::endl;
			//log << "blue results: " << blue << std::endl;

			std::stringstream r;
			r << red;
			std::stringstream g;
			g << green;
			std::stringstream b;
			b << blue;

			std::string R = r.str();
			std::string G = g.str();
			std::string B = b.str();


			std::string rgb = R + " " + G + " " + B + " ";

			//log << "rgb: " << rgb << std::endl;

			Thread_RGB[id][y][x] = rgb;

			//log << "Thread_RGB[" << id << "][" << y << "][" << x << "]: " << Thread_RGB[id][y][x] << std::endl;
			//Image << rgb;
			if (x != 0)
			{
				float Per1 = (float)((x + 1)*(y + 1)) / (float)(width*(ceil(height / 3) + 1));
				float Per2 = Per1 * (float)100.0;
				threadValueS[id] = Per2;
			}
			_x++;
		}
		_y++;
		//Image << std::endl;
	}
	//Image.close();
	Geni[id] = false;
	Done_Geni[id] = true;
	//log.close();
	std::this_thread::yield();
}

void coutProgress()
{
	while (Geni[0] && Geni[1] && Geni[2])
	{
		std::cout << "Thread 1: " << floor(threadValueS[0]) << "%  Thread 2: " << floor(threadValueS[1]) << "%  Thread 3: " << floor(threadValueS[2]) << "% \n";
	};

	while (Geni[0] && Geni[1] && !Geni[2])
	{
		std::cout << "Thread 1: " << floor(threadValueS[0]) << "%  Thread 2:" << floor(threadValueS[1]) << "% \n";
	};

	while (Geni[0] && !Geni[1] && Geni[2])
	{
		std::cout << "Thread 1: " << floor(threadValueS[0]) << "% Thread 3: " << floor(threadValueS[2]) << "% \n";
	};

	while (!Geni[0] && Geni[1] && Geni[2])
	{
		std::cout << "Thread 2: " << floor(threadValueS[0]) << "% Thread 3: " << floor(threadValueS[2]) << "% \n";
	};

	while (Geni[0] && !Geni[1] && !Geni[2])
	{
		std::cout << "Thread 1: " << floor(threadValueS[0]) << "% \n";
	};

	while (!Geni[0] && Geni[1] && !Geni[2])
	{
		std::cout << "Thread 2: " << floor(threadValueS[1]) << "% \n";
	};

	while (!Geni[0] && !Geni[1] && Geni[2])
	{
		std::cout << "Thread 3: " << floor(threadValueS[2]) << "% \n";
	};

	while (ImageMaking)
	{
		std::cout << "Image: " << floor(threadValueS[3]) << "% \n";
	};

	while (RTA_Allocating && TVA_Allocating)
	{
		std::cout << "RTA Thread: " << floor(threadValueS[4]) << "%  TVA Thread: " << floor(threadValueS[5]) << "% \n";
	}

	while (RTA_Allocating && !TVA_Allocating)
	{
		std::cout << "RTA Thread: " << floor(threadValueS[4]) << "% \n";
	};

	while (TVA_Allocating && !RTA_Allocating)
	{
		std::cout << "TVA Thread: " << floor(threadValueS[5]) << "% \n";
	}

	std::this_thread::yield();
}

void RTA_Init()
{
	RTA_Allocating = true;
	//std::ofstream MemAllocationLog("MAL_RTA.txt");
	Thread_RGB.resize(3);
	//MemAllocationLog << Thread_RGB.capacity() << std::endl;
	for (int td = 0; td < 3; ++td)
	{
		Thread_RGB[td].resize((int)ceil(height / 3) + 1);
		//MemAllocationLog << Thread_RGB[td].capacity() << std::endl;
		for (int ht = 0; ht < (int)(ceil(height / 3) + 1); ++ht)
		{
			Thread_RGB[td][ht].resize(width);
			//MemAllocationLog << Thread_RGB[td][ht].capacity() << std::endl;
			if (ht != 0)
			{
				float Per1 = (float)((ht + 1)*(td + 1)) / (float)((ceil(height / 3) + 1) * 3);
				float Per2 = Per1 * (float)100.0;
				threadValueS[4] = Per2;
			}
		}
	}
	RTA_Allocating = false;
	RTA_Empty = false;
	RTA_Done = true;
	//MemAllocationLog.close();
	std::this_thread::yield();
}

void RTA_Deallocate()
{
	RTA_Deallocating = true;
	for (int td = 0; td < Thread_RGB.capacity(); ++td)
	{
		for (int ht = 0; ht < Thread_RGB[td].capacity(); ++ht)
		{
			Thread_RGB[td][ht].resize(0);
		}
		Thread_RGB[td].resize(0);
	}
	Thread_RGB.resize(0);
	RTA_Deallocating = false;
	RTA_Empty = true;
	std::this_thread::yield();
}

void TVA_Init()
{
	TVA_Allocating = true;
	//std::ofstream MemAllocationLog("MAL_TVA.txt");
	threadValues.resize(3);
	//MemAllocationLog << threadValues.capacity() << std::endl;
	for (int td = 0; td < 3; ++td)
	{
		threadValues[td].resize(4);
		//MemAllocationLog << threadValues[td].capacity() << std::endl;
		if (td != 0)
		{
			float Per1 = (float)(td + 1) / 2.f;
			float Per2 = Per1 * (float)100.0;
			threadValueS[5] = Per2;
		}
	}
	TVA_Allocating = false;
	TVA_Empty = false;
	TVA_Done = true;
	//MemAllocationLog.close();
	std::this_thread::yield();
}

void TVA_Deallocate()
{
	TVA_Deallocating = true;
	for (int td = 0; td < threadValues.capacity(); ++td)
	{
		threadValues[td].resize(0);
	}
	threadValues.resize(0);
	TVA_Deallocating = false;
	TVA_Empty = true;
}

void InitMem()
{
	MemAllocating = true;
	//std::ofstream MemAllocationLog("MAL.txt");
	std::cout << "Allocating Memory.." << std::endl;

	threadValueS.resize(6);
	//MemAllocationLog << threadValueS.capacity() << std::endl;

	MATs.push_back(std::thread(RTA_Init));
	MATs.push_back(std::thread(TVA_Init));
	MATs.push_back(std::thread(coutProgress));

	for (auto& mt : MATs)
	{
		//if (MemAllocate)
		//{
		mt.join();
		//}
	}

	//MemAllocationLog.close();
	std::cout << "Memory Allocated" << std::endl;
	MemAllocating = false;
	MemAllocated = true;
}

void DeallocateMem()
{
	MemDeallocating = true;
	std::cout << "Deallocating Memory.." << std::endl;

	MDATs.push_back(std::thread(RTA_Deallocate));
	MDATs.push_back(std::thread(TVA_Deallocate));
	MDATs.push_back(std::thread(coutProgress));

	for (auto& mdt : MDATs)
	{
		mdt.join();
	}

	threadValueS.resize(0);

	std::cout << "Memory Deallocated" << std::endl;
	MemDeallocating = false;
	MemDeallocated = true;
}

void InitThreads()
{
	std::cout << "initializing Threads And Thread Information" << std::endl;

	if (MemAllocated)
	{
		threadValues[0][0] = 0;
		threadValues[0][1] = width;
		threadValues[0][2] = 0;
		threadValues[0][3] = (int)ceil(height / 3) + 1;

		threadValues[1][0] = 0;
		threadValues[1][1] = width;
		threadValues[1][2] = (int)ceil(height / 3) + 1;
		threadValues[1][3] = (int)ceil((height / 3) * 2) + 1;

		threadValues[2][0] = 0;
		threadValues[2][1] = width;
		threadValues[2][2] = (int)ceil((height / 3) * 2) + 1;
		threadValues[2][3] = height;

		threadValueS[0] = 0;					//Thread 1's Prog				0
		threadValueS[1] = 0;					//Thread 2's Prog				1
		threadValueS[2] = 0;					//Thread 3's Prog				2
		threadValueS[3] = 0;					//Image Building Prog			3
		threadValueS[4] = 0;					//RTA Prog						4
		threadValueS[5] = 0;					//TVA Prog						5
		threads.push_back(std::thread(genFrac, (int)threadValues[0][0], (int)threadValues[0][1], (int)threadValues[0][2], (int)threadValues[0][3], 0, "1"));
		threads.push_back(std::thread(genFrac, (int)threadValues[1][0], (int)threadValues[1][1], (int)threadValues[1][2], (int)threadValues[1][3], 1, "2"));
		threads.push_back(std::thread(genFrac, (int)threadValues[2][0], (int)threadValues[2][1], (int)threadValues[2][2], (int)threadValues[2][3], 2, "3"));
		threads.push_back(std::thread(coutProgress));

		std::cout << "Joining Threads.." << std::endl;

		for (auto& th : threads)
		{
			//if (MemAllocate)
			//{
			th.join();
			//}
		}
	}
}

void AssemableImage()
{
	ImageMaking = true;
	std::cout << "Making .ppm" << std::endl;
	std::ofstream Image("Multi_Thread_Dev.ppm");
	Image << "P3" << std::endl;
	Image << width << " " << height << std::endl;
	for (int td = 0; td < 3; td++)
	{
		for (int y = 0; y < (int)(ceil(height / 3) + 1); y++)
		{
			for (int x = 0; x < width; x++)
			{
				Image << Thread_RGB[td][y][x];

				if (x != 0)
				{
					float Per1 = (float)((x + 1)*(y + 1)) / (float)(width*(ceil(height / 3) + 1));
					float Per2 = Per1 * (float)100.0;
					threadValueS[3] = Per2;
				}
			}
			Image << std::endl;
		}
	}
	Image.close();
	ImageMaking = false;
	ImageAssembled = true;
	std::cout << ".ppm Finished" << std::endl;
}

int main()
{
	std::vector<std::thread> Img;

	InitMem();

	std::cout << "Press Any Key..." << std::endl;
	std::cin.ignore();

	if (MemAllocated)
	{
		InitThreads();
	}

	std::cout << "Press Any Key..." << std::endl;
	std::cin.ignore();

	if (Done_Geni[0] && Done_Geni[1] && Done_Geni[2])
	{
		Img.push_back(std::thread(AssemableImage));
		Img.push_back(std::thread(coutProgress));
		for (auto& I : Img)
		{
			I.join();
		}
	}

	if (ImageAssembled)
	{
		std::cout << "Finished!" << std::endl;
		std::cin.ignore();
		std::cout << "Shutting Down..." << std::endl;
		DeallocateMem();
		return 0;
	}
	else {
		return 1;
	}
}