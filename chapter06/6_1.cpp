#include "test.h"
#include "Timer.hpp"
#include <chrono>
#include <iomanip>
#include <thread>
void time_duration()
{
	chrono::milliseconds t1(3);
	chrono::microseconds t2 = 2 * t1;
	chrono::duration<double, ratio<1, 30>> hz30(3.5);
	cout << "3ms duration has " << t1.count() << " ticks\n"//3
		<< "us duration has " << t2.count() << " ticks\n";//6000

	chrono::microseconds t3 = t1 - t2;
	cout << t3.count() << " us" << endl;//-3000
	cout << chrono::duration_cast<chrono::milliseconds>(t3).count() << endl;//-3

	chrono::duration<double, ratio<9, 7>> d1(3);
	chrono::duration<double, ratio<6, 5>> d2(1);
	auto d3 = d1 - d2;
	cout << typeid(d3).name() << " " << d3.count() << endl;//31
}

void time_point()
{
	using namespace std::chrono;
	typedef duration<int, ratio<3600 * 24>> days_type;
	chrono::time_point<system_clock, days_type> today =
		time_point_cast<days_type>(system_clock::now());
	cout << today.time_since_epoch().count() << " days since epoch" << endl;

	system_clock::time_point t1 = system_clock::now();
	time_t last = system_clock::to_time_t(t1 - hours(24));
	time_t next = system_clock::to_time_t(t1 + hours(24));
	cout << "one day ago,the time was " << put_time(localtime(&last), "%F %T") << '\n';
	cout << "next day,the time is " << put_time(localtime(&next), "%Y_%m_%d %H.%M.%S") << '\n';

	system_clock::time_point t2 = system_clock::now();
	cout << (t2 - t1).count() << " " << duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;
}

void time_count()
{
	Timer t;
	time_point();
	cout << t.elapsed_nano() << endl;
	cout << t.elapsed_micro() << endl;
}

void test6_1()
{
	time_duration();
	//time_count();
}