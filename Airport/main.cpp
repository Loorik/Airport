#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include<vector>
#include <sstream>
#include <algorithm>
#include "AirportCounter.h"
#include "Airport.h"
#include "StateAbb.h"
#include "ExtremaAirport.h"
using namespace std;

int main()
{
	ifstream inStates("../stateabb.txt");
	if (!inStates)
	{
		cerr << "Datei konnte nicht geoeffnet werden.";
		exit(EXIT_FAILURE);
	}

	string useless;
	getline(inStates, useless);
	string state;
	string abbreviation;
	vector<pair<string, string>> stateAbbreviations;

	while (getline(inStates, state, '\t'))
	{
		getline(inStates, abbreviation);
		stateAbbreviations.push_back(pair<string, string>(state, abbreviation));
	}
	inStates.close();
	StateAbb all;
	all.setStateAbbs(stateAbbreviations);
	//
	//
	//

	//setlocale(LC_ALL, "");


	ifstream inAirport("../airports.txt");
	if (!inAirport)
	{
		cerr << "Datei konnte nicht geöffnet werden." << endl;
		exit(EXIT_FAILURE);
	}

	getline(inAirport, useless);

	string iata;
	string airport;
	string city;
	string stateAbbreviation;
	string country;
	string tempLat;
	string tempLong;
	string upperCaseCity;
	double lat;
	double lng;

	stringstream l;


	string line;
	string chars = "\"";
	vector<Airport> allAirports;

	while (getline(inAirport, line))
	{
		for (int i = 0; i < chars.size(); i++)
		{
			line.erase(remove(line.begin(), line.end(), chars[i]), line.end()); // lösche bestimmte Zeichen aus string
		}
		l << line;
		getline(l, iata, ',');
		getline(l, airport, ',');
		getline(l, city, ',');
		getline(l, stateAbbreviation, ',');
		getline(l, country, ',');
		getline(l, tempLat, ',');
		getline(l, tempLong, ',');

		for (int i = 0; i < city.size(); i++)
		{
			upperCaseCity += toupper(city[i]);
		}

		lat = stod(tempLat);
		lng = stod(tempLong);

		allAirports.push_back(Airport(iata, airport, city, stateAbbreviation, country, lat, lng, upperCaseCity, stateAbbreviations));

		line = "";
		upperCaseCity = "";
		l.clear();
	}
	inAirport.close();
	cout << "Anzahl gespeicherter Flughäfen: " << allAirports.size();

	//
	//
	//



	char select;

	cout << "\nstateabb: " << stateAbbreviations.size();
	

	bool keepOpen = true;
	
	while (keepOpen)
	{
		cout << "\n\n[1] Infos zu IATA - Code oder Stadt auf Konsole ausgeben" << endl
			<< "[2] Anzahl Flughaefen in einzelnen Staaten / Territorien auf Konsole ausgeben" << endl
			<< "[3] Noerdlichsten und suedlichsten Flughafen auf Konsole ausgeben" << endl
			<< "[4] Entfernung zwischen zwei Flughaefen bestimmen" << endl << endl
			<< "[9] Programm beenden" << endl
			<< "Ihre Wahl : ";
		cin >> select;
		switch (select)
		{
		case '1':
		{
			cin.ignore();
			bool countHit = false;
			string s;
			cout << "\nIata oder Stadt eingeben: ";
			getline(cin, s);


			string upperS = "";
			for (int i = 0; i < s.size(); i++)
			{
				upperS += toupper(s[i]);
			}

			for (Airport a : allAirports)
			{
				//a.setStateAbbTxt(stateAbbreviations);
				if (a.informationAboutAirportsInCity(upperS))
				{
					cout << a.informationToString();
					countHit = true;
				}
			}
			if (countHit == false)
			{
				cout << "\nKonnte nicht gefunden werden.\n";
			}
			break;
		}
		case '2':
		{
			cout << "\n*** Anzahl Flughaefen in einzelnen Staaten/Territorien *** \n\n"
				<< "Staat/Territorium " << setw(30) << " Anzahl Flughaefen" << endl;
			AirportCounter tst;
			tst.setAllAirports(allAirports);
			tst.setAllStateAbbs(stateAbbreviations);
			cout << tst.countAllAirports();
			break;
		}
		case '3':
		{
			ExtremaAirport tst(allAirports);
			cout << tst.calculateAndPrintExtrema();
			break;
		}
		case '4':
		{
			//?
			break;
		}
		case '9':
			exit(EXIT_SUCCESS);
		}
	}
}
