/**
 *  @file    objParserInterface.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef OBJPARSERINTERFACE_HH
#define OBJPARSERINTERFACE_HH

#include <vector>
#include <string>

#include <iostream>

namespace Kitsunemimi
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
    void error(const Kitsunemimi::Obj::location &location,
               const std::string& message);
    std::string getErrorMessage() const;

private:
    Json::JsonObject* m_output;
    std::string m_errorMessage = "";
    std::string m_inputString = "";

    bool m_traceParsing = false;
};

}  // namespace Obj
}  // namespace Kitsunemimi

#endif // OBJPARSERINTERFACE_HH
