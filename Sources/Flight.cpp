/**
 * \file   Flight.cpp
 * \brief  Implementation file for the Flight class.
 * \author Chih Taki-eddine
 * \date   June 24, 2024
 */
#include "Flight.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>

namespace aerien{
    using namespace std;
    /**
     * \brief Constructor for the Flight class.
     *
     * Initializes a Flight object with the given parameters.
     *
     * \param[in] p_number The flight number.
     * \param[in] p_company The airline company name.
     * \param[in] p_hour The departure time in 24-hour format.
     * \param[in] p_city The departure city of the flight.
     *
     * \pre util::isValidNumber(p_number) must return true.
     * \pre util::isValidName(p_company) must return true.
     * \pre util::isValid24Format(p_hour) must return true.
     * \pre util::isValidName(p_city) must return true.
     * \post The flight number, company name, departure time, and city are initialized with the specified values.
     */
     Flight::Flight (const string & p_number,const string & p_company,
             const string & p_hour,const string & p_city):
     m_number(p_number),m_company(p_company), m_hour(p_hour), m_city(p_city)
     {        
            PRECONDITION(util::isValidNumber(p_number));
            PRECONDITION(util::isValidName(p_company));
            PRECONDITION(util::isValid24Format(p_hour));
            PRECONDITION(util::isValidName(p_city));
            
            POSTCONDITION(m_number == p_number);
            POSTCONDITION(m_company == p_company);
            POSTCONDITION(m_hour == p_hour);
            POSTCONDITION(m_city == p_city);
                  
            INVARIANTS();
     }

    /**
     * \brief Sets a new departure time for the flight.
     *
     * Assigns a new value to the m_hour attribute of the flight. The departure time must be valid in 24-hour format.
     *
     * \param[in] p_hour The new departure time in 24-hour format.
     *
     * \pre util::isValid24Format(p_hour) must return true.
     * \post The departure time is updated only if the parameter is valid. Otherwise, a contract error will be generated.
     */     
     void Flight::setHour(const std::string & p_hour)
    {
        PRECONDITION(util::isValid24Format(p_hour)) 
        m_hour = p_hour;
        POSTCONDITION(m_hour == p_hour);
        INVARIANTS ();
    }

    /**
     * \brief Compares two Flight objects for equality.
     *
     * Two flights are considered equal if their flight numbers are identical.
     *
     * \param[in] p_flight The Flight object to compare with the current object.
     * \return true if the flight numbers are the same; false otherwise.
     */
    bool Flight::operator == (const Flight& p_flight ) const
    {
        return m_number==p_flight.m_number;
    }

    /**
     * \brief Returns a formatted string representing the flight information.
     *
     * Creates and returns a string containing the flight information formatted as:
     * |number|company|hour|city|.
     * The company name and city are adjusted in width for consistent formatting.
     *
     * \return A formatted string representing the flight information.
     */
    string Flight::getFlightFormatted() const{
        ostringstream oss;

        oss << "|" << m_number << "|" <<util::adjustWidth(m_company);
        oss << "|" << m_hour <<"|" <<util::adjustWidth(m_city)<< "|" ;

        return oss.str();
    }
    
    /**
     * \brief Returns the flight number.
     *
     * \return A constant reference to the string representing the flight number.
     */
    const string & Flight::getNumber()const{
      return m_number;
    }

    /**
     * \brief Returns the airline company name.
     *
     * \return A constant reference to the string representing the airline company name.
     */
    const string & Flight::getCompany()const{
      return m_company;
    }

    /**
     * \brief Returns the departure time of the flight.
     *
     * \return A constant reference to the string representing the departure time.
     */
    const string & Flight::getHour()const{
      return m_hour;
    }


    /**
     * \brief Returns the departure city of the flight.
     *
     * \return A constant reference to the string representing the departure city.
     */
    const string & Flight::getCity()const{
      return m_city;
    }
    

    /**
     * \brief Checks the invariant of the Flight class.
     *
     * Verifies that the invariants of the Flight class are respected. The checked invariants are:
     * - The flight number (m_number) is valid using util::isValidNumber().
     * - The airline company name (m_company) is valid using util::isValidName().
     * - The departure time (m_hour) is valid using util::isValid24Format().
     * - The departure city (m_city) is valid using util::isValidName().
     *
     * \pre This method is designed for use during the invariant verification of the Flight class.
     * \post No modification is made to the state of the Flight object.
     * \return No data is returned.
     */
    void Flight::verifieInvariant() const
    {
        INVARIANT(util::isValidNumber(m_number));
        INVARIANT(util::isValidName(m_company));
        INVARIANT(util::isValid24Format(m_hour));
        INVARIANT(util::isValidName(m_city));         
    }
}