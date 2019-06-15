namespace Castle {
	const double zr_[8] =	{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double zi_[8] =	{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double maxR_[8] = { 0.2, 0.18, 0.16, 0.14, 0.12, 0.1, 0.08, 0.07 };
	const double minR_[8] = { -0.2, -0.18, -0.16, -0.14, -0.12, -0.1, -0.08, -0.07 };
	const double maxI_[8] = { 0.14, 0.12, 0.1, 0.08, 0.06, 0.04, 0.03, 0.02 };
	const double minI_[8] = { -0.26, -0.24, -0.22, -0.2, -0.18, -0.16, -0.15, -0.14 };
	const int maxN_[8] =	{ 100, 100, 100, 100, 100, 100, 100, 100 };
	const float z_[8] =		{ 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0 };
	const float maxZ_[8] =	{ 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0 };
	int castle(double Zr, double Cr, double Zi, double Ci, int MaxN, float Z, float MaxZ) {
		int i = 0;
		double zr = Zr;
		double zi = Zi;
		do {
			double temp = (zr * zr + zi * zi + Ci)*PI;
			zi = (Z * (zr*zi) + Cr)*PI;
			zr = temp;
			i++;
		} while (i < MaxN && zr*zr - zi*zi < MaxZ);
		return i;
	}
}
