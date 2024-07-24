/**
 * Depart.h file
 \brief File containing the declaration of the Depart class, which inherits from the Vol class.
 * \author Chih Taki-eddine
 * \date June 24, 2024
 */

#ifndef DEPART_H
#define DEPART_H
#include "Flight.h"

namespace aerien{
    /**
     * Departure class
     * Class representing a departure flight, derived from the Flight class.
     */
    class Depart : public Flight
    {
    public:
      Depart (const std::string & p_number, const std::string & p_company,
             const std::string & p_hour, const std::string & p_city, const std::string& p_boardingGate, const std::string& p_boardingHour);
      
      void setBoardingHour(const std::string& p_boardingHour);
      void setBoardingGate(const std::string& p_boardingGate);
      const std::string& getBoardingGate()const;
      const std::string& getBoardingHour()const;
      virtual std::string getFlightFormatted() const;
      virtual std::unique_ptr<Flight> clone() const;
      virtual ~Depart (){};
      
      
    private:
    
      std::string m_boardingGate;
      std::string m_boardingHour;
      void verifieInvariant() const;

    };
}
#endif /* DEPART_H */

