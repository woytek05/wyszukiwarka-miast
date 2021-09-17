/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>*/
#include <bits/stdc++.h>

using namespace std;

float calculate_distance(pair<float, float> first_city, pair<float, float> second_city);
float find_cities_within_x_km(float x)
{
}

int main()
{
  string line, input;
  int line_number = 0;
  float x;

  vector<string> city_names;
  map<string, pair<float, float>> cities_and_coordinates;
  map<string, float> cities_and_distances;

  fstream file;
  file.open("miasta-pl.txt", ios::in);

  if (!file.good())
  {
    cout << "Cannot open file!";
    exit(0);
  }

  while (!file.eof())
  {
    if (line_number != 0)
    {
      getline(file, line);
      string city_name = "", lat = "", lng = "";
      int i = line.find('L') + 3;

      while (line[i] != ' ' || line[i + 1] != ' ')
      {
        city_name += line[i];
        i++;
      }
      city_names.push_back(city_name);

      i += 2;
      while (line[i] != ' ' || line[i + 1] != ' ')
      {
        lat += line[i];
        i++;
      }

      i += 2;
      while (i < line.length())
      {
        lng += line[i];
        i++;
      }

      pair<float, float> dataset(atof(lat.c_str()), atof(lng.c_str()));

      cities_and_coordinates[city_name] = dataset;
    }
    line_number++;
  }

  file.close();

  sort(city_names.begin(), city_names.end());

  cout << "Podaj miasto: ";
  cin >> input;

  if (cities_and_coordinates.find(input) == cities_and_coordinates.end())
  {
    //tu ma być algorytm na znalezienie najdłuższego wspólnego prefixu
    cout << "City isn't exist!" << endl;
    exit(0);
  }
  else
  {
    cout << "Podaj promien: ";
    cin >> x;

    for (int i = 0; i < city_names.size(); i++)
    {
      cities_and_distances[city_names[i]] = calculate_distance(cities_and_coordinates[input], cities_and_coordinates[city_names[i]]);
    }
    //sort(cities_and_distances.begin(), cities_and_distances.end());
    for (int i = 0; i < city_names.size(); i++)
    {
      if (cities_and_distances[city_names[i]] <= x)
        cout << city_names[i] << " " << cities_and_distances[city_names[i]] << " " << endl;
    }
  }

  return 0;
}

float calculate_distance(pair<float, float> first_city, pair<float, float> second_city)
{
  return sqrt(pow(first_city.first - second_city.first, 2) + pow(first_city.second - second_city.second, 2)) * 73;
}