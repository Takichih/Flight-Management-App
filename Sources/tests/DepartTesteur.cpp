/**
 * \file   DepartTesteur.cpp
 * \brief  Test file for the Depart class.
 * \author Chih Taki-eddine
 * \date   June 26, 2024
 */

#include <gtest/gtest.h>
#include"Depart.h"
#include "ContratException.h"
#include <memory>

using namespace aerien;
using namespace std;

/**
 * \brief Test of the default constructor of the Depart class.
 */
TEST(depart, DefaultConstructor)
{
  Depart d("AC1636","AIR CANADA","18:00","ORLONDO","17:15","C86");
  ASSERT_EQ(("|AC1636|    AIR CANADA     |18:00|      ORLONDO      |17:15| C86 |"), d.getFlightFormatted ());
}

/**
 * \brief Test of the constructor with valid parameters.
 *
 * This test verifies that the constructor of the Depart class correctly initializes
 * an object with valid parameters, and that the accessor methods return the correct values.
 */

TEST(depart, ValidParameters) {
    Depart d1("AC1634","AIR FRANCE","20:00","PARIS","17:15","X47");
    ASSERT_EQ("AC1634", d1.getNumber ());
    ASSERT_EQ("AIR FRANCE", d1.getCompany ());
    ASSERT_EQ("20:00", d1.getHour ());
    ASSERT_EQ("PARIS", d1.getCity ());
    ASSERT_EQ("17:15", d1.getBoardingHour ());
    ASSERT_EQ("X47", d1.getBoardingGate ());
}

/**
 * \brief Test of the constructor with an invalid flight number.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided flight number is invalid.
 */
TEST(Depart, InvalidFlightNumberParameter)
{

	ASSERT_THROW(Depart d2("A21634","AIR FRANCE","20:00","PARIS","17:15","X47"), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid airline name.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided airline name is invalid.
 */
TEST(Depart, InvalidCompanyParameter)
{

	ASSERT_THROW(Depart d2("AC1634","AIR FRANCE44","20:00","PARIS","17:15","X47"), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid departure time.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided departure time is invalid.
 */
TEST(Depart, InvalidHourParameter)
{

	ASSERT_THROW(Depart d2("AC1634","AIR FRANCE","20:70","PARIS","17:15","X47"), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid destination city.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided destination city is invalid.
 */
TEST(Depart, InvalidCityParameter)
{

    ASSERT_THROW(Depart d2("AC1634","AIR FRANCE","20:00","_Paris_","17:15","X47"), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid boarding hour.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided boarding hour is invalid.
 */
TEST(Depart, InvalidBoardingHourParameter)
{

	ASSERT_THROW(Depart d2("AC1634","AIR FRANCE","20:00","PARIS","47:15","X47"), PreconditionException);
}

/**
 * \brief Test of the constructor with an invalid boarding gate number.
 *
 * This test verifies that the constructor throws a PreconditionException
 * when the provided boarding gate number is invalid.
 */
TEST(Depart, InvalidBoardingGateParameter)
{

	ASSERT_THROW(Depart d2("AC1634","AIR FRANCE","20:00","PARIS","17:15","147"), PreconditionException);
}



/**
 * \brief Test fixture for methods of the Depart class.
 */
class TheDepart : public ::testing::Test
{
public:
    /**
     * \brief Initialization of a Depart object for testing.
     */
  TheDepart():
  f_depart ("AC1636","AIR CANADA","18:00","ORLONDO","17:15","C86"){};
  Depart f_depart; ///< Depart object for testing..
  
};

/**
 * \brief Test of the boarding gate assignment with a valid value.
 */
TEST_F(TheDepart, ValidBoardingGateAssignment)
{
  f_depart.setBoardingGate("T95");
  ASSERT_EQ("T95", f_depart.getBoardingGate ());
}

/**
 * \brief Test of the boarding gate assignment with an invalid value.
 */
TEST_F(TheDepart, InvalidBoardingGateAssignment)
{
  ASSERT_THROW(f_depart.setBoardingGate("t00"), PreconditionException);
}


/**
 * \brief Test of the boarding hour assignment with a valid value.
 */
TEST_F(TheDepart, ValidBoardingHourAssignment)
{
  f_depart.setBoardingHour("18:18");
  ASSERT_EQ("18:18", f_depart.getBoardingHour ());
}

/**
 * \brief Test of the boarding hour assignment with an invalid value.
 */
TEST_F(TheDepart, InvalidBoardingHourAssignment)
{
  ASSERT_THROW(f_depart.setBoardingHour("40:00"), PreconditionException);
}

/**
 * \brief Test of the getBoardingGate() method.
 *
 * This test verifies that the getBoardingGate() method returns the correct value.
 */
TEST_F(TheDepart, GetBoardingGate ){
  ASSERT_EQ("C86", f_depart.getBoardingGate ());
}

/**
 * \brief Test of the getBoardingHour() method.
 *
 * This test verifies that the getBoardingHour() method returns the correct value.
 */
TEST_F(TheDepart, GetBoardingHour){
  ASSERT_EQ("17:15", f_depart.getBoardingHour ());
}

/**
 * \brief Test of the getFlightFormatted() method.
 *
 * This test verifies that the getFlightFormatted() method returns the correctly formatted string.
 */
TEST_F(TheDepart, GetFormattedFlight)
{
  ASSERT_EQ("|AC1636|    AIR CANADA     |18:00|      ORLONDO      |17:15| C86 |",
            f_depart.getFlightFormatted ());
}


/**
 * \brief Test of the clone() method.
 *
 * This test verifies that the clone() method returns a correctly cloned Depart object.
 */

TEST_F(TheDepart, clone)
{
  auto pt_depart = f_depart.clone();
  ASSERT_EQ(f_depart.getFlightFormatted (), pt_depart->getFlightFormatted ());
}
