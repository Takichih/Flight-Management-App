
/**
 * \file   VolTesteur.cpp
 * \brief  File containing unit tests for the Flight class and its derivatives.
 * \author Chih Taki-eddine
 * \date   June 24, 2014
 */
#include <gtest/gtest.h>
#include "ContratException.h"
#include"Flight.h"
#include <memory>
using namespace aerien;
using namespace std;

/**
 * \class TestingFlight
 * \brief Test class derived from Flight for unit testing.
 */
class TestingFlight : public Flight
{
public:
   /**
     * \brief Constructor of TestingFlight.
     * \param p_number The flight number.
     * \param p_company The name of the airline.
     * \param p_hour The flight time in 24-hour format.
     * \param p_city The destination city of the flight.
     */
  
  TestingFlight(const string & p_number,const string & p_company,
                 const string & p_hour,const string & p_city):
  Flight(p_number, p_company, p_hour, p_city){};
  
  
  /**
     * \brief Cloning method to create a copy of the TestingFlight object.
     * \return A unique pointer to a copy of the TestingFlight object.
     */
  unique_ptr<Flight> clone ()const
  {
    return make_unique <TestingFlight>(*this);
  }
  
};

/**
 * \brief Test of the default constructor of the Flight class.
 */
TEST(Flight, DefaultConstructor)
{
  TestingFlight f1("RJ0271","ROYAL JORDANIAN","07:12","AMMAN");
  ASSERT_EQ(("|RJ0271|  ROYAL JORDANIAN  |07:12|       AMMAN       |"), f1.getFlightFormatted ());
}



/**
 * \class TheFlight
 * \brief Test fixture for the Flight class and its derivatives.
 */

class TheFlight : public ::testing::Test
{
public:
     /**
     * \brief Constructor of TheFlight.
     * Initializes a TestingFlight object for testing.
     */
  TheFlight():
  f_flight ("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"){};
  TestingFlight f_flight; ///< TestingFlight object used for tests.
};

/**
 * \brief Test of the getNumber() method of the TestingFlight class.
 */
TEST_F(TheFlight,GetNumber)
{
	ASSERT_EQ("RJ0271",f_flight.getNumber ());
}

/**
 * \brief Test of the getCompany() method of the TestingFlight class.
 */
TEST_F(TheFlight,getCompany)
{
	ASSERT_EQ("ROYAL JORDANIAN",f_flight.getCompany ());
}

/**
 * \brief Test of the getHour() method of the TestingFlight class.
 */
TEST_F(TheFlight,GetHour)
{
	ASSERT_EQ("07:12",f_flight.getHour());
}

/**
 * \brief Test of the getCity() method of the TestingFlight class.
 */
TEST_F(TheFlight,GetCity)
{
	ASSERT_EQ("AMMAN",f_flight.getCity ());
}


/**
 * \brief Test of the setHour() method with a valid time of the TestingFlight class.
 */
TEST_F(TheFlight, SetValidHour)
{
  f_flight.setHour("01:00");
  ASSERT_EQ("01:00", f_flight.getHour());
}

/**
 * \brief Test of the setHour() method with an invalid hour of the TestingFlight class.
 */
TEST_F(TheFlight, SetInvalidHour)
{
  ASSERT_THROW(f_flight.setHour("27:00"), PreconditionException)<<"The time must be between 00 and 23";
}

/**
 * \brief Test of the setHour() method with invalid minutes of the TestingFlight class.
 */
TEST_F(TheFlight, SetInvalidMinutes)
{
  ASSERT_THROW(f_flight.setHour("11:70"), PreconditionException)<<"minutes must be between 0 and 60 exclusively";
}
//------------------


/**
 * \brief Test of the == operator for identical flights.
 */

TEST_F (TheFlight, EqualOperatorIdenticalFlights)
{
  TestingFlight flight2("RJ0271","ROYAL JORDANIAN","07:12","AMMAN");
  ASSERT_TRUE (f_flight == flight2);
}

/**
 * \brief Test of the == operator for flights with different numbers.
 */
TEST_F (TheFlight, EqualOperatorDifferentNumbers)
{  
  TestingFlight flight2("RJ0272","ROYAL JORDANIAN","07:12","AMMAN");
  ASSERT_FALSE(f_flight == flight2);
}


/**
 * \brief Test of the == operator for flights with identical numbers but different companies.
 */
TEST_F (TheFlight, FlightOperatorDifferent_NumeroIdentical)
{  
  TestingFlight flight2("RJ0271","WESTJEST","00:34","CALGARY");
  ASSERT_TRUE (f_flight == flight2);
}

/**
 * \brief Test of the getFlightFormatted() method of the TestingFlight class.
 */

TEST_F (TheFlight, GetFormattedFlight)
{
  ASSERT_EQ("|RJ0271|  ROYAL JORDANIAN  |07:12|       AMMAN       |", f_flight.getFlightFormatted ());
}











