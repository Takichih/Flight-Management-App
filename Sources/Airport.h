/**
 \file Airport.h
 \brief File containing the declaration of the Airport class
 * \author Chih Taki-eddine
 * \date June 24, 2024
 */
#ifndef AIRPORT_H
#define AIRPORT_H

#include <memory>
#include <vector>
#include "Flight.h"


namespace aerien{
    /**
     * \class Airport
     * \brief Class representing an airport with its associated flights.
     */
    class Airport
    {
    public:
      Airport (const std::string& p_code);
      Airport (const Airport& p_airport);
      const Airport& operator= (const Airport& p_airport);
      const std::string & getCode()const;
      void addFlight(const Flight& p_flight);
      
      void deleteFlight (const std::string& p_number); 
      
      virtual std::string getAirportFormatted()const;

    private:
      void verifieInvariant() const;
      std::string m_code;
      std::vector<std::unique_ptr<Flight>> m_flights;
  
    };
      
}

#endif /* AIRPORT_H */

