// Example file using the MathVectors
#include <iostream>
#include "../include/MathVectors.hpp"

using namespace MathVectors;

int main()
{
    //
    // Creating a vector2D
    //
    Vector<int, 2> iVec2D_1 { 20, 10 };

    //
    // Printing vectors
    //

    // Standard Print with the operator overload
    std::cout << "[Printing to the console]\n\tUsing the << operator with std::cout: ";
    std::cout << iVec2D_1 << std::endl;

    // Or you can use the classes built in print function
    std::cout << "\tUsing the Print() function: ";
    iVec2D_1.Print();

    std::cout << "\tor\n";
    // Optionally you can add a variable name to it, it will print with the variable name
    // EX: iVec2D_1: (4, 8)
    std::cout << "\tPrinting with variable name using Print(varName): ";
    iVec2D_1.Print("iVec2D_1");


    //
    // Math functions
    //
    Vector<int, 2> iVec2D_2 { 2, 4 };
    // Print both vectors
    std::cout << "\n[Vector Math]\n\t[Vectors]\n";
    std::cout << "\t\tiVec2D_1: " << iVec2D_1 << std::endl;
    std::cout << "\t\tiVec2D_2: " << iVec2D_2 << std::endl;
    
    // Addition
    Vector<int, 2> iVec2D_Add = iVec2D_1 + iVec2D_2;
    std::cout << "\n\t[Addition]\n\t\t";
    std::cout << iVec2D_1 << " + " << iVec2D_2 << " = " << iVec2D_Add << std::endl;

    // Scalar Addition
    Vector<int, 2> iVec2D_ScalarAdd = iVec2D_1 + 2;
    std::cout << "\n\t[Scalar Addition]\n\t\t";
    std::cout << iVec2D_1 << " + 2" << " = " << iVec2D_ScalarAdd << std::endl;
    
    //Subtraction
    Vector<int, 2> iVec2D_Sub = iVec2D_1 - iVec2D_2;
    std::cout << "\n\t[Subtraction]\n\t\t";
    std::cout << iVec2D_1 << " - " << iVec2D_2 << " = " << iVec2D_Sub << std::endl;
    
    //Scalar Subtraction
    Vector<int, 2> iVec2D_ScalarSub = iVec2D_1 - 2;
    std::cout << "\n\t[Scalar Subtraction]\n\t\t";
    std::cout << iVec2D_1 << " - 2" << " = " << iVec2D_ScalarSub << std::endl;

    //Multliplication
    Vector<int, 2> iVec2D_Mult = iVec2D_1 * iVec2D_2;
    std::cout << "\n\t[Multiplication]\n\t\t";
    std::cout << iVec2D_1 << " * " << iVec2D_2 << " = " << iVec2D_Mult << std::endl;
    
    // Scalar multiplication
    Vector<int, 2> iVec2D_ScalarMult = iVec2D_1 * 2;
    std::cout << "\n\t[Scalar Multiplication]\n\t\t";
    std::cout << iVec2D_1 << " * 2" << " = " << iVec2D_ScalarMult << std::endl;

    //Division
    Vector<int, 2> iVec2D_Div = iVec2D_1 / iVec2D_2;
    std::cout << "\n\t[Division]\n\t\t";
    std::cout << iVec2D_1 << " / " << iVec2D_2 << " = " << iVec2D_Div << std::endl;
    
    //Scalar Division
    Vector<int, 2> iVec2D_ScalarDiv = iVec2D_1 / 2;
    std::cout << "\n\t[Scalar Division]\n\t\t";
    std::cout << iVec2D_1 << " / 2" << " = " << iVec2D_ScalarDiv << std::endl;

    //Modulus
    Vector<int, 2> iVec2D_Mod = iVec2D_1 % iVec2D_2;
    std::cout << "\n\t[Modulous]\n\t\t";
    std::cout << iVec2D_1 << " % " << iVec2D_2 << " = " << iVec2D_Mod << std::endl;
    std::cin.get();
}
