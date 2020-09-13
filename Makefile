CC=g++
CFLAGS=-Wall -O3 -Ofast -fno-exceptions -fopenmp
LIBS=-lm
LDFLAGS=-lpthread -fopenmp

SRC=vector.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME=wave

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): main.cpp $(OBJ)
	$(CC) $(CFLAGS) $(INCDIR) $(LDFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f *.o
	rm -f $(NAME)
