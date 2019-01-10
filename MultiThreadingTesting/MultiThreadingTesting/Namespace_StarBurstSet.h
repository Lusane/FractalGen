namespace StarBurst {
	const double zr_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double zi_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double maxR_[8] = { 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.09, 0.08 };
	const double minR_[8] = { -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, -0.09, -0.08 };
	const double maxI_[8] = { 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.09, 0.08 };
	const double minI_[8] = { -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, -0.09, -0.08 };
	const int maxN_[8] = { 100, 100, 100, 100, 100, 100, 100, 100 };
	const float z_[8] = { 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0 };
	const float maxZ_[8] = { 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0 };
	int starBurst(double Zr, double cr, double Zi, double ci, int MaxN, float Z, float MaxZ) {
		int i = 0;
		double zr = Zr;
		double zi = Zi;
		do {
			double zr_1 = Z * (cr*ci) + zr;
			double zi_1 = (cr*cr) - (ci*ci) +  zi;
			double temp = ((zr*zr) - (zi*zi) - zr_1) * PI;
			zi = (Z * (zr*zi) - zi_1) * PI;
			zr = temp;
			i++;
		} while (i < MaxN && zr*zr-zi*zi < MaxZ);
		return i;
	}
}