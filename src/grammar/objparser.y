/**
 *  @file    objparser.y
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

%skeleton "lalr1.cc"

%defines

//requires 3.2 to avoid the creation of the stack.hh
%require "3.0.4"
%define parser_class_name {ObjParser}

%define api.prefix {obj}
%define api.namespace {Kitsune::Obj}
%define api.token.constructor
%define api.value.type variant

%define parse.assert

%code requires
{
#include <string>
#include <iostream>
#include <vector>
#include <jsonObjects.h>

namespace Kitsune
{
namespace Obj
{

class ObjParserInterface;
using namespace Kitsune::Json;

}  // namespace Obj
}  // namespace Kitsune
}

// The parsing context.
%param { Kitsune::Obj::ObjParserInterface& driver }

%locations

%code
{
#include <obj_parsing/objParserInterface.h>
# undef YY_DECL
# define YY_DECL \
    Kitsune::Obj::ObjParser::symbol_type objlex (Kitsune::Obj::ObjParserInterface& driver)
YY_DECL;
}

// Token
%define api.token.prefix {Obj_}
%token
    END  0  "end of file"
    COMMENT "#"
    BREAK "/"
    DOUBLEBREAK "//"
    VERTEX "v"
    TEXTURE "vt"
    NORMALE "vn"
    POINT "p"
    LINE "l"
    FACE "f"
;


%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <float> FLOAT "float"

%type  <JsonArray*> entry

%type  <JsonArray*> vertexlist
%type  <JsonArray*> normalelist
%type  <JsonArray*> texturelist
%type  <JsonArray*> pointlist
%type  <JsonArray*> linelist
%type  <JsonArray*> facelist


%type  <JsonArray*> vertex
%type  <JsonArray*> texture
%type  <JsonArray*> normale
%type  <JsonArray*> point
%type  <JsonArray*> line
%type  <JsonArray*> face

%type  <JsonArray*> itemlist
%type  <JsonArray*> item

%%
%start startpoint;


startpoint:
    vertexlist normalelist texturelist pointlist linelist facelist
    {
        JsonObject* result = new JsonObject();
        result->insert("v", $1);
        result->insert("vn", $2);
        result->insert("vt", $3);
        result->insert("p", $4);
        result->insert("l", $5);
        result->insert("f", $6);
        driver.setOutput(result);
    }

vertexlist:
    vertexlist vertex
    {
        $1->append($2);
        $$ = $1;
    }
|
    vertex
    {
        JsonArray* tempItem = new JsonArray();
        tempItem->append($1);
        $$ = tempItem;
    }

normalelist:
    normalelist normale
    {
        $1->append($2);
        $$ = $1;
    }
|
    normale
    {
        JsonArray* tempItem = new JsonArray();
        tempItem->append($1);
        $$ = tempItem;
    }
|
    %empty
    {
        JsonArray* result = new JsonArray();
        $$ = result;
    }

texturelist:
    texturelist texture
    {
        $1->append($2);
        $$ = $1;
    }
|
    texture
    {
        JsonArray* tempItem = new JsonArray();
        tempItem->append($1);
        $$ = tempItem;
    }
|
    %empty
    {
        JsonArray* result = new JsonArray();
        $$ = result;
    }

pointlist:
    pointlist point
    {
        $1->append($2);
        $$ = $1;
    }
|
    point
    {
        JsonArray* tempItem = new JsonArray();
        tempItem->append($1);
        $$ = tempItem;
    }
|
    %empty
    {
        JsonArray* result = new JsonArray();
        $$ = result;
    }

linelist:
    linelist line
    {
        $1->append($2);
        $$ = $1;
    }
|
    line
    {
        JsonArray* tempItem = new JsonArray();
        tempItem->append($1);
        $$ = tempItem;
    }
|
    %empty
    {
        JsonArray* result = new JsonArray();
        $$ = result;
    }

facelist:
    facelist face
    {
        $1->append($2);
        $$ = $1;
    }
|
    face
    {
        JsonArray* tempItem = new JsonArray();
        tempItem->append($1);
        $$ = tempItem;
    }
|
    %empty
    {
        JsonArray* result = new JsonArray();
        $$ = result;
    }

vertex:
    "v" "float" "float" "float"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue((float)$2));
        result->append(new JsonValue((float)$3));
        result->append(new JsonValue((float)$4));
        $$ = result;
    }

normale:
    "vn" "float" "float" "float"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue((float)$2));
        result->append(new JsonValue((float)$3));
        result->append(new JsonValue((float)$4));
        $$ = result;
    }

texture:
    "vt" "float" "float"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue((float)$2));
        result->append(new JsonValue((float)$3));
        $$ = result;
    }

point:
    "p" itemlist
    {
        $$ = $2;
    }

line:
    "l" itemlist
    {
        $$ = $2;
    }

face:
    "f" itemlist
    {
        $$ = $2;
    }

itemlist:
    itemlist item
    {
        $1->append($2);
        $$ = $1;
    }
|
    item
    {
        JsonArray* result = new JsonArray();
        result->append($1);
        $$ = result;
    }

item:
    "number"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue($1));
        $$ = result;
    }
|
    "number" "/" "number"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue($1));
        result->append(new JsonValue($3));
        $$ = result;
    }
|
    "number" "//" "number"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue($1));
        result->append(new JsonValue($3));
        $$ = result;
    }
|
    "number" "/" "number" "/" "number"
    {
        JsonArray* result = new JsonArray();
        result->append(new JsonValue($1));
        result->append(new JsonValue($3));
        result->append(new JsonValue($5));
        $$ = result;
    }
%%

void Kitsune::Obj::ObjParser::error(const Kitsune::Obj::location& location,
                                    const std::string& message)
{
    driver.error(location, message);
}
