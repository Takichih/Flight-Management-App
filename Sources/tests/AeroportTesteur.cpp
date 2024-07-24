/**
 * \file   AeroportTesteur.cpp
 * \brief  Test file for the Aeroport class.
 * \author Chih Taki-eddine
 * \date June 24, 2024
 */
#include <gtest/gtest.h>
#include "Airport.h"
#include "Arrival.h"
#include "Depart.h"
#include "Flight.h"
#include "ContratException.h"
#include "FlightException.h"
#include <vector>

using namespace aerien;
using namespace std;

/**
 * \brief Test of the constructor with a valid code.
 *
 * This test verifies that the constructor of the Airport class correctly initializes
 * an object with a valid code and that the method reqCode() returns the correct value.
 */

TEST (Airport, DefaultConstructor)
{
  Airport a1("YUL");
  ASSERT_EQ("YUL", a1.getCode ());
}



/**
 * \brief Test of the constructor with an invalid code.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided code is invalid.
 */
TEST(Airport, InvalidConstructor) {
    ASSERT_THROW(Airport airport("233"), PreconditionException);
}


/**
 * \brief Test of the constructor with an empty code.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided parameter is empty.
 */
TEST(Airport, EmptyParam) {
    ASSERT_THROW(Airport airport(""), PreconditionException);
}

/**
 * \brief Test of the copy constructor.
 *
 * This test verifies that the copy constructor performs a deep copy
 * of the Airport object.
 */
TEST(Airport, CopyConstructor) {
    Airport airport1("YUL");
    Arrival arrival("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"," Atterri ");
    airport1.addFlight(arrival);
    Airport airport2(airport1);
    ASSERT_EQ(airport1.getAirportFormatted (), airport2.getAirportFormatted ());
}


/**
 * \brief Test of the assignment operator.
 *
 * This test verifies that the assignment operator performs a deep copy
 * of the Airport object.
 */
TEST(Airport, AssignmentOperator) {
    Airport airport1("YUL");
    Arrival arrival("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"," Atterri ");
    airport1.addFlight (arrival);
    Airport airport2("YYZ");
    airport2 = airport1;
    ASSERT_EQ(airport1.getAirportFormatted (), airport2.getAirportFormatted ());
}

/**
 * \brief Test of the getAirportFormatted() method.
 *
 * This test verifies that the getAirportFormatted() method returns a properly
 * formatted string representing the flights at the airport.
 */
TEST(Airport, getAirportFormatted) {
    Airport airport("YUL");
    Arrival arrival("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"," Atterri ");
    Depart depart("DL5064","DELTA","16:05","NEW YORK","15:30","C88");
    
    airport.addFlight (arrival);
    airport.addFlight (depart);

    string attendu = "Airport YUL\n\n"
                     "Departure schedule\n"
                     "------------------------------------------------------------------\n"
                     "| FLIGHT  |  COMPANY       |HOUR|         CITY       |EMBRQ|GATE |\n"
                     "------------------------------------------------------------------\n"
                     "|DL5064|       DELTA       |16:05|     NEW YORK      |15:30| C88 |\n"
                     "------------------------------------------------------------------\n"
                     "Arrivals schedule\n"
                     "----------------------------------------------------------------\n"
                     "|FLIGHT|     COMPANY       |HOUR|        CITY        |  STATUT |\n"
                     "----------------------------------------------------------------\n"
                     "|RJ0271|  ROYAL JORDANIAN  |07:12|       AMMAN       | Atterri |\n"
                     "----------------------------------------------------------------\n";
    ASSERT_EQ(attendu, airport.getAirportFormatted ());
}

/**
 * @brief Test class to test the features of the Airport class.
 */

class TheAirport: public ::testing::Test
{
public:
  
    /**
    * @brief Default constructor.
    * Initializes the airport with the code "YUL".
    */
    TheAirport(): f_Airport("YUL"){};
    Airport f_Airport;     
};

/**
 * @brief Tests adding a valid flight to the airport.
 *
 * This test verifies that adding a flight with valid information is correctly
 * performed in the airport. It ensures that the added flight is present in the
 * formatted representation of the airport.
 *
 * @test
 * Adds a flight to the airport with the following information: flight number "LH0478",
 * airline "LUFTHANSA", time "22:05", destination "MUNICH", and status " Delayed ".
 * Retrieves the formatted representation of the airport and verifies that the added flight number
 * is present in this representation.
 */
TEST_F(TheAirport, AddValideFlight)
{
    f_Airport.addFlight(aerien::Arrival("LH0478","LUFTHANSA","22:05","MUNICH"," Retardé "));
    string flight_number = f_Airport.getAirportFormatted ();
    bool present = flight_number.find("LH0478")!= std::string::npos;
    
    ASSERT_TRUE(present);
}

/**
 * @brief Tests adding an already present flight to the airport.
 *
 * This test verifies that adding a flight with a flight number already present in the airport
 * raises a FlightAlreadyExistsException.
 *
 * @test
 * Adds a flight to the airport with the following information: flight number "LH0478",
 * airline "LUFTHANSA", time "22:05", destination "MUNICH", and status " Delayed ".
 * Attempts to add another flight with the same flight number but different information. Checks
 * that this operation raises a FlightAlreadyExistsException.
 */
TEST_F(TheAirport, Add_an_Existing_flight)
{
    f_Airport.addFlight(aerien::Arrival("LH0478", "LUFTHANSA", "22:05", "MUNICH", " Retardé "));
    
    ASSERT_THROW(
    {
        f_Airport.addFlight(aerien::Arrival("LH0478", "ABCDE", "11:11", "AZERTY", " Retardé "));
    }, FlightAlreadyExistsException);
}



/**
 * @brief Tests deleting a valid flight.
 * Adds a flight, deletes it, and checks its absence in the formatted table.
 */
TEST_F(TheAirport, Delete_Valide_Flight)
{ 
    f_Airport.addFlight(aerien::Arrival("LH0478","LUFTHANSA","22:05","MUNICH"," Retardé "));
    f_Airport.deleteFlight("LH0478");

    std::string AirportFormatted = f_Airport.getAirportFormatted ();
    bool volAbsent = AirportFormatted.find("LH0478") == std::string::npos;
    
    EXPECT_TRUE(volAbsent);
}

/**
 * @brief Tests deleting a non-existent flight.
 * Adds a flight and tries to delete another non-existent flight,
 * verifying that it raises a FlightAbsentException.
 */
TEST_F(TheAirport, Delete_nonexistent_Flight)
{ 
    f_Airport.addFlight(aerien::Arrival("LH0478","LUFTHANSA","22:05","MUNICH"," Retardé "));
    
    ASSERT_THROW(f_Airport.deleteFlight("LH0792"), FlightAbsentException);
}

/**
 * @brief Tests deleting a flight with an invalid number.
 * Adds a flight and tries to delete a flight with an invalid number,
 * verifying that it raises a PreconditionException.
 */
TEST_F(TheAirport, Delete_invalid_Flight)
{ 
    f_Airport.addFlight(aerien::Arrival("LH0478","LUFTHANSA","22:05","MUNICH"," Retardé "));
    
    ASSERT_THROW(f_Airport.deleteFlight("LH0792568"), PreconditionException);
}