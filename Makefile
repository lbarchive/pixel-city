SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp,%.o,$(SRCS))
CFLAGS	= -g -Wall -Wno-write-strings
LDFLAGS	= -lGL -lGLU -lglut

all: ${OBJS}
	${CXX} ${CFLAGS} ${LDFLAGS} -o PixelCity ${OBJS}
clean:
	rm -f ${OBJS}

%.o: %.cpp
	${CXX} ${CFLAGS} -c -o $@ $^
