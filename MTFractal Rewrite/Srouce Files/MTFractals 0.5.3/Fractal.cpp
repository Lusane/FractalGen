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
		return Fractal::ColorSaftyNet(color);
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
		return Fractal::ColorSaftyNet(color);
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
		return Fractal::ColorSaftyNet(color);
	}
	return color;
}
int Fractal::addFractalSets(double v, double d) 
{
	return Fractal::ColorSaftyNet((int)(v + d));
}
int Fractal::subFractalSets(double v, double d) 
{
	return Fractal::ColorSaftyNet((int)(v - d));
}
std::string Fractal::getRGB(std::vector<double> dRed, std::vector<double> dGreen, std::vector<double> dBlue, std::string id)
{
	#if __DBG && __COLOR && __LOG
	std::ofstream getRGBLog;
	getRGBLog.open("getRGB.log.txt");
	#endif
	int red = 1;
	int green = 1;
	int blue = 1;
	for (int st = 0; st < fConfig.setCount; st++)
	{
		if (fConfig.Inverted)
		{
			red = Fractal::ColorSaftyNet((int)(Fractal::subFractalSets((((double)Fractal::addFractalSets((double)red, dRed[st]) / fConfig.setCount) + (int)PI), dRed[fConfig.setCount - st]) * threadCount));
			green = Fractal::ColorSaftyNet((int)(Fractal::subFractalSets((((double)Fractal::addFractalSets((double)green, dGreen[st]) / fConfig.setCount) + (int)PI), dGreen[fConfig.setCount - st]) * threadCount));
			blue = Fractal::ColorSaftyNet((int)(Fractal::subFractalSets((((double)Fractal::addFractalSets((double)blue, dBlue[st]) / fConfig.setCount) + (int)PI), dBlue[fConfig.setCount - st]) * threadCount));
		}
		else if (!fConfig.Inverted)
		{
			red = Fractal::ColorSaftyNet((int)(Fractal::addFractalSets((((double)Fractal::subFractalSets((double)red, dRed[st]) / fConfig.setCount) + (int)PI), dRed[fConfig.setCount - st]) * threadCount));
			green = Fractal::ColorSaftyNet((int)(Fractal::addFractalSets((((double)Fractal::subFractalSets((double)green, dGreen[st]) / fConfig.setCount) + (int)PI), dGreen[fConfig.setCount - st]) * threadCount));
			blue = Fractal::ColorSaftyNet((int)(Fractal::addFractalSets((((double)Fractal::subFractalSets((double)blue, dBlue[st]) / fConfig.setCount) + (int)PI), dBlue[fConfig.setCount - st]) * threadCount));
		}
		if (fConfig.Intensify) {
			red = Fractal::ColorSaftyNet((int)floor(red * (int)fConfig.Intensity));
			green = Fractal::ColorSaftyNet((int)floor(green * (int)fConfig.Intensity));
			blue = Fractal::ColorSaftyNet((int)floor(blue * (int)fConfig.Intensity));
		}
		#if __DBG && __COLOR && __LOG
		std::stringstream _rtmp_;
		_rtmp_ << red;
		std::stringstream _gtmp_;
		_gtmp_ << green;
		std::stringstream _btmp_;
		_btmp_ << blue;
		std::string Red = _rtmp_.str();
		std::string Green = _gtmp_.str();
		std::string Blue = _btmp_.str();
		const char *_red = Red.c_str();
		const char *_green = Green.c_str();
		const char *_blue = Blue.c_str();\
		const char *r_Name = "red";
		const char *g_Name = "green";
		const char *b_Name = "blue";
		log2txt(getRGBLog,r_Name,_red);
		log2txt(getRGBLog,g_Name,_green);
		log2txt(getRGBLog,b_Name,_blue);
		#endif
	}
	red = Fractal::ColorSaftyNet(red);
	green = Fractal::ColorSaftyNet(green);
	blue = Fractal::ColorSaftyNet(blue);
	std::stringstream r;
	r << red;
	std::stringstream g;
	g << green;
	std::stringstream b;
	b << blue;
	std::string R=r.str();
	std::string G=g.str();
	std::string B=b.str();
	#if __DBG && __COLOR && __LOG
	const char *_r = R.c_str();
	const char *_g = G.c_str();
	const char *_b = R.c_str();
	const char *r_Name = "red";
	const char *g_Name = "green";
	const char *b_Name = "blue";
	log2txt(getRGBLog,r_Name,_r);
	log2txt(getRGBLog,g_Name,_g);
	log2txt(getRGBLog,b_Name,_b);
	#endif
	std::string rgb = r.str() + " " + g.str() + " " + b.str() + " ";
	#if __DBG && __COLOR && __LOG
	const char *RGB = rgb.c_str();
	const char *RGB_Name = "rgb";
	log2txt(getRGBLog,RGB_Name,RGB);
	getRGBLog.close();
	#endif
	return rgb;
}