CXX = g++
CXXFLAGS = -std=c++17 -I./include

SRC = src/naadya.cpp src/lexer.cpp src/tokens.cpp
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

TARGET = build/naadya

all: $(TARGET)

# Rule to link the final binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Rule to compile .cpp to .o in build/
build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the build directory exists
build:
	mkdir -p build

# Clean build artifacts
clean:
	rm -rf build

# Run the binary with the given script
run: $(TARGET)
	./$(TARGET) scripts/myscript.ndy

# Full rebuild and run
rebuild: clean all run
