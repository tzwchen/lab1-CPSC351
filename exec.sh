#!/bin/bash

#compile
g++ processes.cpp -o processes

#check if compiled is successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running processes..."
    echo "----------------------------------------"
    ./processes
else
    echo "Compilation failed."

fi

#when process complete, delete .o files
rm -f *.o