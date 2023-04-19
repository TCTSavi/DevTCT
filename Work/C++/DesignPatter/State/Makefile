CC= g++
RS= windres
MAIN= Capp
#Boa parte desses flags fazem com que o binario incluas todas dependências
CFLAGS = -static-libgcc -static-libstdc++
# -c só produz o binario e -g produz o binario com depuração(gdb)
CMOD = -c -g 
MFILES = 
IFILES = State
MIFILES = devCIterator
MFILES = 
RCFILES =
DFiles = 

MINC = ..\..\mainLib\inc
MLIB = ..\..\mainLib\lib
MRES = ..\..\mainLib\res
MOBJ = ..\..\mainLib\obj
INC = inc
LIB = lib
RES = res
SRC = src
OBJ = obj
BIN = bin

MOBJS  = $(patsubst %,%.o,$(MFILES))
IOBJS = $(patsubst %,%.o,$(IFILES))
MIOBJS = $(patsubst %,%.o,$(MIFILES))
IRC = $(patsubst %,%.o,$(RCFILES))

vpath %.o ${MOBJ} 
vpath %.o ${OBJ} 

all: ${BIN}/${MAIN}.exe
	$<

${BIN}/${MAIN}.exe: ${OBJ}/${MAIN}.o ${MOBJS} ${MIOBJS} ${IOBJS} ${IRC} 
	${CC} ${CFLAGS} -o $@ $< $(patsubst %,${OBJ}/%,$(IOBJS)) $(patsubst %,${MOBJ}/%,$(MIOBJS)) $(patsubst %,${WRES}/%,$(IRC)) $(patsubst %,${OBJ}/%,$(MOBJS))

${OBJ}/${MAIN}.o: ${MAIN}.cpp ${MAIN}.h
	${CC}  ${CMOD} $< -o $@

${MOBJS}: %.o:${SRC}/%.cpp ${MAIN}.h
	${CC}  ${CMOD} $< -o ${OBJ}/$@
	
${IOBJS}: %.o:${LIB}/%.cpp ${INC}/%.h
	${CC}  ${CMOD} $< -o ${OBJ}/$@

${MIOBJS}: %.o:${MLIB}/%.cpp ${MINC}/%.h
	${CC}  ${CMOD} $< -o ${MOBJ}/$@

${IRC}:	%.o:${RES}/%.rc
	${RS}  -i $< -o ${RES}/$@

	
	
