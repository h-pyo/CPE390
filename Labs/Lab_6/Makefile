CXX	:= g++ -g -std=c++20

OBJ	:=main.o gcode.o shape.o pipe.o box.o
gcoder:  $(OBJ)
	$(CXX) $(OBJ)  -o $@ # link all .o files into the executable

main.o: main.cc shape.hh
	$(CXX) -c $<

gcode.o: gcode.cc shape.hh
	$(CXX) -c $<

shape.o: shape.cc shape.hh
	$(CXX) -c $<

pipe.o: pipe.cc pipe.hh shape.hh
	$(CXX) -c $<

box.o: box.cc box.hh box.hh shape.hh
	$(CXX) -c $<
clean:
	rm gcoder *.o

