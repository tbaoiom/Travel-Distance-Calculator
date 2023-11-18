#include <algorithm>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Enumeration of cities and declaration of 2D array
enum CityType {
  INVALID = -1,
  ATLANTA = 0,
  BOSTON,
  CHICAGO,
  DALLAS,
  DENVER,
  HOUSTON,
  LOS_ANGELES,
  MEMPHIS,
  MIAMI,
  NEW_YORK,
  PHILADELPHIA,
  PHOENIX,
  SAN_FRANCISCO,
  SEATTLE,
  WASHINGTON_DC
};

const int CITIES = 15;
const int distanceTable[CITIES][CITIES] = {
    {0, 1505, 944, 1157, 1945, 1126, 3108, 541, 973, 1200, 1070, 2555, 3434,
     3503, 871},
    {1505, 0, 1367, 2491, 2839, 2578, 4166, 1824, 2022, 306, 435, 3691, 4330,
     3997, 634},
    {944, 1366, 0, 1290, 1474, 1510, 2444, 773, 1912, 1145, 1069, 2332, 2981,
     2787, 956},
    {1157, 2491, 1290, 0, 1064, 362, 1990, 675, 1785, 2204, 2086, 1422, 2380,
     2701, 1900},
    {1945, 2838, 1474, 1064, 0, 1412, 1335, 1411, 2773, 2617, 2532, 942, 1524,
     1640, 2395},
    {1127, 2579, 1511, 362, 1412, 0, 2205, 778, 1544, 2279, 2154, 1631, 2641,
     3038, 1958},
    {3108, 4166, 2800, 1990, 1335, 2205, 0, 2573, 3755, 3933, 3918, 574, 559,
     1544, 3689},
    {541, 1824, 773, 675, 1411, 778, 2573, 0, 1404, 1533, 1413, 2026, 2893,
     2997, 1226},
    {973, 2022, 1912, 1785, 2773, 1544, 3755, 1404, 0, 1756, 1643, 3182, 4166,
     4392, 1487},
    {1200, 306, 1145, 2204, 2617, 2279, 3933, 1533, 1756, 0, 130, 3441, 4126,
     3863, 328},
    {1070, 435, 1069, 2086, 2532, 2154, 3918, 1413, 1643, 130, 0, 3342, 4047,
     3816, 199},
    {2555, 3691, 2332, 1422, 942, 1631, 574, 2026, 3182, 3441, 3342, 0, 1050,
     1792, 3180},
    {3434, 4330, 2981, 2380, 1524, 2641, 559, 2893, 4166, 4126, 4047, 1050, 0,
     1092, 3916},
    {3503, 3997, 2787, 2701, 1640, 3038, 1544, 2997, 4392, 3863, 3816, 1792,
     1092, 0, 3734},
    {871, 634, 956, 1900, 2395, 1958, 3689, 1226, 1487, 328, 199, 3180, 3916,
     3734, 0}};

// Function to convert user input into enumerator value
CityType getCityFromStr(string cityStr) {

  CityType cityNum;

  if (cityStr == "ATLANTA") {
    cityNum = CityType::ATLANTA;
  } else if (cityStr == "BOSTON") {
    cityNum = CityType::BOSTON;
  } else if (cityStr == "CHICAGO") {
    cityNum = CityType::CHICAGO;
  } else if (cityStr == "DALLAS") {
    cityNum = CityType::DALLAS;
  } else if (cityStr == "DENVER") {
    cityNum = CityType::DENVER;
  } else if (cityStr == "HOUSTON") {
    cityNum = CityType::HOUSTON;
  } else if (cityStr == "LOS_ANGELES") {
    cityNum = CityType::LOS_ANGELES;
  } else if (cityStr == "MEMPHIS") {
    cityNum = CityType::MEMPHIS;
  } else if (cityStr == "MIAMI") {
    cityNum = CityType::MIAMI;
  } else if (cityStr == "NEW_YORK") {
    cityNum = CityType::NEW_YORK;
  } else if (cityStr == "PHILADELPHIA") {
    cityNum = CityType::PHILADELPHIA;
  } else if (cityStr == "PHOENIX") {
    cityNum = CityType::PHOENIX;
  } else if (cityStr == "SAN_FRANCISCO") {
    cityNum = CityType::SAN_FRANCISCO;
  } else if (cityStr == "SEATTLE") {
    cityNum = CityType::SEATTLE;
  } else if (cityStr == "WASHINGTON_DC") {
    cityNum = CityType::WASHINGTON_DC;
  } else {
    cityNum = CityType::INVALID;
  }
  return cityNum;
}

// Function that converts enumerator value into city name as a string
string getCityName(CityType cityValue) {
  string cityName;
  switch (cityValue) {
  case CityType::ATLANTA:
    cityName = "Atlanta";
    break;
  case CityType::BOSTON:
    cityName = "Boston";
    break;
  case CityType::CHICAGO:
    cityName = "Chicago";
    break;
  case CityType::DALLAS:
    cityName = "Dallas";
    break;
  case CityType::DENVER:
    cityName = "Denver";
    break;
  case CityType::HOUSTON:
    cityName = "Houston";
    break;
  case CityType::LOS_ANGELES:
    cityName = "Los Angeles";
    break;
  case CityType::MEMPHIS:
    cityName = "Memphis";
    break;
  case CityType::MIAMI:
    cityName = "Miami";
    break;
  case CityType::NEW_YORK:
    cityName = "New York";
    break;
  case CityType::PHILADELPHIA:
    cityName = "Philadelphia";
    break;
  case CityType::PHOENIX:
    cityName = "Phoenix";
    break;
  case CityType::SAN_FRANCISCO:
    cityName = "San Francisco";
    break;
  case CityType::SEATTLE:
    cityName = "Seattle";
    break;
  case CityType::WASHINGTON_DC:
    cityName = "Washington DC";
    break;
  default:
    break;
  }
  return cityName;
}

// Function that copies global array into argument array
void buildDistanceTable(int arr[][CITIES], int ARR_SIZE) {
  bool alert = true;
  const int distanceDelay = 75;
  // Denver origin city
  // Seattle, San Francisco, Los Angeles delayed cities
  const int originCity = 4;
  const int delayedCitiesSize = 3;
  const int delayedCities[delayedCitiesSize] = {6, 12, 13};

  for (int i = 0; i < ARR_SIZE; i++) {
    for (int j = 0; j < ARR_SIZE; j++) {
      arr[i][j] = distanceTable[i][j];
    }
  }

  // Adds 75 mile distance to cities west of Denver when there is an alert
  if (alert) {
    for (int i = 0; i < delayedCitiesSize; i++) {
      arr[originCity][delayedCities[i]] += distanceDelay;
      arr[delayedCities[i]][originCity] += distanceDelay;
    }
    cout << "Warning!!! Due to a snowstorm in Colorado, I-70 has been closed. "
            "This will effect the trips from Denver to Los_Angeles, San "
            "Francisco, and Seattle"
         << endl;
  }
}

// Function that calculates the trip cost after user inputs mileage and gas
// price
double getTripCost(int arr[][CITIES], CityType departingCity,
                   CityType arrivingCity) {
  double mileage;
  double gasPrice;
  double distance;

  cout << "Enter the car's miles per gallon: " << endl;
  cin >> mileage;
  cout << "Enter the price of gas: " << endl;
  cin >> gasPrice;

  distance = arr[departingCity][arrivingCity];
  return distance * (1 / mileage) * gasPrice;
}

// Function to get average distance from departing city to all other cities
double getAverageDistance(int arr[][CITIES], CityType departingCity) {
  // If enum value is out of range, returns a -1
  if (departingCity >= CITIES || departingCity < 0) {
    return -1;
  }

  double distanceSum = 0;
  for (int i = 0; i < CITIES; i++) {
    distanceSum += arr[departingCity][i];
  }

  return distanceSum / (CITIES - 1);
}

// Function to get the closest city
string getClosestCity(int arr[][CITIES], CityType departingCity) {
  string closestCity;

  int distanceTracker = arr[departingCity][0];
  for (int i = 0; i < CITIES; i++) {
    if (arr[departingCity][i] < distanceTracker && arr[departingCity][i] > 0) {
      distanceTracker = arr[departingCity][i];
      closestCity = getCityName(static_cast<CityType>(i));
    }
  }
  return closestCity + ", " + std::to_string(distanceTracker);
}

// Function to get the farthest city
string getFarthestCity(int arr[][CITIES], CityType departingCity) {
  string farthestCity;
  int distanceTracker = 0;

  for (int i = 0; i < CITIES; i++) {
    if (arr[departingCity][i] > distanceTracker) {
      distanceTracker = arr[departingCity][i];
      farthestCity = getCityName(static_cast<CityType>(i));
    }
  }
  return farthestCity + ", " + std::to_string(distanceTracker);
}

// Function to get the closest two cities
string getClosestTwoCities(int arr[][CITIES]) {
  string closeCity1;
  string closeCity2;
  int distanceTracker = arr[0][1];

  for (int i = 0; i < CITIES; i++) {
    for (int j = 0; j < CITIES; j++) {
      if (arr[i][j] < distanceTracker && arr[i][j] != 0) {
        distanceTracker = arr[i][j];
        closeCity1 = getCityName(static_cast<CityType>(i));
        closeCity2 = getCityName(static_cast<CityType>(i));
      }
    }
  }
  return closeCity1 + " and " + closeCity2 + ", " + std::to_string(distanceTracker) + " miles";
}

// Function to get the farthest two cities
string getFarthestTwoCities(int arr[][CITIES]) {
  string farCity1;
  string farCity2;
  int distanceTracker = 0;

  for (int i = 0; i < CITIES; i++) {
    for (int j = 0; j < CITIES; j++) {
      if (arr[i][j] > distanceTracker) {
        distanceTracker = arr[i][j];
        farCity1 = getCityName(static_cast<CityType>(i));
        farCity2 = getCityName(static_cast<CityType>(i));
      }
    }
  }
  return farCity1 + " and " + farCity2 + ", " +
         std::to_string(distanceTracker) + " miles";
}

int main() {
  // Declaration of variables
  string departingCityInput;
  string arrivingCityInput;
  CityType departingCity;
  CityType arrivingCity;
  int arr[CITIES][CITIES];
  double tripCost;
  double averageDistance;
  string closestCity;
  string farthestCity;
  string closestTwoCities;
  string farthestTwoCities;
  bool validInput = false;

  // Ask user for cities until a valid input is entered
  while (!validInput) {
    cout << "Enter the departing city name: " << endl;
    cin >> departingCityInput;
    cout << "Enter the arriving city name: " << endl;
    cin >> arrivingCityInput;

    // Turns inputs into uppercase
    std::transform(departingCityInput.begin(), departingCityInput.end(),
                   departingCityInput.begin(), ::toupper);
    std::transform(arrivingCityInput.begin(), arrivingCityInput.end(),
                   arrivingCityInput.begin(), ::toupper);

    if (getCityFromStr(departingCityInput) == -1 ||
        getCityFromStr(arrivingCityInput) == -1) {
      cout << "Not a valid city: Try again." << endl;
    } else {
      break;
    }
  }

  // Builds 2D array of distance table
  buildDistanceTable(arr, CITIES);

  // Calculates and displays cost of trip
  departingCity = getCityFromStr(departingCityInput);
  arrivingCity = getCityFromStr(arrivingCityInput);

  tripCost = getTripCost(arr, departingCity, arrivingCity);

  cout.setf(std::ios::fixed);
  cout.setf(std::ios::showpoint);
  cout.precision(2);
  cout << "The distance between " << getCityName(departingCity) << " and " << getCityName(arrivingCity) << " is "
       << arr[departingCity][arrivingCity] << " miles." << endl;
  cout << "The cost of that trip is $" << tripCost << endl;

  // Calculates and displays average distance between departing city and all
  // other cities
  averageDistance = getAverageDistance(arr, departingCity);
  cout << "The average distance between " << getCityName(departingCity)
       << " and all other cities is " << averageDistance << " miles." << endl;

  // Gets the closest city to the departing city and displays it
  closestCity = getClosestCity(arr, departingCity);
  cout << "The closest city is " << closestCity << " miles away." << endl;

  // Gets the farthest city from departing city and displays it
  farthestCity = getFarthestCity(arr, departingCity);
  cout << "The farthest city is " << farthestCity << " miles away." << endl;

  // Gets the closest two cities in the entire table and displays it
  closestTwoCities = getClosestTwoCities(arr);
  cout << "The closest two cities are " << closestTwoCities << " apart."
       << endl;

  // Gets the farthest two cities in the entire table and displays it
  farthestTwoCities = getFarthestTwoCities(arr);
  cout << "The farthest two cities are " << farthestTwoCities << " apart."
       << endl;

  return 0;
}