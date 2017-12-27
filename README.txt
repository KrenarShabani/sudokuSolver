The the core program is wriiten in C++ which does the main task of solving the Sudoku Puzzle
There is a C++/CLR class implemented as a wrapper to the C++ class so it can interact with the C# GUI




- The GUI only works on my machine sadly. If you want to see the Algorithm run without a GUI on OSX or Linux just compile the files in the "Non_GUI" folder while making sure you edit the driver.cpp file to be able to receive a .txt file
- On Windows just open "SudokuCore.vcxproj" in the "SudokuCore" folder with Visual Studio and edit the driver file accordingly
- you can use the "ExampleFile.txt" file I included to run a test




version 2.0.0
- added a very basic GUI system. prone to errors i assume. just follow the the Example txt file i left in the repo


version 1.0.0

- you are going to need to edit the driver.cpp file and enter the adress of the input and output text files
- you are also going to need visual studio to edit and run the files since i didnt create a runnable exe (yet)
