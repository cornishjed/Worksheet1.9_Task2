# Worksheet1.9_Task2

First set of requirements: 

Write a program that creates a linked list of bunny objects. You must not use the STL List for this task. Each bunny object must have the following data:
•	Sex: Male, Female (random at creation 50/50)
•	colour: white, brown, black, spotted
•	age : 0-10 (years old)
•	Name : randomly chosen from a list of 10 bunny names (choice these yourself)

Second set of requirements:

Write program that simulates a population of bunny rabbits in real-time using the follow set of criteria:

•	At program initialization 5 bunnies must be created and given random colours.
•	Each turn bunnies age by 1 year.
•	Bunnies die when they reach 10 years of age
•	If there is at least one adult male (aged 2+), every adult female gives birth to a new bunny, e.g. if there was 1 adult male and 3 adult females, 3 new bunnies would be born
•	New bunnies are born with the same colour as their mother
•	The program should print a list of all the bunnies in the colony each turn giving all the bunnies details, sorted by age.
•	Each turn lasts 2 seconds and there should be a 1 second pause for announcements
•	When all bunnies have died the program terminates
•	If the population exceeds 50, a food shortage occurs killing exactly half of the bunnies chosen at random
