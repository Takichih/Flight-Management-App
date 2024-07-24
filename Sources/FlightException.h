/**
 * \file FlightException.h
 \brief File containing flight exceptions.
 * \author Chih Taki-eddine
 * \date 07 July 2024
 */

#ifndef FLIGHTEXCEPTION_H
#define FLIGHTEXCEPTION_H
#include <string>
#include <stdexcept>


namespace aerien
{
  
    /**
     \class FlightException
     * Basic class for flight-related exceptions.
     *
     * This class inherits from std::runtime_error and is used for all
     * flight-specific exceptions.
     */
    class FlightException : public std::runtime_error
    {
        public:
        /**
         * VolException constructor.
         \param p_reason Reason for exception.
         */
        FlightException(const std::string & p_raison): std::runtime_error(p_raison){};
    };


    /**
     * \class FlightAlreadyExistsException
     * \brief Exception thrown when a flight already exists.
     *
     * This exception is used when the user attempts to add
     * a flight that is already present in the flight list.
     */
    class FlightAlreadyExistsException : public FlightException
    {
        public:
        /**
         * \brief Constructor for FlightAlreadyExistsException.
         * \param p_reason Reason for the exception.
         */ 
        FlightAlreadyExistsException(const std::string& p_raison): FlightException(p_raison){};
    };
    
    /**
    * \class FlightNotFoundException
    * \brief Exception thrown when a flight is missing.
    *
    * This exception is used when the user attempts to manipulate
    * or access a flight that is missing (e.g., the flight does not exist).
    */
    class FlightAbsentException : public FlightException
    {
        public:
        /**
        * \brief Constructor for FlightAbsentException.
        * \param p_reason Reason for the exception.
        */
        FlightAbsentException (const std::string& p_raison): FlightException(p_raison){};
    };


}
#endif /* FLIGHTEXCEPTION_H */

