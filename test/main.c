

#include <raylib.h>
#include <Open4D/OFD_geometry.h>
#include <stdlib.h>
#include <stdio.h>
#include "renderer.h"


// Generate a 24-Cell to render.
OFD_Mesh structure;

int main(void) {

    initialize_renderer();

    structure = OFD_one_twenty_cell();

    while (!WindowShouldClose()) { 
        start_frame();

        OFD_Mesh3D slice = OFD_SliceMesh(structure, 0);

        if (!slice.mesh) {
            printf("Failure to slice mesh.");
        }

        draw_mesh_3d(slice);

        free(slice.mesh);

        end_frame();
    }

    CloseWindow();

    return 0;
}