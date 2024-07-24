/**
 \file Flight.h
 \brief File containing the Flight class declaration and its method prototypes.
 * \author Chih Taki-eddine
 * \date June 24, 2024
 */

#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <memory>

namespace aerien{
    /**
     \class Flight
     * \brief Class representing an air flight.
     *
     * This class models a flight with a number, an airline, a departure time and a destination city.
     */
    class Flight
    {
    public:
        Flight (const std::string & p_number,const std::string & p_company,
             const std::string & p_hour,const std::string & p_city);

        const std::string & getNumber()const;
        const std::string & getCompany()const;
        const std::string & getHour()const;
        const std::string & getCity()const;
        void setHour(const std::string & p_hour);
        bool operator == (const Flight& p_flight )const;
        virtual std::string getFlightFormatted() const;
        virtual std::unique_ptr<Flight> clone ()const = 0;   
        virtual ~Flight (){};
         
        
    private:      
      std::string m_number;
      std::string m_company;
      std::string m_hour;
      std::string m_city;
      
      void verifieInvariant() const;

    };
}
#endif /* FLIGHT_H */

