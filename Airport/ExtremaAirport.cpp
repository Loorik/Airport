#include "ExtremaAirport.h"
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

ExtremaAirport::ExtremaAirport(vector<Airport> all)
	:allAirports(all)
{

}

string ExtremaAirport::calculateAndPrintExtrema()
{
	const int borderBottom = -125;
	const int borderTop = -68;
	
	stringstream s;
	//alle Flughäfen
	Airport tempMax;
	Airport tempMin;
	double max = 0.0;
	double min = 10000.0;

	//Kerngebiet 
	Airport tempCoreMax;
	Airport tempCoreMin;
	double CoreMax = allAirports[1].getLat();
	double CoreMin = allAirports[1].getLat();

	for (int i = 0; i < allAirports.size(); i++)
	{
		if (allAirports[i].getLat() >= max)
		{
			max = allAirports[i].getLat();
			tempMax = allAirports[i];

		}
		if (allAirports[i].getLat() <= min)
		{
			min = allAirports[i].getLat();
			tempMin = allAirports[i];
		}
		if (allAirports[i].getLng() <= borderTop && allAirports[i].getLng() >= borderBottom)
		{
			if (allAirports[i].getLat() >= CoreMax)
			{
				CoreMax = allAirports[i].getLat();
				tempCoreMax = allAirports[i];
			}
			if (allAirports[i].getLat() <= CoreMin)
			{
				CoreMin = allAirports[i].getLat();
				tempCoreMin = allAirports[i];
			}
		}

	}


	s << "***Alle Flughaefen***\n\n"
		<< left << "Noerdlichster Flughafen:" << setw(7)<<" " << tempMax.informationToString() << endl
		<< left << "Suedlichster Flughafen:" << setw(7)<<" " << tempMin.informationToString() << endl << endl
		<< "***Kerngebiet***\n\n"
		<< left << "Noerdlichster Flughafen:" << setw(7)<<" " << tempCoreMax.informationToString() << endl
		<< left << "Suedlichster Flughafen:" << setw(7) <<" "<< tempCoreMin.informationToString() << endl << endl;
	return s.str();
}
