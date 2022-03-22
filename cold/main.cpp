// this should be a demonstration of periodic, non lethal desease such as the cold.
#include <iostream>
#include <vector>
#include <fstream>


int main(int argc, char* argv[]) {
	double alpha;	// interaction rate
	double gamma;	// recovery rate

	std::cin >> alpha >> gamma;

	double nstep{ 1000 };
	double h{ 0.25 };

	double susceptible{ 0.9 };
	double infectous{ 0.1 };

	std::vector<double> susceptibles{ susceptible };
	std::vector<double> infectouses{ infectous };


	for (unsigned int i{}; i != nstep; i++) {
		infectouses.push_back(- alpha * h * infectouses.at(i) * infectouses.at(i) +
			(double{ 1 } + h * ((alpha - gamma) * infectouses.at(i))));
		susceptibles.push_back(double{1} - infectouses.at(i + 1U);
		
	}

	std::fstream cold{ "cold.dat", std::ios_base::out };
	cold << "t" << '\t' << "s" << '\t' << "i" << std::endl;

	for (unsigned int i{}; i != susceptibles.size(); i++) {
		cold << i * h << '\t' << susceptibles.at(i) << '\t' << infectouses.at(i) << std::endl;
	}
	return 0;
}