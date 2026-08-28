CXX = g++
CXXFLAGS = -O3 -Wall -pthread

SRC = src/main.cpp src/calcula_sequencia.cpp src/exibe_dados.cpp
OUT = build/escalonador

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build/escalonador