QT -= qt core gui

TARGET = KitsunemimiObj
CONFIG += c++14
TEMPLATE = lib

LIBS += -L../../libKitsuneJson/src -lKitsuneJson
LIBS += -L../../libKitsuneJson/src/debug -lKitsuneJson
LIBS += -L../../libKitsuneJson/src/release -lKitsuneJson
INCLUDEPATH += ../../libKitsuneJson/include/libKitsuneJson

INCLUDEPATH += $$PWD \
            $$PWD/../include/libKitsuneObj

LIBS +=  -lfl -ly

SOURCES += \
    objConverter.cpp \
    obj_parsing/objParserInterface.cpp \
    obj_item.cpp

HEADERS += \
    ../include/libKitsunemimiObj/obj_item.h \
    obj_parsing/obj_parserInterface.h \
    obj_converter.h

FLEXSOURCES = grammar/objlexer.l
BISONSOURCES = grammar/objparser.y

OTHER_FILES +=  \
    $$FLEXSOURCES \
    $$BISONSOURCES

# The following code calls the flex-lexer and bison-parser before compiling the
# cpp-code for automatic generation of the parser-code in each build-step.
# The resulting source-code-files are stored in the build-directory of the obj-converter.
flexsource.input = FLEXSOURCES
flexsource.output = ${QMAKE_FILE_BASE}.cpp
flexsource.commands = flex --header-file=${QMAKE_FILE_BASE}.h -o ${QMAKE_FILE_BASE}.cpp ${QMAKE_FILE_IN}
flexsource.variable_out = SOURCES
flexsource.name = Flex Sources ${QMAKE_FILE_IN}
flexsource.CONFIG += target_predeps
flexsource.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += flexsource

flexheader.input = FLEXSOURCES
flexheader.output = ${QMAKE_FILE_BASE}.hh
flexheader.commands = @true
flexheader.variable_out = HEADERS
flexheader.name = Flex Headers ${QMAKE_FILE_IN}
flexheader.CONFIG += target_predeps
flexheader.CONFIG += target_predeps no_link

QMAKE_EXTRA_COMPILERS += flexheader

bisonsource.input = BISONSOURCES
bisonsource.output = ${QMAKE_FILE_BASE}.cpp
bisonsource.commands = bison -d --defines=${QMAKE_FILE_BASE}.h -o ${QMAKE_FILE_BASE}.cpp ${QMAKE_FILE_IN}
bisonsource.variable_out = SOURCES
bisonsource.name = Bison Sources ${QMAKE_FILE_IN}
bisonsource.CONFIG += target_predeps
bisonsource.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += bisonsource

bisonheader.input = BISONSOURCES
bisonheader.output = ${QMAKE_FILE_BASE}.hh
bisonheader.commands = @true
bisonheader.variable_out = HEADERS
bisonheader.name = Bison Headers ${QMAKE_FILE_IN}
bisonheader.CONFIG += target_predeps
bisonheader.CONFIG += target_predeps no_link

QMAKE_EXTRA_COMPILERS += bisonheader
