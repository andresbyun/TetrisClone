#include <BoolMat.hpp>

BoolMat::BoolMat(int x, int y) : width(x), height(y) {
	data.resize(y);

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			data[i].push_back(false);
		}
	}
}

BoolMat::BoolMat(int x, int y, bool in[]) : width(x), height(y) {
	data.resize(y);

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			data[i].push_back(in[i + (j * x)]);
		}
	}
}
