#include <iostream>
#include <iomanip>
#include <random>

using namespace std;


int main()
{

const int processes = 1000;
double total_arrival = 0;
double total_service = 0;

std::default_random_engine generator1;
std::poisson_distribution<int> distribution1(2);
std::default_random_engine generator2;
std::exponential_distribution<double> distribution2(1);


for(int i = 1; i <= processes; i++)
	{
		int arrival_time = distribution1(generator1);
		double service_time = distribution2(generator2);

		cout << "Process #" << i
		<< ", arrival time: " << i + service_time + arrival_time 
		<< ", requested service time: " << fixed << showpoint << setprecision(2) << service_time
		<<"s" << endl;
		
		total_arrival = total_arrival + arrival_time;
		total_service = total_service + service_time;

	}

	double avg_arrival = total_arrival / processes;
	double avg_service = total_service / processes;
	cout << "\nAverage arrival time : " << avg_arrival << endl;
	cout << "\nAverage service time : " << avg_service << endl;

}

