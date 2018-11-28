# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

check: driver.o stack312_arr.o
	c99 -o check driver.o stack312_arr.o

driver.o: driver.c
	c99 -c driver.c

stack312_arr.o: stack312_arr.c
	c99 -c stack312_arr.c
