CXX = g++
CXXFLAGS = -Wall -g -I ../include/

all : main
	@./main

main : main.o Person.o Sales_data.o
	$(CXX) $(CXXFLAGS) -o main main.o Person.o Sales_data.o

# all rules implicity expanded
# $(CXX) $(CXXFLAGS) -c *.cpp

main.o : Person.h Sales_data.h
Person.o : Person.h
Sales_data.o : Sales_data.h
