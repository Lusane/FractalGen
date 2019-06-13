#include "Fractal.h"
double Fractal::mapTo(int axis, int size, double max, double min) 
{
	double range = max - min;
	return axis * (range / size) + min;
}
int Fractal::fractalSaftyNet(int FracValue) 
{
	if (FracValue == 0) 
	{
		return 1;
	}
	return FracValue;
}
float Fractal::fractalSaftyNet(float FracValue) 
{
	if (FracValue == 0) 
	{
		return 1;
	}
	return FracValue;
}
double Fractal::fractalSaftyNet(double FracValue) 
{
	if (FracValue == 0) 
	{
		return 1;
	}
	return FracValue;
}
int Fractal::fractalSaftyNet(int FracValue,int Limit) 
{
	if (FracValue >= Limit) 
	{
		return Limit;
	}
	else if (FracValue == 0) 
	{
		return 1;
	}
	return FracValue;
}
float Fractal::fractalSaftyNet(float FracValue, float Limit) 
{
	if (FracValue >= Limit) 
	{
		return Limit;
	}
	else if (FracValue == 0) 
	{
		return 1;
	}
	return FracValue;
}
double Fractal::fractalSaftyNet(double FracValue, double Limit) 
{
	if (FracValue >= Limit) 
	{
		return Limit;
	}
	else if (FracValue == 0) 
	{
		return 1;
	}
	return FracValue;
}
int Fractal::ColorSaftyNet(int color) 
{
	if (color == 0) 
	{
		return 1;
	}
	else if(color < 0) 
	{
		return color *= (-1);
	}
	else if (color >= (255*fConfig.colorBitMulti)) {
		color -= (255*fConfig.colorBitMulti);
		return ColorSaftyNet(color);
	}
	return color;
}
float Fractal::ColorSaftyNet(float color) 
{
	if (color == 0.f) 
	{
		return 1.f;
	}
	else if (color < 0.f) 
	{
		return color *= (-1.f);
	}
	else if (color >= (255.f*fConfig.colorBitMulti)) {
		color -= (255.f*fConfig.colorBitMulti);
		return ColorSaftyNet(color);
	}
	return color;
}
double Fractal::ColorSaftyNet(double color) 
{
	if (color == 0.0) 
	{
		return 1.0;
	}
	else if (color < 0.0) 
	{
		return color *= (-1.0);
	}
	else if (color >= (255.0*fConfig.colorBitMulti)) {
		color -= (255.0*fConfig.colorBitMulti);
		return ColorSaftyNet(color);
	}
	return color;
}
int Fractal::addFractalSets(double v, double d) 
{
	return ColorSaftyNet((int)(v + d));
}
int Fractal::subFractalSets(double v, double d) 
{
	return ColorSaftyNet((int)(v - d));
}
std::string Fractal::getRGB(std::vector<double> dRed, std::vector<double> dGreen, std::vector<double> dBlue, std::string id)
{
	int red = 1;
	int green = 1;
	int blue = 1;
	for (int st = 0; st < fConfig.setCount; st++)
	{
		if (fConfig.Inverted)
		{
			red = ColorSaftyNet((int)(subFractalSets((((double)addFractalSets((double)red, dRed[st]) / fConfig.setCount) + (int)PI), dRed[fConfig.setCount - st]) * threadCount));
			green = ColorSaftyNet((int)(subFractalSets((((double)addFractalSets((double)green, dGreen[st]) / fConfig.setCount) + (int)PI), dGreen[fConfig.setCount - st]) * threadCount));
			blue = ColorSaftyNet((int)(subFractalSets((((double)addFractalSets((double)blue, dBlue[st]) / fConfig.setCount) + (int)PI), dBlue[fConfig.setCount - st]) * threadCount));
		}
		else if (!fConfig.Inverted)
		{
			red = ColorSaftyNet((int)(addFractalSets((((double)subFractalSets((double)red, dRed[st]) / fConfig.setCount) + (int)PI), dRed[fConfig.setCount - st]) * threadCount));
			green = ColorSaftyNet((int)(addFractalSets((((double)subFractalSets((double)green, dGreen[st]) / fConfig.setCount) + (int)PI), dGreen[fConfig.setCount - st]) * threadCount));
			blue = ColorSaftyNet((int)(addFractalSets((((double)subFractalSets((double)blue, dBlue[st]) / fConfig.setCount) + (int)PI), dBlue[fConfig.setCount - st]) * threadCount));
		}
		if (fConfig.Intensify) {
			red = ColorSaftyNet((int)floor(red * (int)fConfig.Intensity));
			green = ColorSaftyNet((int)floor(green * (int)fConfig.Intensity));
			blue = ColorSaftyNet((int)floor(blue * (int)fConfig.Intensity));
		}
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