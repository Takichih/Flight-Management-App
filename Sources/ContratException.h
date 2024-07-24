/**
 * \file   ContratException.h
 * \brief  File containing the declaration of the ContratException class and its inheritors
 * \author Chih Taki-eddine
 * \date July 7, 2024
 */
#ifndef CONTRATEXCEPTION_H_DEJA_INCLU
#define CONTRATEXCEPTION_H_DEJA_INCLU

#include <string>
#include <stdexcept>

/**
 * \class ContratException
 * \brief Classe de base pour les exceptions de contrat.
 */
class ContratException: public std::logic_error
{
public:
    ContratException(std::string, unsigned int, std::string, std::string);
    ~ContratException() throw() {}
    std::string reqExceptionText() const;

private:
    std::string m_expression;
    std::string m_file;
    unsigned int m_line;
};

/**
 * \class AssertionException
 * \brief Class for handling assertion errors.
 */
class AssertionException : public ContratException
{
public:
    AssertionException(std::string, unsigned int, std::string);
};
/**
 * \class PreconditionException
 * \brief Class for handling precondition errors.
 */
class PreconditionException : public ContratException
{
public:
    PreconditionException(std::string, unsigned int, std::string);
};

/**
 * \class PostconditionException
 * \brief Class for handling postcondition errors.
 */
class PostconditionException : public ContratException
{
public:
    PostconditionException(std::string, unsigned int, std::string);
};

/**
 * \class InvariantException
 * \brief Class for handling invariant errors.
 */
class InvariantException : public ContratException
{
public:
    InvariantException(std::string, unsigned int, std::string);
};

// --- Definition of macros for contract theory control

#if !defined(NDEBUG)
// --- Debug mode

#  define INVARIANTS() \
      verifieInvariant()

#  define ASSERTION(f)     \
      if (!(f)) throw AssertionException(__FILE__, __LINE__, #f);
#  define PRECONDITION(f)  \
      if (!(f)) throw PreconditionException(__FILE__, __LINE__, #f);
#  define POSTCONDITION(f) \
      if (!(f)) throw PostconditionException(__FILE__, __LINE__, #f);
#  define INVARIANT(f)   \
      if (!(f)) throw InvariantException(__FILE__, __LINE__, #f);

// --- Release mode
#else

#  define PRECONDITION(f);
#  define POSTCONDITION(f);
#  define INVARIANTS();
#  define INVARIANT(f);
#  define ASSERTION(f);

#endif  // --- if !defined (NDEBUG)
#endif  // --- ifndef CONTRATEXCEPTION_H_ALREADY_INCLUDED