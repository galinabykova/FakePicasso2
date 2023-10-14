#include "../FakePicasso/PicassoLWD.FastSimulation.Native.h"
#include <iostream>
#include <math.h>

int main()
{
	double x[] = { 0 };
	const int size_indata = 1024;
	double tvd[size_indata]; std::fill_n(tvd, size_indata, 3);
	double zeni[size_indata]; std::fill_n(zeni, size_indata, 90);
	double phases[size_indata * 2]; std::fill_n(phases, 2 * size_indata, 1);
	double ampl[size_indata * 2]; std::fill_n(ampl, 2 * size_indata, 0.85);
	double md[size_indata];
	for (int i = 0; i < size_indata; i++) md[i] = i * 0.1;
	double tvdstart = 0;
	double alpha = 0;
	double rof = 0;
	double rosf = 0;
	double kf = 0;
	double ksf = 0;
	double synt_phases[2 * size_indata];
	double synt_ampl[2 * size_indata];
	double misfit;
	uint32_t num_probe[] = { LWD_LOOCH_VIKPB_ROL, LWD_LOOCH_VIKPB_ROH };

	auto errocode = StartModelSimpleHorizontalModel6Param1_5D_ByRo(2, num_probe, size_indata, md, tvd, x, zeni, phases, ampl,
		tvdstart, NAN, NAN,
		alpha, 0, 10,
		rof, 0.1, 10000,
		kf, 1, 10,
		rosf, 7, 10000,
		ksf, 1, 10,
		synt_phases, synt_ampl,
		misfit);
	std::cout << errocode;
	return 0;
}
