#include "Perlin.hpp"
#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <future>

float compute(const Perlin& p2d, float x) {
	return p2d.Get({x,0},0.1f);
}

void benchmark_async() {
	std::vector<std::future<float>> densities;
	Perlin p;

	int samples = 100000;

	auto start = std::chrono::steady_clock::now();

	for(int x = 0 ; x < samples ; ++x) {
		densities.push_back(std::async(compute, p, x));
	}

	for(auto &e : densities) {
	    e.get();
	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> diff = end-start;

/*
	for(int i = 0 ; i < 10 ; i++) {
		float v = densities.at(i).get();
	  std::cout<< " P2d : " << v << std::endl;
	}
*/
	std::cout<<" Executed : " << samples <<" in "<< std::chrono::duration <double, std::milli> (diff).count() << "ms" << std::endl;
}
