This README.txt file goes over instructions on how to run my program
for hw5.

You have to compile the code as it is c++, you may do so with the 
following line (in the cs1 computer):

$ g++ -o HW5 HW5.cpp

Where the "-o HW5" sets the output name for the .o file and HW5.cpp
refers to the file to be compiled.

After running that command line, you may run the program:

$ ./HW5 capacity /path/to/your/fileName.txt

Where the "capacity" refers to the capacity of the knapsack for the
problem to be solved. It is assumed for this value to be an integer.
The "/path/to/your/fileName.txt" refers specifically to the file path
where the input file is. The file is assumed to have the format
specified by the assignment guideline.

For example:

The following line will output the optimal value for a knapsack with
a capacity of 18 and reading in the values for the specified file:

$ ./HW5 18 /Input_Files/input.txt

There is no need for "~/", "../", or "./" as I have hardcoded in
"./". This means that it is assumed that the file you are going to pass
to the file is in the Input_Files folder or you may create another folder
in the scope of the code and refer to a file within that folder.

Note:

Incomplete solution: After several attempts, I was unable to insert the
keep array in the correct place. This would've allowed me to show the
values and weights of the items that add up to the optimal solution.

It would be great if you could release the function, just to see the
placement of the keep array within the function.

Furthermore, I would've had more item, I would've been able to test and
devise a solution with the keep array.