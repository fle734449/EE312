# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

flood_fill: stack312_ll.o driver.o
	c99 -o life stack312_ll.o driver.o

stack312_ll.o: stack312_ll.c
	c99 -c stack312_ll.c

driver.o: driver.c
	c99 -c driver.c
