/**
 \file Arrival.h
 \brief File containing the declaration of the Arrival class
 * \author Chih Taki-eddine
 * \date June 24, 2024
 */
#include "Flight.h"
#ifndef ARRIVAL_H
#define ARRIVAL_H
namespace aerien
{

  /**
   * \class Arrival
   * \brief Classe représentant un vol d'arrivée, dérivée de la classe Vol.
   */
  class Arrival : public Flight
  {
  public:
    Arrival (const std::string & p_number, const std::string & p_company,
             const std::string & p_hour, const std::string & p_city, const std::string& p_status);

    void setStatus (const std::string& p_status);
    const std::string& getStatus ()const;
    virtual std::string getFlightFormatted ()const;
    virtual std::unique_ptr<Flight> clone ()const;

    virtual
    ~Arrival () { };

  private:
    std::string m_status;
    void verifieInvariant () const;
  };
}
#endif /* ARRIVAL_H */

