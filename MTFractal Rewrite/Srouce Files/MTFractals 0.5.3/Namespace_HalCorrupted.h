namespace HalCorrupted {
	const double zr_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double zi_[8] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	const double maxR_[8] = { 6.6, 6.4, 6.2, 6.0, 5.8, 5.6, 5.4, 5.2 };
	const double minR_[8] = { -6.6, -6.4, -6.2, -6.0, -5.8, -5.6, -5.4, -5.2 };
	const double maxI_[8] = { 6.6, 6.4, 6.2, 6.0, 5.8, 5.6, 5.4, 5.2 };
	const double minI_[8] = { -6.6, -6.4, -6.2, -6.0, -5.8, -5.6, -5.4, 5.2 };
	const int maxN_[8] = { 25, 25, 25, 25, 25, 25, 25, 25 };
	const float z_[8] = { 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0 };
	const float maxZ_[8] = { 331.0, 331.0, 331.0, 331.0, 331.0, 331.0, 331.0, 331.0 };
	int halCorrupted(double Zr, double Cr, double Zi, double Ci, int MaxN, float Z, float MaxZ) {
		int i = 0;
		double zr = Zr;
		double zi = Zi;
		do {
			double temp = (zr*zr) + (int)(zi*zi) % (int)(Z*PI);
			zi = (Cr*Cr) + (int)(Ci*Ci) % (int)(Z*PI);
			zr = temp;
			i++;
		} while (i < MaxN && zr*zr-zi*zi < MaxZ);
		return i;
	}
}