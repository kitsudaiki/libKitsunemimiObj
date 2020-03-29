/**
 *  @file    objParserInterface.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef JINJA2PARSERINTERFACE_HH
#define JINJA2PARSERINTERFACE_HH

#include <vector>
#include <string>
#include <jsonItems.hpp>

#include <iostream>

namespace Kitsune
{
namespace Obj
{
class location;

class ObjParserInterface
{

public:
    ObjParserInterface(const bool traceParsing);

    // connection the the scanner and parser
    void scan_begin(const std::string &inputString);
    void scan_end();
    bool parse(const std::string &inputString);

    // output-handling
    void setOutput(Json::JsonObject *output);
    Json::JsonObject *getOutput() const;

    // Error handling.
    void error(const Kitsune::Obj::location &location,
               const std::string& message);
    std::string getErrorMessage() const;

private:
    Json::JsonObject* m_output;
    std::string m_errorMessage = "";
    std::string m_inputString = "";

    bool m_traceParsing = false;
};

}  // namespace Obj
}  // namespace Kitsune

#endif // JINJA2PARSERINTERFACE_HH
