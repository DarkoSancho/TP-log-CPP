# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Target names
TARGET = main
OBJS = main.o Log.o Structure_Log.o

# Build the executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
