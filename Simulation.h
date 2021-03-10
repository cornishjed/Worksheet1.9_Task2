#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <chrono>
#include <thread>
#include "LinkedList.h"
#include "Bunny.h"
using namespace std;

class Simulation
{
public:
	Simulation();
	void run();

private:
	linkedList bunnyList;
};

#endif // !INTERFACE_H