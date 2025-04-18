/*
   Open4D
   Copyright (c) 2025 William Gibbs & S.V

   This software is provided 'as-is', without any express or implied
   warranty. In no event will the authors be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
      claim that you wrote the original software. If you use this software
      in a product, an acknowledgment in the product documentation would be
      appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must not be
      misrepresented as being the original software.
   3. This notice may not be removed or altered from any source distribution.
*/

#ifndef OFD_util_h_
#define OFD_util_h_



/** @brief Represents a 2D vector. */
typedef struct { double x, y; } OFD_Vector2;

/** @brief Represents a 3D vector. */
typedef struct { double x, y, z; } OFD_Vector3;

/** @brief Represents a 4D vector. */
typedef struct { double x, y, z, w; } OFD_Vector4;

/** @brief Represents a 6D vector. Used for rotational calculations in 4D, 
 * which have 6 planes of rotation. */
typedef struct { double xy, xz, xw, yz, yw, zw; } OFD_Vector6;


/** @brief Calculates the magnitude of the provided vector. */
extern double OFD_Vector2_Magnitude(OFD_Vector2 a);
/** @brief Adds two 2D vectors together.*/
extern OFD_Vector2 OFD_Vector2_Add(OFD_Vector2 a, OFD_Vector2 b);
/** @brief Subtracts vector "b" from vector "a" */
extern OFD_Vector2 OFD_Vector2_Subtract(OFD_Vector2 a, OFD_Vector2 b);
/** @brief Calculates the dot product of two 2D vectors. */
extern double OFD_Vector2_Dot(OFD_Vector2 a, OFD_Vector2 b);


/** @brief Calculates the magnitude of the provided vector. */
extern double OFD_Vector3_Magnitude(OFD_Vector3 a);
/** @brief Finds the cross product of two 3D vectors.
 * 
 *  The "cross product" is a 3D vector derived from two others. It
 *  represents a vector perpendicular to a plane formed by vectors "a" and "b"
 *  It also represents the area of the parallelogram formed by vectors "a" and "b"
 * 
 */
extern OFD_Vector3 OFD_Cross(OFD_Vector3 a, OFD_Vector3 b);
/** @brief Adds two 3D vectors together. */
extern OFD_Vector3 OFD_Vector3_Add(OFD_Vector3 a, OFD_Vector3 b);
/** @brief Subtracts vector "b" from vector "a" */
extern OFD_Vector3 OFD_Vector3_Subtract(OFD_Vector3 a, OFD_Vector3 b);
/** @brief Calculates the dot product of two 3D vectors. */
extern double OFD_Vector3_Dot(OFD_Vector3 a, OFD_Vector3 b);


/** @brief Calculates the magnitude of the provided vector. */
extern double OFD_Vector4_Magnitude(OFD_Vector4 a);
/** @brief Finds the exterior product, or wedge product of two 4D vectors.
 * 
 * The "exterior product," also known as the "wedge product" is a 6D vector 
 * derived from two 4D vectors. Similar to the cross product, the exterior product 
 * can find the area of a parallelogram formed by vectors "a" and "b" in 4D space.
 * 
 */
extern OFD_Vector6 OFD_Exterior(OFD_Vector4 a, OFD_Vector4 b);
/** @brief Adds two 4D vectors together. */
extern OFD_Vector4 OFD_Vector4_Add(OFD_Vector4 a, OFD_Vector4 b);
/** @brief Subtracts vector "b" from vector "a" */
extern OFD_Vector4 OFD_Vector4_Subtract(OFD_Vector4 a, OFD_Vector4 b);
/** @brief Calculates the dot product of two 4D vectors. */
extern double OFD_Vector4_Dot(OFD_Vector4 a, OFD_Vector4 b);


/** @brief Calculates the magnitude of the provided vector. */
extern double OFD_Vector6_Magnitude(OFD_Vector6 a);


/** @brief Rotates a 4D vector around a central point. */
extern OFD_Vector4 OFD_Vector4_Rotate(OFD_Vector4 a, OFD_Vector4 c, OFD_Vector6 r);


#endif // OFD_util_h_