#ifndef __BOOL_MAT__
#define __BOOL_MAT__

#include <vector>

using std::vector;

class BoolMat {

public:
	int height, width;

	BoolMat(int x, int y);
	BoolMat(int x, int y, bool in[]);
	void operator=(BoolMat b) {
		if (this->width == b.width && this->height == b.height) {
			for (int i = 0; i < this->height; i++) {
				this->data[i] = b[i];
			}
		}
	}

	vector<bool> operator[](int i) {
		return this->data[i];
	}

private:
	vector<vector<bool>> data;
};


#endif
