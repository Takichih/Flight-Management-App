/**
 * @file   DeleteFlight.h
 * @brief  File containing the declaration of the DeleteFlight class, which inherits from QDialog.
 * @author Chih Taki-eddine
 * @date 07 July 2024
 */

#ifndef _DELETEFLIGHT_H
#define _DELETEFLIGHT_H


#include "ui_DeleteFlight.h"
#include <QWidget>
#include <QMessageBox>


/**
 * \class DeleteFlight
 * \brief Dialog window for deleting a flight.
 *
 * This class manages the user interface to allow the user
 * to enter a flight number to be deleted.
 */
class DeleteFlight : public QDialog
{
  Q_OBJECT
public:

  DeleteFlight ();
 
   
  const std::string getNumberDelete()const;
  

  virtual ~DeleteFlight ();
  
  
  const std::string getNumber()const;
   
  private slots:
   
    void slotDelete();
    
private:
  Ui::Delete_Flight widget;
 
};

#endif /* _DELETEFLIGHT_H */
