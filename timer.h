#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

namespace myalgorithm {

class Timer {
	using clock = std::chrono::system_clock;
private:
	static clock::time_point start_, end_;
public:
	explicit Timer() {}

	inline static void Start() {
		start_ = clock::now();
	}
	inline static void End() {
		end_ = clock::now();
	}
	inline static double GetDuration() {
		auto duration = std::chrono::duration_cast
			<std::chrono::microseconds>
			(end_ - start_);
		double lf_duration = duration.count();
		lf_duration *= std::chrono::microseconds::period::num;
		lf_duration /= std::chrono::microseconds::period::den;
		return lf_duration * 1000;
	}
};

};

#endif	//	HEAD_H_