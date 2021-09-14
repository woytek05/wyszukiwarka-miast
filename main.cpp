#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");

  string line;
  double x;

  vector<string> city;
  vector<pair<double, double>> coordinates;
  map<string, pair<double, double>> map;
  map<string, double> map2;

  fstream file;
  file.open("miasta-pl.txt", ios::in);

  if (!file.good())
  {
    cout << "Cannot open file!";
    exit(0);
  }

  while (!file.eof())
  {
    getline(file, line);
    int start_index = line.find("PL") + 4;
    int end_index;
    string city_name = line.substr(start_index, end_index);
    city.push_back(city_name);

    start_index = end_index;
    start_index += 3;
    double lat = stod(line.substr(start_index, end_index));

    start_index = end_index;
    start_index += 3;
    double lng = stod(line.substr(start_index, end_index));

    pair<double, double> set(lat, lng);
    coordinates.push_back(set);
  }

  file.close();

  return 0;
}