#include <iostream>
#include <vector>

void printRepairDetails(int id, double price, double gain, double capital) {
	std::cout << "Bought a laptop (id " << id << ") for $";
	std::cout << price << " and got $" << gain;
	std::cout << " gain. Current capital = " << capital << ".\n";
}

double maximiseCapital(double capital, int maxCount, int countOfLaptops,
					   std::vector<double> prices, std::vector<double> gains) {
	for (int i = 0; i < maxCount; i++) {
		double maxGain = 0;
		int indexOfMaxGain = -1;
		for (int j = 0; j < countOfLaptops; j++) {
			if (capital >= prices[j] && gains[j] > maxGain) {
				maxGain = gains[j];
				indexOfMaxGain = j;
			}
		}
		if (indexOfMaxGain != -1) {
			capital += gains[indexOfMaxGain];
			printRepairDetails(indexOfMaxGain, prices[indexOfMaxGain],
							  gains[indexOfMaxGain], capital);
			gains[indexOfMaxGain] = 0;
		} else {
			break;
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

	std::cout << "Do you want to use default values for testing? [y/n]:\n";
	char choice;
	std::cin >> choice;
	if (choice != 'y' && choice != 'Y') {
		std::cout << "Enter student's capital:\n";
		if (!(std::cin >> C)) {
			std::cout << "Input error.";
			return 1;
		}
		std::cout << "Enter the number of laptops that the student is able to repair:\n";
		if (!(std::cin >> N)) {
			std::cout << "Input error.";
			return 1;
		}
		std::cout << "Enter the number of laptops available for purchase:\n";
		if (!(std::cin >> K)) {
			std::cout << "Input error.";
			return 1;
		}
		std::cout << "Enter prices of " << K << " laptops:\n";
		for (int i = 0; i < K; i++) {
			if (!(std::cin >> prices[i])) {
				std::cout << "Input error.";
				return 1;
			}
		}
		std::cout << "Enter gains of laptops:\n";
		for (int i = 0; i < K; i++) {
			if (!(std::cin >> gains[i])) {
				std::cout << "Input error.";
				return 1;
			}
		}
	}

	if (C < 0) {
		std::cout << "C must be positive.";
		return 2;
	}
	if (N < 0) {
		std::cout << "N must be positive.";
		return 2;
	}
	if (K < 0) {
		std::cout << "K must be positive.";
		return 2;
	}
	for (int i = 0; i < K; i++) {
		if (prices[i] < 0) {
			std::cout << "Prices must be positive.";
			return 2;
		}
		if (gains[i] < 0) {
			std::cout << "Gains must be positive.";
			return 2;
		}
	}

	std::cout << "Input data:\n";
	std::cout << "Capital = " << C << ", N = " << N << ", K = " << K << "\n";
	std::cout << "Prices:\n";
	for (int i = 0; i < K; i++) {
		std::cout << prices[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Gains:\n";
	for (int i = 0; i < K; i++) {
		std::cout << gains[i] << " ";
	}
	std::cout << "\n";

	double maxCapital = maximiseCapital(C, N, K, prices, gains);
	std::cout << "Total capital at the end of the summer = " << maxCapital;

	return 0;
}
