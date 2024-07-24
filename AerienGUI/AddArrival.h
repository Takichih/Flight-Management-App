/**
 * @file   AddArrival.h
 * @brief  File containing the declaration of the AddArrival class, which inherits from QDialog.
 * @author Chih Taki-eddine
 * @date   July 7, 2024
 */

#ifndef _ADDARRIVAL_H
#define _ADDARRIVAL_H

#include "ui_AddArrival.h"

class AddArrival : public QDialog
{
  Q_OBJECT
public:
  AddArrival ();
        const std::string getNumber()const;
        const std::string getCompany()const;
        const std::string getHour()const;
        const std::string getCity()const;
        const std::string getStatus()const;
        
  virtual ~AddArrival(){};
  
  private slots:
    void slotConfirmeArrival();
    
private:
  Ui::AddArrival widget;
};

#endif /* _ADDARRIVAL_H */
