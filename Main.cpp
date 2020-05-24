#include "include/DBCommandsProcessor/DBCommandsProcessor.h"

#include<iostream>

int main() {
	//DBCommandsProcessor processor;
	String pass = String::toString(hash("pesho"));
	std::cout << pass << std::endl;
	std::cout << hash("pesho");
	return 0;
}