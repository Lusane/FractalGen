#define VERITAS_FACTA 420
#include "INIReader.h"
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

typedef struct {
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

	double mapTo(int axis, int size, double max, double min) {
		double range = max - min;

		return axis * (range / size) + min;
	};

	int fractalSaftyNet(int FracValue) {
		int Limit = 999999999;
		if (FracValue >= Limit) {
			return Limit;
		}
		else if (FracValue == 0) {
			return 1;
		}
		return FracValue;
	}

	float fractalSaftyNet(float FracValue) {
		float Limit = 999999999.f;
		if (FracValue >= Limit) {
			return Limit;
		}
		else if (FracValue == 0) {
			return 1;
		}
		return FracValue;
	}

	double fractalSaftyNet(double FracValue) {
		double Limit = 999999999.9;
		if (FracValue >= Limit) {
			return Limit;
		}
		else if (FracValue == 0) {
			return 1;
		}
		return FracValue;
	}

	int fractalSaftyNet(int FracValue,int Limit) {
		if (FracValue >= Limit) {
			return Limit;
		}
		else if (FracValue == 0) {
			return 1;
		}
		return FracValue;
	}

	float fractalSaftyNet(float FracValue, float Limit) {
		if (FracValue >= Limit) {
			return Limit;
		}
		else if (FracValue == 0) {
			return 1;
		}
		return FracValue;
	}

	double fractalSaftyNet(double FracValue, double Limit) {
		if (FracValue >= Limit) {
			return Limit;
		}
		else if (FracValue == 0) {
			return 1;
		}
		return FracValue;
	}

	int ColorSaftyNet(int color) {
		if (color == 0) {
			return 1;
		}
		else if(color < 0) {
			return color *= (-1);
		}
		return color;
	}

	float ColorSaftyNet(float color) {
		if (color == 0.f) {
			return 1.f;
		}
		else if (color < 0.f) {
			return color *= (-1);
		}
		return color;
	}

	double ColorSaftyNet(double color) {
		if (color == 0.0) {
			return 1.0;
		}
		else if (color < 0.0) {
			return color *= (-1);
		}
		return color;
	}

	int addFractalSets(double v, double d) {
		return ColorSaftyNet((int)(v + d));
	}

	int subFractalSets(double v, double d) {
		return ColorSaftyNet((int)(v - d));
	}

	std::string getRGB(double *dRed, double *dGreen, double *dBlue, std::string id) {
		int red = 1;
		int green = 1;
		int blue = 1;

		if (fConfig.Inverted) {

			for (int rn = 0; rn < fConfig.setCount; rn++) {
				red = ColorSaftyNet((int)(subFractalSets((((double)addFractalSets((double)red, dRed[rn]) / fConfig.setCount) + (int)PI), dRed[fConfig.setCount-rn]) * mConfig.ThreadCount));
				green = ColorSaftyNet((int)(subFractalSets((((double)addFractalSets((double)green, dGreen[rn]) / fConfig.setCount) + (int)PI), dGreen[fConfig.setCount-rn]) * mConfig.ThreadCount));
				blue = ColorSaftyNet((int)(subFractalSets((((double)addFractalSets((double)blue, dBlue[rn]) / fConfig.setCount) + (int)PI), dBlue[fConfig.setCount-rn]) * mConfig.ThreadCount));
			}
		}
		else if(!fConfig.Inverted) {

			for (int rn = 0; rn < fConfig.setCount; rn++) {
				red = ColorSaftyNet((int)(addFractalSets((((double)subFractalSets((double)red, dRed[rn]) / fConfig.setCount) + (int)PI), dRed[fConfig.setCount-rn]) * mConfig.ThreadCount));
				green = ColorSaftyNet((int)(addFractalSets((((double)subFractalSets((double)green, dGreen[rn]) / fConfig.setCount) + (int)PI), dGreen[fConfig.setCount-rn]) * mConfig.ThreadCount));
				blue = ColorSaftyNet((int)(addFractalSets((((double)subFractalSets((double)blue, dBlue[rn]) / fConfig.setCount) + (int)PI), dBlue[fConfig.setCount-rn]) * mConfig.ThreadCount));
			}
		}
		
		if (fConfig.Intensify) {
			red = (int)floor(red * (int)fConfig.Intensity);
			green = (int)floor(green * (int)fConfig.Intensity);
			blue = (int)floor(blue * (int)fConfig.Intensity);
		}

		red = ColorSaftyNet(red);
		green = ColorSaftyNet(green);
		blue = ColorSaftyNet(blue);

		std::stringstream r;
		r << red;
		std::stringstream g;
		g << green;
		std::stringstream b;
		b << blue;

		std::string rgb = r.str() + " " + g.str() + " " + b.str() + " ";

		return rgb;
	}
}Fractal;

Fractal frac;