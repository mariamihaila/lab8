#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DateProfile { 

private:
  char gender;
  char searchGender;
  int romance;
  int finance;
  string name;


  double determineGenderFit(DateProfile partner) {
	return (searchGender == partner.gender)? 1.0 : 0.0;
  }

  double determineRomanceFit(DateProfile partner) {
	return 1.0 - abs(partner.romance - romance)/MAX_ROMANCE;
  }

  double determineFinanceFit(DateProfile partner) {
	return 1.0 - abs(partner.finance - finance)/MAX_FINANCE;
  }

  double fitValue(DateProfile partner);

public:
  DateProfile();
  DateProfile(string name, char gender, char searchGender,
			  int romance, int finance);

  static const int MIN_ROMANCE = 1;
  static const int MAX_ROMANCE = 10;
  static const int DEFAULT_ROMANCE = 5;
  static const int MIN_FINANCE = 1;
  static const int MAX_FINANCE = 10;
  static const int DEFAULT_FINANCE = 5;
  static const int MIN_NAME_LEN = 1;
  static const int MAX_NAME_LEN = 30;
  static const char DEFAULT_GEND = 'F';
  static const char DEFAULT_SEARCH_GEND = 'M';
  static const string DEFAULT_NAME;

  //Accessors

  char getGender();
  char getSearchGender();
  int getRomance();
  int getFinance();
  string getName();


  //mutators

  bool setGender(char gender);
  bool setSearchGender( char searchGender);
  bool setRomance(int romance);
  bool setFinance(int finance);
  bool setName(string name);
  void setDefaults();
};


int main() {
  DateProfile applicant1 = DateProfile("Susan", 'F', 'M', 9, 3);
  DateProfile applicant2 = DateProfile("Elaine", 'F', 'M', 5, 8);
  DateProfile applicant3 = DateProfile("George", 'M', 'F', 6, 9);
  DateProfile applicant4 = DateProfile("Jerry", 'M', 'F', 3, 7);
  
}

const string DateProfile::DEFAULT_NAME = "No Name";

DateProfile::DateProfile()
{
  setDefaults();
}

DateProfile::DateProfile(string name, char gender, char searchGender,
						 int romance, int finance) {
  this->name = name;
  this->gender = gender;
  this->searchGender = searchGender;
  this->romance = romance;
  this->finance = finance;
}

void DateProfile::setDefaults()
{
  this->name = DEFAULT_NAME;
  this->gender = DEFAULT_GEND;
  this->searchGender = DEFAULT_SEARCH_GEND;
  this->romance = DEFAULT_ROMANCE;
  this->finance = DEFAULT_FINANCE;
}

string DateProfile::getName()
{
  return name;
}

char DateProfile::getGender()
{
  return gender;
}

char DateProfile::getSearchGender()
{
  return searchGender;
}

int DateProfile::getRomance()
{
  return romance;
}

int DateProfile::getFinance()
{
  return finance;
}

bool DateProfile::setName(string name)
{
  return true;
}

double DateProfile::fitValue(DateProfile partner)
{
  if (determineGenderFit(partner) == 0.0)
  {
	return 0.0;
  }
  return (determineRomanceFit(partner) + determineFinanceFit(partner)) / 2.0;
}


  
  
