/**
 * \file validationFormat.h
 * \brief déclarations des fonctions de validation TP1 Aerien
 * \author Chih Taki-eddine
 * \date 2024-07-06
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include <string>
namespace util {
bool isValidNumber(const std::string& p_VolNumber);
bool isValid24Format(const std::string& p_Hour);
bool isValidGate(const std::string& p_gate);
bool isValidName(const std::string& p_name);
bool isValideCode(const std::string & p_code);
std::string  adjustWidth(const std::string& p_field, int p_width=19);
bool isValidStatus(const std::string& p_status);


}


#endif /* VALIDATIONFORMAT_H */

