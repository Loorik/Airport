#pragma once
#include "Airport.h"
#include "StateAbb.h"
#include <vector>
#include <map>
#include "StateAbb.h"

class AirportCounter
{
public:
	AirportCounter();
	void setAllAirports(std::vector<Airport>);
	void setAllStateAbbs(std::vector<std::pair<std::string, std::string>>);
	std::string countAllAirports();

private:
	std::vector<Airport> allAirports;
	std::vector<std::pair<std::string, std::string>> stateAbbs;
};