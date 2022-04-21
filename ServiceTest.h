#pragma once
#include "Service.h"
#include <iostream>
#include <cassert>

class ServiceTest {
public:
	static void runAllTests();
	static int creationTest();
	static int gettersSettersTest();
	static int featuresTests();
};