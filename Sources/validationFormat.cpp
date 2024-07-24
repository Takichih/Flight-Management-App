/**
 * \file   validationFormat.cpp
 * \brief  Definition of validation functions for the Aerien project.
 * \author Chih Taki-eddine
 * \date   July 6, 2024
 */
#include "validationFormat.h"
namespace util {
    using namespace std;
    /**
     * \brief Checks if a flight number is valid.
     *
     * A valid flight number must have exactly 6 characters:
     * - The first two characters must be uppercase letters.
     * - The next four characters must be digits.
     *
     * \param[in] p_VolNumber The flight number to be validated.
     * \return true if the flight number is valid, false otherwise.
     */
    bool isValidNumber(const std::string& p_VolNumber)
    {
      bool valideNumber = (p_VolNumber.length()==6); 
      valideNumber &= isupper(p_VolNumber[0]) && isupper(p_VolNumber[1]) ;
      for (int i = 2; i <6; i++)
        {
            valideNumber&=isdigit(p_VolNumber[i]) ;
        }
      return valideNumber;
    }

    /**
     * \brief Checks if a time string is valid in 24-hour format.
     *
     * A valid time string must be in the format "HH:MM", where:
     * - HH is between 00 and 23 (inclusive).
     * - MM is between 00 and 59 (inclusive).
     *
     * \param[in] p_hour The time string to be validated.
     * \return true if the time string is valid, false otherwise.
     */
    bool isValid24Format(const std::string& p_hour)
    {

    if (p_hour.length() != 5)
        return false;

    if (p_hour[2] != ':')
        return false;

    for (int i = 0; i < 5; ++i)
    {
        if (i == 2)
            continue; 

        if (!isdigit(p_hour[i]))
            return false;
    }

    int hours = std::stoi(p_hour.substr(0, 2));
    int minutes = std::stoi(p_hour.substr(3, 2));

    if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60)
        return false;

    return true;
    }

    /**
     * \brief Checks if a gate string is valid.
     *
     * A valid gate string must have exactly 3 characters:
     * - The first character must be an uppercase letter.
     * - The second and third characters must be digits.
     * - The gate number cannot be "00".
     *
     * \param[in] p_gate The gate string to be validated.
     * \return true if the gate string is valid, false otherwise.
     */
    bool isValidGate(const std::string& p_gate)
    {
      bool valideGate = (p_gate.length()==3); 
      valideGate&= isupper(p_gate[0]) && true ;
      valideGate&=isdigit(p_gate[1]) ;
      valideGate&=isdigit(p_gate[2]) ;
      valideGate&=!(p_gate[1]=='0'&&p_gate[2]=='0');
      return valideGate;
    }
    
    /**
     * \brief Checks if a name string is valid.
     *
     * A valid name must be between 3 and 19 characters long, start with an uppercase letter,
     * and only contain uppercase letters, hyphens, and spaces. Hyphens and spaces must
     * be followed by an uppercase letter and not appear consecutively or at the end.
     *
     * \param[in] p_name The name string to be validated.
     * \return true if the name string is valid, false otherwise.
     */
    bool isValidName (const string& p_name)
    {
      int longNom= p_name.length();
      if(longNom<3 || longNom>19 || !isupper(p_name[0]))
        return false;

      for (int i = 1; i < p_name.length (); i++)
        {
          if (!isalpha (p_name[i]))
            {
              if (p_name[i] == '-' || p_name[i] == ' ' )
                {
                  if (i == p_name.length () - 1 || p_name[i + 1] == '-' ||  p_name[i + 1] == ' ' || !isupper(p_name[i+1]))
                    return false;
                  i++;
                }
              else
                return false;
            }
          else if(!isupper(p_name[i]))
            return false;
        }
      return true;
    }

    /**
     * \brief Adjusts the width of a string to a specified width.
     *
     * Adds spaces to the left and/or right of the string to match the desired width.
     * Spaces are alternated between the left and right.
     *
     * \param[in] p_field The string to be adjusted.
     * \param[in] p_width The desired width of the string.
     * \return The adjusted string.
     */
    string  adjustWidth(const string& p_field, int p_width)
    {
      string adjustField = p_field;
      bool ajoutEspaceAGauche=false;
        while (adjustField.size()<(u_int)p_width)
          {
            if (ajoutEspaceAGauche)
                adjustField = " " + adjustField;
            else
                adjustField = adjustField + " ";

            ajoutEspaceAGauche=!ajoutEspaceAGauche;
          }         
      return adjustField;
    }

    /**
     * \brief Checks if a code string is valid.
     *
     * A valid code string must be exactly 3 characters long and consist of uppercase letters only.
     *
     * \param[in] p_code The code string to be validated.
     * \return true if the code string is valid, false otherwise.
     */
    bool isValideCode(const std::string & p_code){
      if (p_code.size() != 3 )
        return false;
      for (int i=0; i < p_code.size(); i++){
         if (islower(p_code[i]) || isdigit(p_code[i]))
            {
              return false;
            }
        }
      return true;
    }

    /**
     * \brief Checks if a status string is valid.
     *
     * A valid status string must be one of the following:
     * - " Atterri "
     * - " Retardé "
     * - "À l'heure"
     *
     * \param[in] p_status The status string to be validated.
     * \return true if the status string is valid, false otherwise.
     */    
    bool isValidStatus(const std::string& p_status){
        { 
          return (p_status == " Atterri " || p_status == " Retardé " || p_status == "À l'heure");
        }
    }
}