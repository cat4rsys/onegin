all:
	@g++ -I include/ -o onegin source/main.cpp source/utilities.cpp source/input.cpp source/sort.cpp
