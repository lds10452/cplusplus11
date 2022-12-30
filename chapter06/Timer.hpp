#pragma once
#include "test.h"
#include <chrono>
class Timer
{
	chrono::time_point<chrono::high_resolution_clock> m_begin;
	template<typename Duration=chrono::milliseconds>
	int64_t elapsed()const
	{
		return chrono::duration_cast<Duration>(chrono::high_resolution_clock::now() - m_begin).count();
	}
public:
	Timer():m_begin(chrono::high_resolution_clock::now()){}
	void reset() {
		m_begin = chrono::high_resolution_clock::now();
	}
	
	int64_t elapsed_micro()const
	{
		return elapsed<chrono::microseconds>();
	}
	int64_t elapsed_nano()const
	{
		return elapsed<chrono::nanoseconds>();
	}
	int64_t elapsed_seconds()const
	{
		return elapsed<chrono::seconds>();
	}
	int64_t elapsed_minutes()const
	{
		return elapsed<chrono::minutes>();
	}
	int64_t elapsed_hours()const
	{
		return elapsed<chrono::hours>();
	}
};