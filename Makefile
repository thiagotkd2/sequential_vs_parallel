TARGET = main.exe
SRCS = main.cpp filtro.cpp

$(TARGET): $(SRCS)
	g++ $(SRCS) -o $(TARGET) -fopenmp

clean:
	rm -f $(TARGET)
