/**
 * \file   Airport.cpp
 * \brief  File containing the declaration of the Airport class
 * \author Chih Taki-eddine
 * \date   Jully 23, 2024
 */

#include "Airport.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "Arrival.h"
#include "Depart.h"
#include <algorithm>
#include <vector>
#include <sstream>
#include "FlightException.h"

namespace aerien{
    using namespace std;

    /**
     * \brief Constructor of the Airport class with code validation.
     *
     * \param[in] p_code The code of the airport to create.
     * \pre The parameter should not be empty.
     * \pre isValideCode(p_code) must return true.
     */

    Airport::Airport (const std::string& p_code): m_code(p_code) 
    { PRECONDITION(p_code != "");
      PRECONDITION(util::isValideCode(p_code));
      POSTCONDITION(m_code == p_code);
      INVARIANTS ();
    }

    /**
     * \brief Copy constructor of the Airport class.
     *
     * \param[in] p_Airport The Airport object to copy.
     * \post A deep copy of the flights is made.
     */
    Airport::Airport (const Airport& p_Airport): m_code(p_Airport.m_code){ 
      for (const auto & element : p_Airport.m_flights){
          addFlight(*element);
        }
      INVARIANTS ();
    }

    /**
     * \brief Assignment operator for the Airport class.
     *
     * \param[in] p_Airport The Airport object to assign.
     * \return A reference to the assigned Airport object.
     * \post A deep copy of the flights is made.
     */
    const Airport& Airport::operator= (const Airport& p_Airport){
      if (this != &p_Airport)
        {
          m_code = p_Airport.m_code;
          m_flights.clear();
            for (const auto & element : p_Airport.m_flights)
              {
                addFlight(*element);
              }
        }
      INVARIANTS ();
      return *this;
    }

    /**
     * \brief Accessor to get the airport code.
     * \return A constant reference to the string containing the airport code.
     */
     const string & Airport::getCode()const{
       return m_code;
     }


    /**
     * \brief Adds a flight to the list of airport flights.
     *
     * \param[in] p_flight The flight to add.
     * \post A copy of the flight is added to the list of flights.
     */ 
    void Airport::addFlight(const Flight& p_flight){
      bool exist = false;
      
      for (auto iter=m_flights.begin(); iter<m_flights.end(); iter++)
        {
          if((**iter) == p_flight)
            {
              exist = true;
              break;
            }
        }
      if (exist)
        {
          throw FlightAlreadyExistsException("This flight already exists :\n" + p_flight.getNumber());
        }
      else
        {
          m_flights.push_back(p_flight.clone());
        }
      
    }
    
    /**
     * \brief Returns a formatted representation of all airport flights.
     *
     * This method generates and returns a formatted string representing
     * all airport flights, categorized into departures and arrivals.
     *
     * \return A formatted string representing the airport flights information.
     */
    string Airport::getAirportFormatted() const 
    {
        ostringstream osDeparture;
        ostringstream osArrival;

         // Add header for departures
        osDeparture << "Departure schedule\n";
        osDeparture << "------------------------------------------------------------------\n";
        osDeparture << "| FLIGHT  |  COMPANY       |HOUR|         CITY       |EMBRQ|GATE |\n";
        osDeparture << "------------------------------------------------------------------\n";    

        // Add header for arrivals    
        osArrival <<"Arrivals schedule\n";
        osArrival <<"----------------------------------------------------------------\n";
        osArrival <<"|FLIGHT|     COMPANY       |HOUR|        CITY        |  STATUT |\n";
        osArrival <<"----------------------------------------------------------------\n";

        for (const auto& Flight : m_flights) {
            string flight_Info = Flight->getFlightFormatted();
            if (flight_Info.length() == 66) 
            { 
                osDeparture << flight_Info << endl;
            } else if (flight_Info.length() == 64 || flight_Info.length() == 65 ) 
            { 
                osArrival << flight_Info << endl;
            }
        }

        // Add end line for departures
        osDeparture << "------------------------------------------------------------------\n";

        // Add end line for arrivals
        osArrival << "----------------------------------------------------------------\n";

        // Concatenate the two output streams
        ostringstream osFinal;
        osFinal << "Airport " << m_code << "\n\n";
        osFinal << osDeparture.str();
        osFinal << osArrival.str();

        return osFinal.str();
    }
    
    /**
     * \brief Checks the invariant of the Airport class.
     *
     * This method verifies that the invariant of the Airport class is respected.
     * The invariant verified is that the airport code (m_code) is valid.
     * The function util::isValideCode() is used to check if m_code meets the conditions of a valid code.
     *
     * \pre This method is designed to be used when verifying the invariant of the Airport class.
     * \post No modification is made to the state of the Airport object.
     * \return No data is returned.
     *
     * \see util::isValideCode
     */
        void Airport::verifieInvariant() const
        {
            INVARIANT(util::isValideCode(m_code));
        }
        

    /**
     * \brief Deletes a flight from the airport based on its flight number.
     * 
     * This function iterates over the vector of unique pointers to Flight objects (`m_flights`).
     * It compares the flight number of each Flight object with the provided flight number (`p_number`).
     * If a match is found, the corresponding Flight object is removed from the vector.
     * 
     * \param[in] p_number The flight number of the flight to delete.
     * \pre isValideNumero(p_number) must return true.
     * \post The flight is removed from the list if it exists.
     * \throws VolAbsentException if the flight does not exist.
     * 
     * \note This function uses std::unique_ptr for managing Flight objects.
     */
    void Airport::deleteFlight(const std::string& p_number)
    {   
        PRECONDITION(util::isValidNumber(p_number))
        bool Exist = false;

            for (auto iter = m_flights.begin(); iter != m_flights.end(); ) 
            {
                const std::unique_ptr<Flight>& ptrFlight = *iter;

                if (ptrFlight->getNumber() == p_number) 
                    {
                        iter = m_flights.erase(iter); 
                        Exist = true;
                    } 
                else 
                    {
                        ++iter; // Incrémente l'itérateur seulement si aucun vol n'est supprimé
                    }
            }
        if (!Exist) 
        {
            throw FlightAbsentException("This Flight doesn't exist."); 
        }
    }
}


