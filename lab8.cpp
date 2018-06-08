#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class DateProfile { 

private:
  char gender;
  char searchGender;
  int romance;
  int finance;
  string name;

  double determineGenderFit(DateProfile partner);
  double determineRomanceFit(DateProfile partner);
  double determineFinanceFit(DateProfile partner);

public:
  DateProfile();
  DateProfile(char gender, char searchGender,
              int romance, int finance, string name);

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

  // Accessors
  char getGender();
  char getSearchGender();
  int getRomance();
  int getFinance();
  string getName();

  // Mutators
  bool setGender(char gender);
  bool setSearchGender(char searchGender);
  bool setRomance(int romance);
  bool setFinance(int finance);
  bool setName(string name);
  void setDefaults();
  void setAll(char gender, char searchGender,
              int romance, int finance, string name);
  double fitValue(DateProfile partner);
  void print();
};

void displayTwoProfiles(DateProfile profile1, DateProfile profile2)
{
  cout << "Fit between " << profile1.getName() << " and " << profile2.getName() << ":" 
       << endl << profile1.fitValue(profile2) << endl;
}

int main() {
  DateProfile applicant1 = DateProfile('F', 'M', 9, 3, "Susan Ross");
  DateProfile applicant2 = DateProfile('F', 'M', 5, 8, "Elaine Benes");
  DateProfile applicant3 = DateProfile('M', 'F', 3, 10, "George Constanza");
  DateProfile applicant4 = DateProfile('M', 'F', 1, 3, "Jerry Seinfeld");

  applicant1.print();
  applicant2.print();
  applicant3.print();
  applicant4.print();  
  
  displayTwoProfiles(applicant1, applicant1);
  displayTwoProfiles(applicant1, applicant2);
  displayTwoProfiles(applicant1, applicant3);
  displayTwoProfiles(applicant1, applicant4);
  
  displayTwoProfiles(applicant2, applicant1);
  displayTwoProfiles(applicant2, applicant2);
  displayTwoProfiles(applicant2, applicant3);
  displayTwoProfiles(applicant2, applicant4);
  
  displayTwoProfiles(applicant3, applicant1);
  displayTwoProfiles(applicant3, applicant2);
  displayTwoProfiles(applicant3, applicant3);
  displayTwoProfiles(applicant3, applicant4);
  
  displayTwoProfiles(applicant4, applicant1);
  displayTwoProfiles(applicant4, applicant2);
  displayTwoProfiles(applicant4, applicant3);
  displayTwoProfiles(applicant4, applicant4);
}

const string DateProfile::DEFAULT_NAME = "No Name";

DateProfile::DateProfile()
{
  setDefaults();
}

DateProfile::DateProfile(char gender, char searchGender,
                         int romance, int finance, string name)
{
  setAll(gender, searchGender, romance, finance, name);
}

void DateProfile::setDefaults()
{
  name = DEFAULT_NAME;
  gender = DEFAULT_GEND;
  searchGender = DEFAULT_SEARCH_GEND;
  romance = DEFAULT_ROMANCE;
  finance = DEFAULT_FINANCE;
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
  if (name.length() < MIN_NAME_LEN || name.length() > MAX_NAME_LEN)
    return false;
  this->name = name;
  return true;
}

bool DateProfile::setGender(char gdr)
{
  if (gdr != 'M' && gdr != 'F')
    return false;
  this->gender = gdr;
  return true;
}

bool DateProfile::setSearchGender(char searchGdr)
{
  if (searchGdr != 'M' && searchGdr != 'F')
    return false;
  this->searchGender = searchGdr;
  return true;
}

bool DateProfile::setFinance(int finance)
{
  if (finance < MIN_FINANCE || finance > MAX_FINANCE)
    return false;
  this->finance = finance;
  return true;
}

bool DateProfile::setRomance(int romance)
{
  if (romance < MIN_ROMANCE || romance > MAX_ROMANCE)
    return false;
  this->romance = romance;
  return true;
}

double DateProfile::determineGenderFit(DateProfile partner) {
  if (searchGender != partner.gender)
    return 0.0;
  if (partner.searchGender != gender)
    return 0.0;
  return 1.0;
}

double DateProfile::determineRomanceFit(DateProfile partner) {
  return 1.0 - abs(partner.romance - romance)/(double)MAX_ROMANCE;
}

double DateProfile::determineFinanceFit(DateProfile partner) {
  return 1.0 - abs(partner.finance - finance)/(double)MAX_FINANCE;
}
                             
double DateProfile::fitValue(DateProfile partner)
{
  const double genderFit = determineGenderFit(partner);
  if (genderFit == 0.0)
  {
    return 0.0;
  }
  const double romanceFit = determineRomanceFit(partner);
  const double financeFit = determineFinanceFit(partner);
  return (romanceFit + financeFit) / 2.0;
}

void DateProfile::setAll(char gender, char searchGender,
                         int romance, int finance, string name)
{
  if (!setGender(gender))
    this->gender = DEFAULT_GEND;
  if (!setSearchGender(searchGender))
    this->searchGender = DEFAULT_SEARCH_GEND;
  if (!setRomance(romance))
    this->romance = DEFAULT_ROMANCE;
  if (!setFinance(finance))
    this->finance = DEFAULT_FINANCE;
  if (!setName(name))
    this->name = DEFAULT_NAME;
}  

void DateProfile::print()
{
  cout << gender << ", " << searchGender << ", " << romance
       << ", " << finance << ", " << name << endl;
}
