/**
 * @file   AddDeparture.h
 * @brief  File containing the declaration of the AddDeparture class, which inherits from QDialog.
 * @author Chih Taki-eddine
 * @date   July 7, 2024
 */

#ifndef _ADDDEPARTURE_H
#define _ADDDEPARTURE__H

#include "ui_AddDeparture.h"

/**
 * @class AddDeparture
 * @brief This class manages the addition of departures in a user interface.
 *        It inherits from QDialog and also ensures that all entered values
 *        are valid.
 */
class AddDeparture : public QDialog
{
    Q_OBJECT
public:
    AddDeparture();
    
    virtual ~AddDeparture(){};
    
    std::string getNumber() const;
    std::string getCompany() const;
    std::string getHour() const;
    std::string getCity() const;
    std::string getBoardingGate()const;
    std::string getBoardingHour()const;
    
    private slots:
        void slotConfirmeDeparture();
private:
    Ui::AddDeparture widget;
};

#endif /* _ADDDEPARTURE__H */
