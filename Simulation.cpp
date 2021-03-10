#include "Simulation.h"

Simulation::Simulation()
{
	Bunny newBunny;

	// create initial list of 5 bunnies
	for (int x = 0; x < 5; x++) {
		newBunny = newBunny.createBunny();
		bunnyList.insert(newBunny);
		bunnyList.setBunnyCount(bunnyList.getBunnyCount() + 1);
	}
}

void Simulation::run()
{
	while (bunnyList.getBunnyCount() != 0) {
		if (bunnyList.getBunnyCount() >= 50)
			bunnyList.starvation();
		bunnyList.incrementAge();
		this_thread::sleep_for(chrono::seconds(2)); //sleep function
		bunnyList.reproduction();
		bunnyList.checkAge();
		bunnyList.resetBirthCheck();
		cout << endl;
		bunnyList.print();
		cout << "---------------------------------------------------------------" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "\nNo bunnies remain." << endl;
}
