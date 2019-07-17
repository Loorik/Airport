#pragma once
#include <string>
#include "StateAbb.h"

class Airport
{
public:
	Airport() {};
	Airport(std::string, std::string, std::string, std::string, std::string, double, double, std::string, std::vector<std::pair<std::string,std::string>>);
	std::string convertStateAbb() const;
	std::string informationToString() const;
	bool informationAboutAirportsInCity(std::string);
	std::string getStateAbbreviation() const;
	double getLat() const;
	double getLng() const;

private:
	std::vector<std::pair<std::string, std::string>>stateAbbTxt;
	std::string upperCaseCity; //State Abbreviaton*
	std::string iata;
	std::string airport;
	std::string city;
	std::string stateAbbreviation;
	std::string country;
	double lat;
	double lng;
};