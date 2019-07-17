#include <iostream>
#include <locale>
#include <sstream>
#include <map>
#include "Airport.h"
using namespace std;

Airport::Airport(string ia, string ap, string cit, string sA, string ctr, double la, double lo, string uCC, vector<pair<string,string>> sabb)
	: iata(ia), airport(ap), city(cit), stateAbbreviation(sA), country(ctr), lat(la), lng(lo), upperCaseCity(uCC), stateAbbTxt(sabb)
{

}

bool Airport::informationAboutAirportsInCity(string s) 
{
	stringstream result;
	if (s == iata ||s == upperCaseCity)
	{
		return true;
	}
	return false;
}

string Airport::getStateAbbreviation() const
{
	return stateAbbreviation;
}

string Airport::convertStateAbb() const
{
	string extendedStateAbb = "";

	for (auto s : stateAbbTxt)
	{
		if (stateAbbreviation == s.second)
		{
			extendedStateAbb = s.first +" (" +s.second +")";
		}
	}
	return extendedStateAbb;
}

string Airport::informationToString() const
{
	stringstream s;
	s << iata << ": " << airport << ", " << city << ", " << convertStateAbb() << ", " << country << ", " << lat << ", " << lng << "\n";
	return s.str();
}


double Airport::getLat() const
{
	return lat;
}

double Airport::getLng() const
{
	return lng;
}