CC=g++
CFLAGS=-Wall -O2 -fno-exceptions
LIBS=-lm
LDFLAGS=

SRC=vector.cpp upscale_filter.cpp downscale_filter.cpp composed_filter.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME=wave

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): main.cpp $(OBJ)
	$(CC) $(CFLAGS) $(INCDIR) $(LDFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f *.o
	rm -f $(NAME)
