#include "Perlin.hpp"
#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <future>
#include "ctpl_stl.h"
#include "include_all.hpp"

const int samplesx = 1000;
const int samplesy = 10000;

float compute(int id, const Perlin& p2d, const int& x) {
	for(int y = 0 ; y < samplesy ; ++y)
		p2d.Get({x,y},0.1f);
}

void benchmark_serial() {

	Perlin p;

	auto start = std::chrono::steady_clock::now();

	for(int x = 0 ; x < samplesx ; ++x)
	{
		compute(0,p,x);
	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> diff = end-start;

	std::cout<<" Serial executed : " << samplesx * samplesy <<" in "<< std::chrono::duration <double, std::milli> (diff).count() << "ms" << std::endl;

}

void benchmark_parallel() {

		Perlin p;
	 	ctpl::thread_pool pool(3);

		auto start = std::chrono::steady_clock::now();

		for(int x = 0 ; x < samplesx ; ++x)
		{
	 		pool.push(compute,p,x);
	 	}

		pool.stop(true);

		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> diff = end-start;

		std::cout<<" Executed : " << samplesx * samplesy <<" in "<< std::chrono::duration <double, std::milli> (diff).count() << "ms" << std::endl;
}
