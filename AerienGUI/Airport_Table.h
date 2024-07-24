/**
 * @file   Airport_Table.h
 * @brief  File containing the declaration of the Airport_Table class, which inherits from QMainWindow.
 * @author Chih Taki-eddine
 * @date 07 July 2024
 */

#ifndef _AIRPORT_TABLE_H
#define _AIRPORT_TABLE_H

#include "ui_Airport_Table.h"
#include "Airport.h"

/**
 * @class Airport_Table
 * @brief Main window of the airport management application.
 *
 * This class inherits from QMainWindow and manages the main interface of the application.
 * It allows the user to view and manage the flights of an airport.
 */
class Airport_Table : public QMainWindow
{
  Q_OBJECT // Permet de créer des widgets et des slots
  
public:
  Airport_Table ();
  
  virtual ~Airport_Table (){};
  
  
  private slots:
    void slotDeparture();
    void slotArrival();
    void slotDeleteFlight();
  
private:
  Ui::AirportTable widget;
  aerien::Airport m_air;
  std::vector<aerien::Flight> m_flights;

};
#endif /* _AIRPORT_TABLE_H */
