# MathVectors
Small Library as I learn C++ for MathVectors for me and a couple friends to use when we start developing games

## [Change-log]
# [Version - 1.1.0]
- Rewritten from scratch into a single Header File
- Uses std::array to store the 'data' (originally was std::vector)
- Added Modulus overload
- Added Scalar Division, Mutliplication, Addition, Subtraction overload
- Added additional paramater to the template to define the size of the Vector at initialization

# [Version - 1.2.0]
- Removed Copy, Move constructors
- Removed member variable m_Size, will now just use templates 'S' variable
- Removed function Print(), and Print(variableName), standard << operator overload remains
- Replaced instances of std::size_t with just size_t
