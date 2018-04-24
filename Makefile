CXXFLAGS=-std=c++14 -g
OBJS = main.o LogLevel.o Utils.o BaseDestination.o ConsoleDestination.o LogBox.o
BIN = main
OUTPUT_DIR = build

$(shell mkdir -p ${OUTPUT_DIR} )

.PHONY: ${BIN}
${BIN}: ${OBJS}
	$(CXX) ${CXXFLAGS} ${OBJS} -o ${OUTPUT_DIR}/${BIN}

.PHONY: clean
clean:
	${RM} *.o
	${RM} -r ${OUTPUT_DIR}

