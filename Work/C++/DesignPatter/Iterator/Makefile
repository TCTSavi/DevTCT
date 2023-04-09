CC= g++
RS= windres
MAIN= Capp
#Boa parte desses flags fazem com que o binario incluas todas dependências
CFLAGS =  #-static-libgcc -static-libstdc++
# -c só produz o binario e -g produz o binario com depuração(gdb)
CMOD = -c -g 
MFILES = 
IFILES = devCIterator
RCFILES =
DFiles = 

MP_INC = ..\..\mainLib\inc
MP_LIB = ..\..\mainLib\lib
MP_RES = ..\..\mainLib\res
MP_OBJ = ..\..\mainLib\obj
P_INC = inc
P_LIB = lib
P_RES = res
P_SRC = src
P_OBJ = obj
P_BIN = bin

MOBJS  = $(patsubst %,%.o,$(MFILES))
IOBJS = $(patsubst %,%.o,$(IFILES))
IRC = $(patsubst %,%.o,$(RCFILES))

vpath %.o ${P_OBJ}

all: ${P_BIN}/${MAIN}.exe
	$<
	
${P_BIN}/${MAIN}.exe: ${P_OBJ}/${MAIN}.o ${MOBJS} ${IOBJS} ${IRC} 
	${CC} ${CFLAGS} -o $@ $< $(patsubst %,${P_OBJ}/%,$(IOBJS)) $(patsubst %,${P_RES}/%,$(IRC)) $(patsubst %,${P_OBJ}/%,$(MOBJS))
	
${P_OBJ}/${MAIN}.o: ${MAIN}.cpp ${MAIN}.h
	${CC}  ${CMOD} $< -o $@

${MOBJS}: %.o:${P_SRC}/%.cpp ${MAIN}.h
	${CC}  ${CMOD} $< -o ${P_OBJ}/$@
	
${IOBJS}: %.o:${P_LIB}/%.cpp ${P_INC}/%.h
	${CC}  ${CMOD} $< -o ${P_OBJ}/$@
	
${IRC}:	%.o:${P_RES}/%.rc
	${RS}  -i $< -o ${P_RES}/$@
	
