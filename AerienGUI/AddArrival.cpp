/**
 * \file   AddArrival.cpp
 * \brief  File containing the implementation of the AddArrival class, used for adding an arrival flight.
 * \author Chih Taki-eddine
 * \date   July 7, 2024
 */

#include "AddArrival.h"
#include "FlightException.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace std;
using namespace aerien;
using namespace util;


/**
 * \brief Default constructor for the AddArrival class.
 */
AddArrival::AddArrival ()
{
  widget.setupUi (this);
}

/**
 * \brief Retrieves the flight number from the input field.
 * \return The flight number as a std::string.
 */
const string  AddArrival::getNumber()const{
  return widget.lineEditNumber->text ().toStdString();
}

/**
 * \brief Retrieves the company name from the input field.
 * \return The company name as a std::string.
 */
const string  AddArrival::getCompany()const{
  return widget.lineEditCompany->text ().toStdString();
}

/**
 * \brief Retrieves the hour from the input field.
 * \return The hour as a std::string.
 */
const string  AddArrival::getHour()const{
  return widget.lineEditHour->text ().toStdString();
}

/**
 * \brief Retrieves the city from the input field.
 * \return The city as a std::string.
 */
const string  AddArrival::getCity()const{
  return widget.lineEditCity->text ().toStdString();
}

/**
 * \brief Retrieves the status from the input field.
 * \return The status as a std::string.
 */
const string AddArrival::getStatus()const{
  return widget.lineEditStatus->text ().toStdString();
}

/**
 * \brief Slot that handles the confirmation of arrival flight data.
 * 
 * This method validates the input data for the arrival flight. If the data is valid, it accepts the input. 
 * If any validation fails, it displays an error message using QMessageBox.
 */
void AddArrival::slotConfirmeArrival(){
  bool ValidFormat = true;
    
    try
    {
        if (!isValidNumber(getNumber()))
        {
            throw FlightException("The format entered for the flight number is invalid..\n "
                    "This format must be respected: AA1111");
        }
        
        if (!isValidName(getCompany()))
        {
            throw FlightException("The format entered for the company name is invalid.\n "
                    "it only takes capital letters\n "
                    "(Minimum length 3, maximum 19)\n "
                    "and no number.");
        }
        
        if (!isValid24Format(getHour()))
        {
            throw FlightException("The format entered for the start time is invalid.\n "
                    "It takes the 24-hour format, written like this: 15:01 or 05:15");
        }
        
        if (!isValidName(getCity()))
        {
            throw FlightException("The format entered for the city name is invalid.\n "
                    "it only takes capital letters\n "
                    "(Minimum length 3, maximum 19)\n "
                    "and no number.");
        }
        
        if (!isValidStatus (getStatus()))
        {
            throw FlightException("The format entered for the start time is invalid.\n "
                    " «  Atterri » : with 1 space at the beginning and at the end..\n"
                    " «  Retardé » with 1 space at the beginning and end \n"
                    " «À l'heure»: without spaces at the end.\n");
        }

    }
    catch (FlightException &e)
    {
        QString message = (e.what());
        QMessageBox::warning(this, "ERREUR", message);
        ValidFormat = false;
    }
    if (ValidFormat)
    {
        accept();
    }
}