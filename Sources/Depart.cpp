/**
 * \file   Depart.cpp
 * \brief  File containing the implementation of the methods of the Depart class
 * \author Chih Taki-eddine
 * \date June 24, 2024
 */
#include "Depart.h"
#include "Flight.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>
namespace aerien{
    using namespace std;

    /**
     * \brief Constructor of the Depart class.
     *
     * This constructor initializes a Depart object representing a departure flight with the specified information.
     *
     * \param[in] p_number The flight number.
     * \param[in] p_company The airline company name.
     * \param[in] p_hour The departure time in 24-hour format.
     * \param[in] p_city The departure city of the flight.
     * \param[in] p_boardingHour The boarding time in 24-hour format.
     * \param[in] p_boardingGate The boarding gate for the flight.
     *
     * \pre util::isValidGate(p_boardingGate) must return true.
     * \pre util::isValid24Format(p_boardingHour) must return true.
     * \post The boarding gate and boarding time are initialized with the specified values.
     */
    Depart::Depart (const string & p_number,const string & p_company,const string & p_hour,const string & p_city,
                    const string& p_boardingHour,const string& p_boardingGate):
                    Flight(p_number, p_company, p_hour, p_city),
                    m_boardingHour(p_boardingHour),m_boardingGate(p_boardingGate)
    {
      PRECONDITION(util::isValidGate(p_boardingGate));
      PRECONDITION(util::isValid24Format(p_boardingHour));
      POSTCONDITION(m_boardingHour == p_boardingHour);
      POSTCONDITION(m_boardingGate == p_boardingGate);
      INVARIANTS();
    }


 /**
     * \brief Sets the boarding gate for the departure flight.
     *
     * \param[in] p_boardingGate The new boarding gate.
     */
    void Depart::setBoardingGate (const std::string& p_boardingGate){
      PRECONDITION(util::isValidGate(p_boardingGate));
      m_boardingGate = p_boardingGate;
      POSTCONDITION(m_boardingGate==p_boardingGate);
      INVARIANTS ();
    }


    /**
     * \brief Sets the boarding time for the departure flight.
     *
     * \param[in] p_boardingHour The new boarding time.
     */
    void Depart::setBoardingHour (const std::string& p_boardingHour){
      PRECONDITION(util::isValid24Format(p_boardingHour));
      m_boardingHour=p_boardingHour;
      POSTCONDITION(m_boardingHour==p_boardingHour);
      INVARIANTS ();
    }


   /**
     * \brief Accessor to get the boarding gate of the departure flight.
     *
     * \return A constant reference to the string containing the boarding gate.
     */
    const string& Depart::getBoardingGate () const{
      return m_boardingGate;
    }

    /**
     * \brief Accessor to get the boarding time of the departure flight.
     *
     * \return A constant reference to the string containing the boarding time.
     */
    const string& Depart::getBoardingHour () const{
      return m_boardingHour;
    }

    /**
     * \brief Returns a formatted representation of the departure flight.
     *
     * \return A formatted string representing the information of the departure flight.
     */
    string Depart::getFlightFormatted() const{
      ostringstream os;
      os << Flight::getFlightFormatted()<<m_boardingHour<<"| "<< m_boardingGate<< " |";
      return os.str();
    }


    /**
     * \brief Clone method to create a copy of the Depart object.
     *
     * \return A unique pointer to a copy of the Depart object.
     */
    unique_ptr<Flight> Depart::clone() const{
        return make_unique <Depart> (*this); 
    }
    
    /**
     * \brief Checks the invariant of the Depart class.
     *
     * This method checks that the invariants of the Depart class are respected.
     * It also inherits the invariants checked by the Flight class through the call
     * to Flight::checkInvariant().
     * The checked preconditions are:
     * - The validity of the boarding gate (m_boardingGate) is verified
     *   using util::isValidGate().
     * - The validity of the format of the boarding time (m_boardingHour) is verified
     *   using util::isValid24Format().
     *
     * \pre This method is designed to be used during the verification
     *      of the invariant of the Depart class.
     * \post No modification is made to the state of the Depart object.
     * \return No data is returned.
     */
    void Depart::verifieInvariant() const{
        INVARIANT(util::isValidGate(m_boardingGate));
        INVARIANT(util::isValid24Format(m_boardingHour));
    }
}








