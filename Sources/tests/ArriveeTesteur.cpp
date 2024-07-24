/**
 * \file   ArriveeTesteur.cpp
 * \brief  Test file for the Arrival class.
 * \author Chih Taki-eddine
 * \date   June 26, 2024
 */
#include <gtest/gtest.h>
#include"Arrival.h"
#include "ContratException.h"
using namespace aerien;
using namespace std;
/**
 * \brief Test of the default constructor of the Arrival class.
 */
TEST(Arrival, DefaultConstructor)
{
  Arrival a("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"," Atterri ");
  ASSERT_EQ(("|RJ0271|  ROYAL JORDANIAN  |07:12|       AMMAN       | Atterri |"), a.getFlightFormatted ());
}

/**
 * \brief Test of the constructor with valid parameters.
 *
 * This test verifies that the constructor of the Arrival class correctly initializes
 * an object with valid parameters, and that the accessor methods return the correct values.
 */
TEST(Arrival, ValidParameters) {
    Arrival arrivee("RJ0271", "ROYAL JORDANIAN", "07:12", "AMMAN", " Retardé ");
    ASSERT_EQ("RJ0271", arrivee.getNumber ());
    ASSERT_EQ("ROYAL JORDANIAN", arrivee.getCompany ());
    ASSERT_EQ("07:12", arrivee.getHour ());
    ASSERT_EQ("AMMAN", arrivee.getCity ());
    ASSERT_EQ(" Retardé ", arrivee.getStatus ());
}

/**
 * \brief Test of the constructor with an invalid flight number.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided flight number is invalid.
 */

TEST(Arrival, InvalidFlightNumberParameter)
{

	ASSERT_THROW(Arrival arrivee("RJ0271s", "ROYAL JORDANIAN", "07:12", "AMMAN", " Retardé "), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid airline name.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided airline name is invalid.
 */
TEST(Arrival, InvalidCompanyParameter)
{

	ASSERT_THROW(Arrival arrivee("RJ0271s", "Algerie16", "07:12", "AMMAN", " Retardé "), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid departure time.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided departure time is invalid.
 */
TEST(Arrival, InvalidHourParameter)
{

	ASSERT_THROW(Arrival arrivee("RJ0271s", "ROYAL JORDANIAN", "47:12", "AMMAN", " Retardé "), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid destination city.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided destination city is invalid.
 */

TEST(Arrival, InvalidCityParameter)
{

    ASSERT_THROW(Arrival arrivee("RJ0271s", "ROYAL JORDANIAN", "07:12", "AMMAN05", " Retardé "), PreconditionException);
}
/**
 * \brief Test of the constructor with an invalid arrival status.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided arrival status is invalid.
 */
TEST(Arrival, InvalidStatusParameter)
{

    ASSERT_THROW(Arrival arrivee("RJ0271s", "ROYAL JORDANIAN", "07:12", "AMMAN", "Retardé"), PreconditionException);
}

/**
 * \brief Test of the constructor with invalid parameters.
 */
TEST(Arrival, InvalidConstructor) {
    ASSERT_THROW(Arrival("050271", "ROYAL1N", "07:74", "142", "Inconnu"), ContratException);
}

/**
 * \brief Test fixture for methods of the Arrival class.
 */
class TheArrival: public ::testing::Test
{
public:
  TheArrival(): f_Arrival("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"," Atterri "){};
  Arrival f_Arrival;      
};


/**
 * \brief Test of the setStatus method with a valid status.
 */
TEST_F(TheArrival, setStatusValide)
{
  f_Arrival.setStatus(" Retardé ");
  ASSERT_EQ(" Retardé ", f_Arrival.getStatus ());
}

/**
 * \brief Test of the setStatus method with an invalid status.
 */
TEST_F(TheArrival, InvalidSetStatus)
{
  ASSERT_THROW(f_Arrival.setStatus ("invalide"), PreconditionException);          
}

/**
 * \brief Test of the getStatus method.
 */
TEST_F(TheArrival,getStatus ){
  ASSERT_EQ(" Atterri ", f_Arrival.getStatus ());
}

/**
 * \brief Test of the getFlightFormatted method.
 */
TEST_F(TheArrival, GetFormattedFlight)
{
  ASSERT_EQ("|RJ0271|  ROYAL JORDANIAN  |07:12|       AMMAN       | Atterri |", f_Arrival.getFlightFormatted  ());
}


/**
 * \brief Test of the clone method.
 */
TEST_F(TheArrival, clone) {
    unique_ptr<Flight> clone = f_Arrival.clone();
    ASSERT_EQ(clone->getFlightFormatted(), f_Arrival.getFlightFormatted ());
}














