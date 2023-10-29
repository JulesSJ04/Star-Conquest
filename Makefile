# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRC = main.cpp spacecraft.cpp

# Header files
HEADERS = main.h spacecraft.h

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXECUTABLE = spacecraft

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXECUTABLE)
