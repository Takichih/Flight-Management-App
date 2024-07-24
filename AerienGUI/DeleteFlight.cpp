/**
 * \file   DeleteFlight.cpp
 * \brief  File containing the implementation of the DeleteFlight class, which inherits from QDialog.
 * \author Chih Taki-eddine
 * \date   July 7, 2024
 */

#include "DeleteFlight.h"
#include <string>


#include "FlightException.h"
#include "validationFormat.h"
#include <QMessageBox>
using namespace std;
using namespace aerien;
using namespace util;

/**
 * \brief Constructor for the DeleteFlight class.
 * 
 * Initializes the user interface defined in `ui_DeleteFlight.h`.
 */
DeleteFlight::DeleteFlight()
    {
        widget.setupUi (this);
    }

/**
 * \brief Gets the flight number to be deleted.
 * 
 * \return The flight number entered by the user as a string.
 */
const string  DeleteFlight::getNumberDelete()const
    {
        return widget.lineNumber->text().toStdString();
    }

/**
 * \brief Slot to delete the flight.
 * 
 * This slot is called when the user clicks the "Delete" button.
 * It performs validation of the flight number format and closes the
 * dialog if the format is valid. Displays an error message if the format
 * is invalid.
 */
void DeleteFlight::slotDelete() 
{
  bool Valide = true;
  try
    {
      if (!isValidNumber(getNumberDelete()))
        {
            throw FlightException("The format entered for the flight number is invalid.\n "
                    "This format must be respected: AA1111");
        }
    }
  catch (FlightException &e)
    {
        QString message = (e.what());
        QMessageBox::information(this, "ERREUR", message);
        Valide = false;
    }
    if (Valide)
    {
        accept();
    }
}

/**
 * \brief Virtual destructor for the DeleteFlight class.
 */
DeleteFlight::~DeleteFlight() { }