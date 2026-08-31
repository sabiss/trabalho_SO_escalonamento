TARGET = varredor

CXX = g++
CXXFLAGS = -Wall -std=c++17 -O3 -pthread

SRCS = src/main.cpp src/calcula_sequencia.cpp src/gerador_de_saida.cpp src/relogio.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) src/*.o