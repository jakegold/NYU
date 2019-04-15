Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov

This project has a main.py which is the main project. The project is run by typing 'python main.py' into the terminal on the first semantics directory. 
In order to change the file which is being tested, you will need to change it in TWO (2) spots!!!! Once in main.py in the main directory. The other is in line_numbers.py in the parser directory. If I have enough time I will make it so that you can pass in a file by the command line, but for now this seems less important. 

The main will call everything else in the project.

There is a driver directory, which will just read through a file and get rid of any single line comments. (the scanner will get rid of the multi-line comments). The driver directory has a file in it called comments which just contains some functions relating to comments.
Then the main.py will a new file into the scanner, to scan (this is the file that the prof. wrote). 
From there a new file will be written and opened by the parser. The parser directory has a parser, a file to determine all the lines of code and their respective numbers, and an other file which has a rather random selction of some functions which I hopefully will organize better... There also is a file closings to try to find if there are missing braces or parenthesis
There is also a directory called helpers which has some generic helper functions which are used across the entire project.

NEW PART:
Now there is a semantics directory which will check for type checking. This new directory's main code is being run from semantics.py, which will call everything else. First it finds all the places where any math operation is being run, any return statment is being called, or any assignment happens. Then it will test each of these test cases, and any function call to make sure that they types are correct. 

The system was built in python, version 2.7 on a mac. 

Note that the output of the project goes to the terminal, not to some output file. 

Also note that my run times are not good. At all. 