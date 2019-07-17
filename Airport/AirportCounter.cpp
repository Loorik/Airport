#include "AirportCounter.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

AirportCounter::AirportCounter()
{

}

void AirportCounter::setAllAirports(vector<Airport> all)
{
	allAirports = all;
}

void AirportCounter::setAllStateAbbs(vector<pair<string, string>> abbs)
{
	stateAbbs = abbs;
}

string AirportCounter::countAllAirports()
{
	stringstream s;
	map<string, int> countedAirportsInState;
	for (int i = 0; i < allAirports.size(); i++)						//füge in die map alle Flughäfen ein und zähle hoch wie oft es sie gibt
	{
		countedAirportsInState[allAirports[i].getStateAbbreviation()]++;
	}


	multimap<int, string> sortedAirportsinState;
	map<string, int>::iterator it;					
	for (it = countedAirportsInState.begin(); it !=	countedAirportsInState.end(); it++)		//tausche in multimap jetzt von der map -> first ist die Anzahl -> second die abkürzung
	{
		sortedAirportsinState.insert(pair<int, string>(it->second, it->first));
	}
	multimap<int, string>::iterator mmit;

	for (mmit = sortedAirportsinState.begin(); mmit != sortedAirportsinState.end(); mmit++)
	{
		for (vector<pair<string, string>>::iterator it = stateAbbs.begin(); it != stateAbbs.end(); it++)
		{
			if (mmit->second == it->second)
			{
				mmit->second = it->first;
				break;
			}
		}
	}


	for (mmit = sortedAirportsinState.begin(); mmit != sortedAirportsinState.end(); mmit++)
	{
		s <<left << setw(30) << mmit->second <<" "<<right<< mmit->first << endl;
	}

	return s.str();
}