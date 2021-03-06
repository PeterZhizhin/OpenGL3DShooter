APP := main

CXX := g++ 
LD := g++
CXXFLAGS += -DDEBUG -Wall -std=c++14
LDFLAGS += -lGLEW -lGL -lglut -lpthread

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

.PHONY: all $(APP)

all: $(APP)

$(APP): $(OBJECTS)
	$(LD) -o $(APP) $(LDFLAGS) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.a $(APP)
