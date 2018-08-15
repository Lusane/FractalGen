//std::ofstream HourGlassSetLog("Namespace_HourGlassSet.hLog.txt");

namespace HourGlass {
	//						  0,   1,   2,   3,   4,   5,   6,   7
	const double zr_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double zi_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

	const double maxR_[8] = { 1.8, 1.6, 1.4, 1.2, 1.0, 0.8, 0.6, 0.4 };
	const double minR_[8] = { -1.8, -1.6, -1.4, -1.2, -1.0, -0.8, -0.6, -0.4 };

	const double maxI_[8] = { 1.8, 1.6, 1.4, 1.2, 1.0, 0.8, 0.6, 0.4 };
	const double minI_[8] = { -1.8, -1.6, -1.4, -1.2, -1.0, -0.8, -0.6, -0.4 };

	const int maxN_[8] = { 100, 100, 100, 100, 100, 100, 100, 100 };

	const float z_[8] = { 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0 };

	const float maxZ_[8] = { 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0 };

	int hourGlass(double Zr, double cr, double Zi, double ci, int MaxN, float z, float MaxZ) {
		int i = 0;
		double zr = Zr;
		double zi = Zi;

		do {
			double zr_1 = z * (cr*ci) + zr;
			double zi_1 = (cr*cr) - (ci*ci) + zi;

			double temp = (zr*zr) - (zi*zi) - zr_1;

			zi = z * (zr*zi) - zi_1;
			zr = temp;

			i++;
		} while (i < MaxN && zr*zr - zi * zi < MaxZ);

		return i;
	}
}