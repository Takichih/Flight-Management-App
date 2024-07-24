/**
 * \file ContratException.cpp
 * \brief Implementation of the ContratException class and its inheritors
 * \author Chih Taki-eddine
 * \date July 6, 2014
 */
#include "ContratException.h"
#include <sstream>

using namespace std;
/**
 * \brief Constructor for the base class ContratException
 * \param p_file String representing the source file where the error occurred
 * \param p_line Integer representing the line where the error occurred
 * \param p_expr Logical test that failed
 * \param p_msg Message describing the error
 */
ContratException::ContratException(std::string p_file, unsigned int p_line,
                                   std::string p_expr, std::string p_msg) :
    logic_error(p_msg), m_expression(p_expr), m_file(p_file), m_line(p_line)
{
}

/**
 * \brief Constructs the complete text related to the contract exception
 * \return A string corresponding to the exception
 */
std::string ContratException::reqExceptionText() const
{
    ostringstream os;
    os << "Message : " << what() << endl;
    os << "File    : " << m_file << endl;
    os << "Line    : " << m_line << endl;
    os << "Test    : " << m_expression << endl;

    return os.str();
}
/**
 * \brief Constructor for the AssertionException class
 * 
 * The public constructor AssertionException(...) initializes
 * its base class ContratException. There are no local attributes.
 * This class is useful for its TYPE when handling exceptions.
 *
 * \param p_file String representing the source file where the error occurred
 * \param p_line Integer representing the line where the error occurred
 * \param p_expr Logical test that failed
 */

AssertionException::AssertionException(std::string p_file, unsigned int p_line,
                                       std::string p_expr)
    : ContratException(p_file, p_line, p_expr, "ASSERTION ERROR")
{
}

/**
 * \brief Constructor for the PreconditionException class, initializing the base class ContratException.
 * 
 * This class represents a precondition error in contract theory.
 *
 * \param p_file String representing the source file where the error occurred
 * \param p_line Integer representing the line where the error occurred
 * \param p_expr Logical test that failed
 */
 PreconditionException::PreconditionException(std::string p_file, unsigned int p_line,
                                             std::string p_expr)
    : ContratException(p_file, p_line, p_expr, "PRECONDITION ERROR")
{
}

 /**
 * \brief Constructor for the PostconditionException class, initializing the base class ContratException.
 * 
 * This class represents a postcondition error in contract theory.
 *
 * \param p_file String representing the source file where the error occurred
 * \param p_line Integer representing the line where the error occurred
 * \param p_expr Logical test that failed
 */
PostconditionException::PostconditionException(std::string p_file, unsigned int p_line,
                                               std::string p_expr)
    : ContratException(p_file, p_line, p_expr, "POSTCONDITION ERROR")
{
}

/**
 * \brief Constructor for the InvariantException class, initializing the base class ContratException.
 * 
 * This class represents an invariant error in contract theory.
 *
 * \param p_file String representing the source file where the error occurred
 * \param p_line Integer representing the line where the error occurred
 * \param p_expr Logical test that failed
 */
InvariantException::InvariantException(std::string p_file, unsigned int p_line,
                                       std::string p_expr)
    : ContratException(p_file, p_line, p_expr, "INVARIANT ERROR")
{
}