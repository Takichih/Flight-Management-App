/**
 * \file   Airport_Table.cpp
 * \brief  File containing the implementation of the Airport_Table class, which inherits from QMainWindow.
 * \author Chih Taki-eddine
 * \date   July 7, 2024
 */
#include "Arrival.h"
#include "Depart.h"
#include "Airport_Table.h"
#include "FlightException.h"
#include "AddArrival.h"
#include "AddDeparture.h"
#include "DeleteFlight.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace aerien;

/**
 * \brief Constructor for the Airport_Table class.
 * 
 * Initializes the user interface defined in `ui_Airport_Table.h` and
 * initializes the airport and flight data.
 */
Airport_Table::Airport_Table () : m_air("YUL")
{
   /* m_aero.ajouterVol(Arrivee("LH0472","LUFTHANSA","22:05","MUNICH"," Retardé "));
    m_aero.ajouterVol(Depart("AC1636","AIR CANADA","18:00","ORLONDO","17:15","C86"));
    m_aero.ajouterVol(Arrivee("RJ0271","ROYAL JORDANIAN","07:12","AMMAN"," Atterri "));
    m_aero.ajouterVol(Depart("DL5064","DELTA","16:05","NEW YORK","15:30","C88"));
    m_aero.ajouterVol(Depart("AF0345","AIR FRANCE","17:00","PARIS","16:15","E50"));
    m_aero.ajouterVol(Depart("BA0094","BRITISH AIRWAYS","22:15","LONDRES","21:30","A57"));
    m_aero.ajouterVol(Depart("QR0764","QATAR AIRWAYS","21:35","DOHA","21:00","A55"));
    m_aero.ajouterVol(Arrivee("WS0214","WESTJEST","00:34","CALGARY","À l'heure"));
    m_aero.ajouterVol(Depart("TS0820","AIR TRANSAT","06:45","ATLANTA","06:00","C85"));
    m_aero.ajouterVol(Arrivee("AC0424","AIR CANADA","20:41","TORONTO"," Atterri "));
    m_aero.ajouterVol(Depart("WG6544","SUNWING","07:00","CAYO COCO","06:30","A59"));
    m_aero.ajouterVol(Arrivee("UA3647","UNITED AIRLINES","21:06","CHIGAGO","À l'heure"));
    m_aero.ajouterVol(Depart("AA5679","AMERICAN AIRLINES","07:29","CHARLOTTE","07:00","C81"));

   */
    widget.setupUi (this);
    
    // Initial display of airport information in the interface
    widget.textEditAir->setPlainText (m_air.getAirportFormatted ().c_str());
}

/**
 * \brief Slot that handles the addition of a departure flight.
 * 
 * Opens the AddDeparture dialog, retrieves the input data, and adds
 * a departure flight to the airport. Displays an error message if the
 * flight already exists.
 */
void Airport_Table::slotDeparture()
{
    AddDeparture dGUI;
    if (dGUI.exec())
    {
        try
        {
            Depart unDepart(dGUI.getNumber(), dGUI.getCompany(), dGUI.getHour(), dGUI.getCity(),
                            dGUI.getBoardingHour (), dGUI.getBoardingGate ());
            m_air.addFlight(unDepart);

        }
        catch (FlightAlreadyExistsException &e)
        {
            QString message = (e.what());
            QMessageBox::information(this, "ERREUR", message);
        }

        widget.textEditAir->setPlainText(m_air.getAirportFormatted ().c_str());
    }
}


/**
 * \brief Slot that handles the addition of an arrival flight.
 * 
 * Opens the AddArrival dialog, retrieves the input data, and adds
 * an arrival flight to the airport. Displays an error message if the
 * flight already exists.
 */
void Airport_Table::slotArrival(){
  AddArrival aGUI;
  if (aGUI.exec()){
      try
        {
          aerien::Arrival unArrivee(aGUI.getNumber (), aGUI.getCompany (),
                                    aGUI.getHour (), aGUI.getCity (), aGUI.getStatus());
          
          m_air.addFlight(unArrivee);
        }catch(FlightAlreadyExistsException &e)
          {
            QString message = (e.what());
            QMessageBox::warning (this, "ERREUR", message);
          }
        widget.textEditAir -> setPlainText(m_air.getAirportFormatted ().c_str());       
    };
}

/**
 * \brief Slot that handles the deletion of a flight.
 * 
 * Opens the DeleteFlight dialog, retrieves the flight number to delete,
 * and attempts to remove the flight from the airport. Displays an error
 * message if the flight does not exist.
 */
void Airport_Table::slotDeleteFlight()
{ 
    DeleteFlight dGUI;
    if (dGUI.exec())
    { 
        try
        {
            m_air.deleteFlight (dGUI.getNumberDelete ());
        }
        catch(FlightAbsentException &e)
        {
            QString message = (e.what());
            QMessageBox::critical (this, "ERREUR", message);
        }
    };
    widget.textEditAir -> setPlainText(m_air.getAirportFormatted ().c_str());     
}
