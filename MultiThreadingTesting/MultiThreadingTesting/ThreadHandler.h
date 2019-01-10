#define VERITAS_FACTA 420
#include "MemDeallocation.h"
void fractalThreadCreation() 
{
	int toAdd = (int)ceil(frac.height / threadCount) + 1;
	int startingY = 0;
	int finishY = toAdd;
	for (int tp = 0; tp < threadCount; tp++)
	{
		threadValues[tp][0] = 0;
		threadValues[tp][1] = frac.width;
		threadValues[tp][2] = startingY;
		threadValues[tp][3] = finishY;
		startingY += toAdd;
		finishY += toAdd;
		threadProgs[tp][0] = 0;
		threadProgs[tp][1] = 0;
	}
	for (int tds = 0; tds < threadCount; tds++)
	{
		threads.push_back(std::thread(genFrac, (int)threadValues[tds][0], (int)threadValues[tds][1], (int)threadValues[tds][2], (int)threadValues[tds][3], tds));
	}
}
void fractalThreadDestruction() 
{
	for (auto& th : threads)
	{
		th.~thread();
	}
	threads.clear();
	threads.resize(0);
}
void joinFractalThreads() 
{
	for (auto& th : threads)
	{
		th.join();
	}
}
void InitThreads() 
{
	Sleep(10);
	std::cout << "initializing Threads And Thread Information" << std::endl;
	fractalThreadCreation();
	Sleep(55);
	std::cout << "Generating Fractal.." << std::endl;
	joinFractalThreads();
	Sleep(55);
	fractalThreadDestruction();
	Sleep(10);
}
void initImageThread() 
{
	std::vector<std::thread> Img;
	Img.push_back(std::thread(AssemableImage));
	for (auto& I : Img) 
	{
		I.join();
	}
}