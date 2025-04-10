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

#include "Open4D/OFD_geometry.h"
#include <stdlib.h>
#include <stdio.h>

struct OFD_RegularMesh OFD_regular_mesh[] = {
   [FIVE_CELL] = {3, 3, 3},
   [EIGHT_CELL] = {4, 3, 3},
   [SIXTEEN_CELL] = {3, 3, 4},
   [TWENTY_FOUR_CELL] = {3, 4, 3},
   [ONE_TWENTY_CELL] = {5, 3, 3},
   [SIX_HUNDRED_CELL] = {3, 3, 5}
};


OFD_Mesh3D OFD_SliceMesh(OFD_Mesh mesh, double w) { 
   OFD_Mesh3D out = {0, NULL};

   // Iterate through all tetrahedrons and add their slice to a mesh.
   for (int i = 0; i < mesh.length; i++) { 
      OFD_Mesh3D slice = OFD_SliceTetrahedron(mesh.mesh[i], w);
      if (slice.length == 0 || !slice.mesh) { continue; }

      // Extend 'out' to account for new OFD_Triangle3D's.
      out.mesh = realloc(out.mesh, (out.length + slice.length) * sizeof(OFD_Triangle3D));

      if (!out.mesh) { 
         printf("Failed to allocate memory for slice. Cancelling.");
         free(slice.mesh);
         return (OFD_Mesh3D){0, NULL};
      }

      out.mesh[out.length] = slice.mesh[0];
      
      if (slice.length == 2) {
         out.mesh[out.length + 1] = slice.mesh[1];
      }
      out.length += slice.length;
      free(slice.mesh);
   }
   return out;
}
