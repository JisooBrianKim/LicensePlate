#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;


bool isValidVehicleString(string vehicleString);

int getOccupants(string vehicleString);

int getSpeed(string vehicleString);

int getLicenseSeries(string vehicleString);

string getLetterGroup(string vehicleString);

int getLicenseGroup(string vehicleString);

int main()
{
	// Check case for isValidVehicleString(string vehicleString)
	/*vector<string> v1 = {
		"asdf1ABC000:2-55",
		"1ABC000:2-55 asdf",
		"1     ABC    000     :   2    -   55",
		"0ABC123:2-55",
		"1abc123:2-55",
		"1A&^123:2-55",
		"000001ABC000:2-55",
		"1ABC0000123:2-55",
		"1ABC121212:2-55",
		"1ABC000:0-55",
		"1ABC000:2-0",
		"1ABC000:2-124311",
		"1ABC000-2:55",
		"1ABC000:2-55    1ABC000:2-55",
		"1ABC000:0000002-50",
		"1ABC000:2-0000050",
		"1ABC1:2-50"
	};

	int i = 0;
	int size = static_cast<int>(v1.size());
	while (i < size)
	{
		cout << v1[i];
		if (isValidVehicleString(v1[i]))
			cout << "---GOOD---" << endl;
		else
			cout << "---BAD---" << endl;
		i++;
	}*/

	// Check getOccupants
	//cout << getOccupants("1ABC000:2344-55") << endl;;
	
	// Check getSpeed
	//cout << getSpeed("1ABC000:2-555") << endl;

	// Check getLicenseSeries
	//cout << getLicenseSeries("1ABC000:2-555") << endl;

	// Check getLetterGroup
	//cout << getLetterGroup("1ABC000:2-555") << endl;

	//Check getLicenseGroup
	//cout << getLicenseGroup("1ABC101:2-555") << endl;

	system("pause");
	return 0;
}

bool isValidVehicleString(string vehicleString)
{
	size_t size = static_cast<int>(vehicleString.size());
	int i = 0;

	while (i < size && vehicleString[i] == ' ') // Increment i until first character
		i++;

	
	int x = (int)vehicleString[i] - 48;
	if (x < 1 || x > 9) return false; // Check if first character is a digit 1-9
	i++;

	for (int j = i; j < i + 3; j++) // Check if next 3 is uppercase alpha
	{
		if (vehicleString[j] == ' ' || (!isupper(vehicleString[j]) 
			|| !isalpha(vehicleString[j]))) return false;
	}

	i += 3; 

	for (int j = i; j < i + 3; j++) // Check if next 3 is digits from 0 to 999
	{
		x = (int)vehicleString[i] - 48;
		if (vehicleString[j] == ' ' || (x > 999 && x < 0)) return false;
	}
			
	i += 3;

	if (vehicleString[i] != ':') return false; // Checks if its a semicolon
	i++;

	x = (int)vehicleString[i] - 48;

	if (x >= 1) // Checks if its a number > 1
		while (isdigit(vehicleString[i])) i++;
	else return false;
	
	if (vehicleString[i] != '-') return false; // Checks if its a dash
	i++;

	if (vehicleString[i] == '0') return false; // Checks if it leads with 0
	else
	{
		x = (int)vehicleString[i] - 48;
		if (i + 4 > size) // Checks if it is digit from 1 to 999
		{
			while (i < size) // Checks if it is a digit
			{
				if (!isdigit(vehicleString[i])) return false;
				else i++;
			}
		}
		else return false;
	}

	return true;
}

int getOccupants(string vehicleString)
{
	if (isValidVehicleString(vehicleString))
	{
		int i = 0;
		while (vehicleString[i] != ':')
			i++;
		i++;

		int x = (int)vehicleString[i] - 48;
		int y = x;
		i++;

		while (vehicleString[i] != '-')
		{
			y *= 10;
			x = (int)vehicleString[i] - 48;
			y += x;
			i++;
		}
		
		return y;
	}
	else
		return -1;
	return -1;
}

int getSpeed(string vehicleString)
{
	if (isValidVehicleString(vehicleString))
	{
		int i = 0;
		while (vehicleString[i] != '-')
			i++;
		i++;

		int x = (int)vehicleString[i] - 48;
		int y = x;
		i++;

		int size = static_cast<int>(vehicleString.size());

		while (i < size)
		{
			y *= 10;
			x = (int)vehicleString[i] - 48;
			y += x;
			i++;
		}

		return y;
	}
	else
		return -1;
	return -1;
}

int getLicenseSeries(string vehicleString)
{
	if (isValidVehicleString(vehicleString))
	{
		int i = 0;

		while (vehicleString[i] == ' ') // Increment i until first character
			i++;

		int x = (int)vehicleString[i] - 48;

		return x;
	}
	else
		return -1;
	return -1;
}

string getLetterGroup(string vehicleString)
{
	if (isValidVehicleString(vehicleString))
	{
		int i = 0;

		while (!isalpha(vehicleString[i])) i++;

		string str;

		for (int j = 0; j < 3; j++)
		{
			str.push_back(vehicleString[i]);
			i++;
		}
		return str;
	}
	else
		return "";

	return "";
}

int getLicenseGroup(string vehicleString)
{
	if (isValidVehicleString(vehicleString))
	{
		int i = 0;

		while (vehicleString[i] == ' ') // Increment i until first character
			i++;

		i += 4; // Increment until license group index

		int x = (int)vehicleString[i++] - 48;
		int y = x;

		while (vehicleString[i] != ':')
		{
			y *= 10;
			x = (int)vehicleString[i] - 48;
			y += x;
			i++;
		}
		
		return y;
	}
	else
		return -1;
	return -1;
}