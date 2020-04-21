%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include <obj_parsing/obj_parserInterface.h>
# include <objparser.h>

# undef yywrap
# define yywrap() 1


// The location of the current token.
# ifdef YY_DECL
# undef YY_DECL
# endif
# define YY_DECL \
    Kitsunemimi::Obj::ObjParser::symbol_type objlex (Kitsunemimi::Obj::ObjParserInterface& driver)
YY_DECL;
Kitsune::Obj::location objloc;

%}


%option noyywrap nounput batch debug yylineno prefix="obj"

id    [a-zA-Z][a-zA-Z_0-9]*
int   -?([0-9]+)
blank [ \t]

%{
    # define YY_USER_ACTION  objloc.columns (yyleng);
%}

%%

%{
    objloc.step();
%}

{blank}+  objloc.step();
[\n]      objloc.step();
"#"       return Kitsune::Obj::ObjParser::make_COMMENT(objloc);
"/"       return Kitsune::Obj::ObjParser::make_BREAK(objloc);
"//"      return Kitsune::Obj::ObjParser::make_DOUBLEBREAK(objloc);
"v"       return Kitsune::Obj::ObjParser::make_VERTEX(objloc);
"vt"      return Kitsune::Obj::ObjParser::make_TEXTURE(objloc);
"vn"      return Kitsune::Obj::ObjParser::make_NORMALE(objloc);
"p"       return Kitsune::Obj::ObjParser::make_POINT(objloc);
"l"       return Kitsune::Obj::ObjParser::make_LINE(objloc);
"f"       return Kitsune::Obj::ObjParser::make_FACE(objloc);

{int}      {
    errno = 0;
    long length = strtol(yytext, NULL, 10);
    if (!(INT_MIN <= length
        && length <= INT_MAX
        && errno != ERANGE))
    {
        driver.error(objloc, "integer is out of range");
    }
    return Kitsune::Obj::ObjParser::make_NUMBER(length, objloc);
}

{int}+"."{int}*	{
    float value = atof( yytext );
    return Kitsune::Obj::ObjParser::make_FLOAT(value, objloc);
}

{id}       return Kitsune::Obj::ObjParser::make_IDENTIFIER(yytext, objloc);
.          driver.error(objloc, "invalid character");
<<EOF>>    return Kitsune::Obj::ObjParser::make_END(objloc);

%%


void Kitsune::Obj::ObjParserInterface::scan_begin(const std::string &inputString)
{
    Kitsune::Obj::location newJsonloc;
    objloc = newJsonloc;
    yy_flex_debug = m_traceParsing;
    yy_scan_string(inputString.c_str());
}

void Kitsune::Obj::ObjParserInterface::scan_end()
{
    yy_delete_buffer(YY_CURRENT_BUFFER);
}


