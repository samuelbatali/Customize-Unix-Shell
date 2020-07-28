#
# Created by Samuel Batali
#

EXTENSION = shell
CXXFLAGS := -std=c++17 $(CXXFLAGS)

C_SOURCES = $(wildcard *.c) $(wildcard functions/*.c) $(wildcard processes/*.c)
CXX_SOURCES = $(wildcard *.cpp) $(wildcard functions/*.cpp) $(wildcard processes/*.cpp)

C_OBJECTS = $(C_SOURCES:.c=.o)
CXX_OBJECTS = $(CXX_SOURCES:.cpp=.o)

all: $(EXTENSION)

$(EXTENSION): $(CXX_OBJECTS) $(C_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	-rm -f $(EXTENSION) $(CXX_OBJECTS) $(C_OBJECTS)