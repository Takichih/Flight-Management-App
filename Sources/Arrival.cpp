/**
 * \file   Arrivee.cpp
 * \brief  File containing the implementation of the methods of the Arrival class
 * \author Chih Taki-eddine
 * \date   June 24, 2024
 */

#include "Arrival.h"
#include "Flight.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <sstream>
namespace aerien{
    using namespace std;

    
    /**
     * \brief Constructor of the Arrival class with status validation.
     *
     * \param[in] p_number The flight number.
     * \param[in] p_company The airline company.
     * \param[in] p_hour The flight hour.
     * \param[in] p_city The city of origin or destination.
     * \param[in] p_status The status of the arrival.
     * \pre isValidStatus(p_status) must return true.
     * \post m_status is set to p_status.
     */
    Arrival::Arrival (const std::string & p_number, const std::string & p_company,
             const std::string & p_hour, const std::string & p_city, const std::string& p_status):
                        Flight(p_number, p_company, p_hour, p_city),m_status(p_status)
    {
      PRECONDITION(util::isValidStatus (p_status) );
      POSTCONDITION(m_status == p_status);
      INVARIANTS ();
    }

     /**
     * \brief Sets the status of the arrival.
     *
     * \param[in] p_status The new status of the arrival.
     * \pre isValidStatus(p_status) must return true.
     * \post m_status is set to p_status.
     */
    void Arrival::setStatus(const std::string& p_status)
    {
        PRECONDITION(util::isValidStatus (p_status));
        m_status = p_status;
        POSTCONDITION(m_status == p_status);
        INVARIANTS ();
    }


     /**
     * \brief Gets the status of the arrival.
     * \return A constant reference to the status string.
     */
    const string& Arrival::getStatus()const
    {
        return m_status;
    }


    /**
     * \brief Returns a formatted representation of the arrival flight.
     *
     * This method generates and returns a formatted string representing
     * the arrival flight information, including the status.
     *
     * \return A formatted string representing the arrival flight information.
     */
    string Arrival::getFlightFormatted()const
    {
        ostringstream os;
        os << Flight::getFlightFormatted()<<m_status<<"|";
        return os.str(); 
    }
    
    /**
     * \brief Clones the Arrival object.
     *
     * This method creates and returns a unique pointer to a new Arrival object
     * that is a copy of the current object.
     *
     * \return A unique pointer to the cloned Arrival object.
     */
    unique_ptr<Flight> Arrival::clone ()const
    {
        return make_unique <Arrival> (*this); 
    }
        
    /**
     * \brief Checks the invariant of the Arrival class.
     *
     * This method verifies that the invariant of the Arrival class is respected.
     * The invariant verified is that the status (m_status) is valid.
     * The function util::isValidStatus() is used to check if m_status meets the conditions of a valid status.
     *
     * \pre This method is designed to be used when verifying the invariant of the Arrival class.
     * \post No modification is made to the state of the object.
     * \return No data is returned.
     *
     * \see util::isValidStatus
     */
    void Arrival::verifieInvariant() const
    {
        INVARIANT(util::isValidStatus (m_status));
    }

 
}

