#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");

  string line, input;
  double x;
  vector<string> cities;
  fstream file;
  file.open("miasta-pl.txt", ios::in);

  if (!file.good())
    cout << "Nie można otworzyć pliku!";

  while (!file.eof())
  {
    getline(file, line);
    int begin = line.find("PL") + 4;
    //string city = line.substr(begin, end);
    //cities.push_back(city);
  }

  file.close();

  /*for (int i = 0; i < cities.size(); i++)
  {
    cout << cities[i] << endl;
  }*/

  /*cout << "Enter city name: ";
  cin >> input;

  if () //Jeżeli ten input znajduje się w wektorze cities, podaj x.
  {
    cout << "Enter the number of kilometers within which to find other cities: ";
    cin >> x;
  }
  else //Jeżeli nie ma takiego miasta w wektorze, wypisz userowi wszystkie wyniki do ostatniej poprawnej literki.
  {
  }*/

  return 0;
}