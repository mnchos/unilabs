#include <fstream>

#include <iostream>

#include <math.h>

#include <ctime>

using namespace std;

int findMandelbrot(double cr, double ci, int max_iterations) //производится поиск множества Мандельброта

{

	int i = 0;

	double zr = 0.0, zi = 0.0;

	while (i < max_iterations && zr * zr + zi * zi < 4.0)

	{

		double temp = zr * zr * zr - 3.0 * zr * zi * zi + zr * zr - zi * zi + 2.0 * zr + cr;

		zi = 3.0 * zr * zr * zi - zi * zi * zi  + 2.0 * zr * zi + 2.0 * zi +ci;

		zr = temp;

		i++;
	}

	return i;

}

double mapToReal(int x, int imageWidth, double minR, double maxR)//вещественная часть

{

	double range = maxR - minR;

	return x * (range / imageWidth) + minR;

}

double mapToImaginary(int y, int imageHeight, double minI, double maxI)//мнимая часть

{

	double range = maxI - minI;

	return y * (range / imageHeight) + minI;

}

int main()

{

	srand(time(0));

	ifstream fin("input.txt");//файл из которого берутся данные

	int imageWidth, imageHeight, maxN;

	double minR, maxR, minI, maxI;

	if (!fin)

	{

		cout << "Could not open file!" << endl;

		return 1;

	}

	fin >> imageWidth >> imageHeight >> maxN;

	fin >> minR >> maxR >> minI >> maxI;

	fin.close();

	ofstream fout("output_image.ppm");

	fout << "P3" << endl;

	fout << imageWidth << " " << imageHeight << endl;

	fout << "256" << endl; // Максимальнрое значение пикселей RGB

	unsigned int start_time = clock();

	for (double y = 0.0; y < imageHeight; y++)

	{

		for (double x = 0.0; x < imageWidth; x++)

		{

			double cr = mapToReal(x, imageWidth, minR, maxR);

			double ci = mapToImaginary(y, imageHeight, minI, maxI);

			int n = findMandelbrot(cr, ci, maxN);

			int r = (n % 256);

			int g = (n % 256);

			int b = (n % 256);

			fout << r << " " << g << " " << b << " ";

		}

		fout << endl;

	}

	fout.close();

	unsigned int end_time = clock();

	cout << "Time: " << (end_time - start_time) / 1000.0 << endl;

	return 0;

}