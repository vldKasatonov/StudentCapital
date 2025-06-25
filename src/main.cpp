#include <iostream>
#include <vector>

double maximiseCapital(double capital, int maxCount, int countOfLaptops,
					   std::vector<double> prices, std::vector<double> gains) {
	for (int i = 0; i < maxCount; i++) {
		double maxGain = -1;
		int indexOfMaxGain = -1;
		for (int j = 0; j < countOfLaptops; j++) {
			if (capital >= prices[j] && gains[j] > maxGain) {
				maxGain = gains[j];
				indexOfMaxGain = j;
			}
		}
		if (indexOfMaxGain != -1) {
			capital += gains[indexOfMaxGain];
			gains[indexOfMaxGain] = -1;
		}
	}
	return capital;
}

int main() {
	double C = 230;
	int N = 5;
	int K = 8;
	std::vector<double> prices = { 120, 220, 300, 180, 450, 270, 380, 120 };
	std::vector<double> gains = { 50, 40, 110, 60, 100, 80, 70, 40 };
	std::cout << maximiseCapital(C, N, K, prices, gains);
	return 0;
}
