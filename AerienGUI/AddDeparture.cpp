/**
 * \file   AddDeparture.cpp
 * \brief  File containing the implementation of the AddDeparture class, used for adding a departure flight.
 * \author Chih Taki-eddine
 * \date   July 7, 2024
 */

#include "AddDeparture.h"
#include "validationFormat.h"
#include "FlightException.h"
#include <QMessageBox>

using namespace std;
using namespace aerien;
using namespace util;

/**
 * \brief Default constructor for the AddDeparture class.
 */
AddDeparture::AddDeparture()
{
    widget.setupUi(this);
}

/**
 * \brief Retrieves the flight number from the input field.
 * \return The flight number as a std::string.
 */
string AddDeparture::getNumber() const
{
    return widget.lineEditNumber->text ().toStdString();
}

/**
 * \brief Retrieves the company name from the input field.
 * \return The company name as a std::string.
 */
string AddDeparture::getCompany() const
{
    return widget.lineEditCompany->text ().toStdString();
}

/**
 * \brief Retrieves the departure hour from the input field.
 * \return The departure hour as a std::string.
 */
string AddDeparture::getHour() const
{
    return widget.lineEditHour->text ().toStdString();
}

/**
 * \brief Retrieves the city from the input field.
 * \return The city as a std::string.
 */
string AddDeparture::getCity() const
{
    return widget.lineEditCity->text ().toStdString();
}

/**
 * \brief Retrieves the boarding gate from the input field.
 * \return The boarding gate as a std::string.
 */
string AddDeparture::getBoardingGate() const
{
    return widget.lineEditBoardingGate->text ().toStdString();
}

/**
 * \brief Retrieves the boarding hour from the input field.
 * \return The boarding hour as a std::string.
 */
string AddDeparture::getBoardingHour() const
{
    return widget.lineEditBoardingHour->text ().toStdString();
}

/**
 * \brief Slot that handles the confirmation of departure flight data.
 * 
 * This method validates the input data for the departure flight. If the data is valid, it accepts the input. 
 * If any validation fails, it displays an error message using QMessageBox.
 */
void AddDeparture::slotConfirmeDeparture()
{
    bool Valide = true;
    
    try
    {
        if (!isValidNumber(getNumber()))
        {
            throw FlightException("The format entered for the flight number is invalid.\n "
                    "This format must be respected: AA1111");
        }
        
        if (!isValidName(getCompany()))
        {
            throw FlightException("The format entered for the company name is invalid.\n "
                    "It only takes capital letters\n "
                    "Minimum length 3, maximum 19\n "
                    "and no figures.");
        }
        
        if (!isValid24Format(getHour()))
        {
            throw FlightException("The format entered for the start time is invalid..\n "
                    "It takes the 24-hour format written this way: 15:01 or 05:15");
        }
        
        if (!isValidName(getCity()))
        {
            throw FlightException("The format entered for the city name is invalid..\n "
                    "It only takes capital letters\n "
                    "Minimum length 3, maximum 19\n "
                    "and no figures.");
        }
        
        if (!isValidGate(getBoardingGate()))
        {
            throw FlightException("The format entered for the door number is invalid.\n "
                    "This format must be respected: A11");
        }
        
        if (!isValid24Format(getBoardingHour()))
        {
            throw FlightException("The format entered for the boarding time is invalid.\n "
                    "It takes the 24-hour format written this way: 15:01 or 05:15");
        }
        
    }
    catch (FlightException &e)
    {
        QString message = (e.what());
        QMessageBox::warning(this, "ERREUR", message);
        Valide = false;
    }
    if (Valide)
    {
        accept();
    }
}
