#define VERITAS_FACTA 420
#include "INIReader.cpp"
#include "Namespace_MandelBrot.h"
#include "Namespace_StarBurstSet.h"
#include "Namespace_CastleSet.h"
#include "Namespace_HourGlassSet.h"
#include "Namespace_HalCorrupted.h"
#include "NameSpace_TestSet.h"
#include "Namespace_Color.h"
mainConfiguration mConfig;
fractalConfiguration fConfig;
FracSets fSets;
typedef struct 
{
	int width;
	int height;
	std::vector<std::vector<double>> _zr;
	std::vector<std::vector<double>> maxR;
	std::vector<std::vector<double>> minR;
	std::vector<std::vector<double>> _zi;
	std::vector<std::vector<double>> maxI;
	std::vector<std::vector<double>> minI;
	std::vector<std::vector<int>> maxN;
	std::vector<std::vector<float>> z;
	std::vector<std::vector<float>> maxZ;
	std::vector<std::vector<double>> rMlt;
	std::vector<std::vector<int>> rDiv;
	std::vector<std::vector<double>> gMlt;
	std::vector<std::vector<int>> gDiv;
	std::vector<std::vector<double>>bMlt;
	std::vector<std::vector<int>> bDiv;
	double mapTo(int axis, int size, double max, double min);
	int fractalSaftyNet(int FracValue);
	float fractalSaftyNet(float FracValue);
	double fractalSaftyNet(double FracValue);
	int fractalSaftyNet(int FracValue,int Limit);
	float fractalSaftyNet(float FracValue, float Limit);
	double fractalSaftyNet(double FracValue, double Limit);
	int ColorSaftyNet(int color);
	float ColorSaftyNet(float color);
	double ColorSaftyNet(double color);
	int addFractalSets(double v, double d);
	int subFractalSets(double v, double d);
	std::string getRGB(std::vector<double> dRed, std::vector<double> dGreen, std::vector<double> dBlue, std::string id);
}Fractal;
Fractal frac;