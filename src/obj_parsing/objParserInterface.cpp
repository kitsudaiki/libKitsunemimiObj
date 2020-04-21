/**
 *  @file    objParserInterface.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include <obj_parsing/obj_parserInterface.h>
#include <objparser.h>
#include <obj_converter.h>

# define YY_DECL \
    Kitsunemimi::Obj::ObjParser::symbol_type objlex (Kitsune::Obj::ObjParserInterface& driver)
YY_DECL;

namespace Kitsunemimi
{
namespace Obj
{

/**
 * The class is the interface for the bison-generated parser.
 * It starts the parsing-process and store the returned values.
 */
ObjParserInterface::ObjParserInterface(const bool traceParsing)
{
    m_traceParsing = traceParsing;
}

/**
 * Start the scanner and parser
 *
 * @return true, if parsing was successful, else false
 */
bool
ObjParserInterface::parse(const std::string &inputString)
{
    // init global values
    m_inputString = inputString;
    m_errorMessage = "";
    m_output = nullptr;

    // run parser-code
    this->scan_begin(inputString);
    Kitsunemimi::Obj::ObjParser parser(*this);
    int res = parser.parse();
    this->scan_end();

    if(res != 0) {
        return false;
    }
    return true;
}

/**
 * Is called for the parser after successfully parsing the input-string
 */
void
ObjParserInterface::setOutput(Json::JsonObject *output)
{
     m_output = output;
}

/**
 * getter for the json-output of the parser
 *
 * @return parser-output as Json::JsonObject
 */
Json::JsonObject*
ObjParserInterface::getOutput() const
{
    return m_output;
}

/**
 * Is called from the parser in case of an error
 *
 * @param message error-specific message from the parser
 */
void
ObjParserInterface::error(const Kitsunemimi::Obj::location& location,
                          const std::string& message)
{
    // get the broken part of the parsed string
    const uint32_t errorStart = location.begin.column;
    const uint32_t errorLength = location.end.column - location.begin.column;
    const std::string errorStringPart = m_inputString.substr(errorStart, errorLength);

    // build error-message
    m_errorMessage =  "error while parsing obj-template \n";
    m_errorMessage += "parser-message: " + message + " \n";
    m_errorMessage += "line-number: " + std::to_string(location.begin.line) + " \n";
    m_errorMessage += "position in line: " + std::to_string(location.begin.column) + " \n";
    m_errorMessage += "broken part in template: \"" + errorStringPart + "\" \n";
}

/**
 * getter fot the error-message in case of an error while parsing
 *
 * @return error-message
 */
std::string
ObjParserInterface::getErrorMessage() const
{
    return m_errorMessage;
}

}  // namespace Obj
}  // namespace Kitsune
