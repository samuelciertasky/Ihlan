#define _USE_MATH_DEFINES
#include <fstream>
#include <math.h>

using namespace std;

int main() {

	int numP = 10;
	float height = 10;
	float radius = 2;

	ofstream file;

	file.open("ihlan10.vtk", ios::out);

	file << "# vtk DataFile Version 2.0" << endl;
	file << "vtk output" << endl;
	file << "ASCII" << endl;
	file << "DATASET POLYDATA" << endl;
	file << "POINTS " << numP+1 <<  " float" << endl;
	for (int i = 0; i < numP; i++) {
		file << 2 * cos(i * (2 * M_PI)/numP) << " " << 2 * sin(i * (2 * M_PI) / numP) << " 0" << endl;
	}
	file << "0 0 " << height << endl;
	file << endl;
	file << "LINES " << numP * 2 << endl;
	for (int i = 0; i < numP; i++) {
		if (i == numP - 1) {
			file << "2 " << i << " " << 0 << endl;
		}
		else {
			file << "2 " << i << " " << i + 1 << endl;
		}
	}
	for (int i = 0; i < numP; i++) {
		file << "2 " << i  << " " << numP << endl;
	}
	file << endl;
	file << "POLYGONS " << numP + 1 << " " << numP * 4 + numP + 1 << endl;
	for (int i = 0; i < numP; i++) {
		if (i == numP - 1) {
			file << "3 " << i << " " << 0 << " 10" << endl;
		}
		else {
			file << "3 " << i << " " << i + 1 << " 10" << endl;
		}
	}
	file << numP;
	for (int i = 0; i < numP; i++) {
		file << " " << i;
	}
	file << endl << endl;
	file << "CELL_DATA " << numP + 1 << endl;
	file << "SCALARS cell_scalars int 1" << endl;
	file << "LOOKUP_TABLE default" << endl;
	for (int i = 0; i < numP + 1; i++) {
		file << i << endl;
	}
	file << "NORMALS cell_normals float" << endl;
	int m = 1;
	file << "0 0 " << m << endl;
	file << "0 0 " << -m << endl;
	file << "0 " << m << " 0" << endl;
	file << "0 " << -m << " 0" << endl;
	file << m << " 0" << " 0" << endl;
	file << -m << " 0" << " 0" << endl;
	file << endl ;

	file << "POINT_DATA " << numP + 1 << endl;
	file << "SCALARS sample_scalars float 1" << endl;
	file << "LOOKUP_TABLE my_table" << endl;
	for (int i = 0; i < numP + 1; i++) {
		file << i << ".0" << endl;
	}
	file << "LOOKUP_TABLE my_table " << numP + 1 << endl;
	for (int i = 0; i < numP + 1; i++) {
		file << "0.0 1.0 0.0 1.0" << endl;
	}
	file.close();

	return 0;
}