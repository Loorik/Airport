#pragma once
#include "Airport.h"
class ExtremaAirport
{
public:
	ExtremaAirport(std::vector<Airport>);
	std::string calculateAndPrintExtrema();
private:
	std::vector<Airport> allAirports;
};