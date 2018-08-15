//std::ofstream TestLog("Namespace_TestSet.hLog.txt");

namespace TestSet {
	//						  0,   1,   2,   3,   4,   5,   6,   7,
	const double zr_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double zi_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

	const double maxR_[8] = { 1.6, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0, 0.9 };
	const double minR_[8] = { -1.6, -1.5, -1.4, -1.3, -1.2, -1.1, -1.0, -0.9 };

	const double maxI_[8] = { 1.6, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0, 0.9 };
	const double minI_[8] = { -1.6, -1.5, -1.4, -1.3, -1.2, -1.1, -1.0, -0.9 };

	const int maxN_[8] = { 25, 25, 25, 25, 25, 25, 25, 25 };

	const float z_[8] = { 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 };

	const float maxZ_[8] = { 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0 };

	int TestSet(double Zr, double Cr, double Zi, double Ci, int MaxN, float Z, float MaxZ) {
		int i = 0;
		double zr = Zr;
		double zi = Zi;

		do {
			double temp = zr * zr - zi * zi + Cr;

			zi = Z * (zr*zi) + Ci;
			zr = temp;

			i++;
		} while (i < MaxN && zr * zr - zi * zi < MaxZ);

		return i;
	}
}