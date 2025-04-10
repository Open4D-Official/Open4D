


#include "renderer.h"

#include <raylib.h>
#include <rlgl.h>

#include <Open4D/OFD_geometry.h>

#include <math.h>

#include <stdio.h>



static Camera camera = { 0 };

static double rotation = 0;

static const double DEGREES_TO_RADIANS = (M_PI / 180);

void draw_triangle_3d(OFD_Triangle3D tri) {
    DrawTriangle3D(
        (Vector3){tri.a.x, tri.a.y, tri.a.z},
        (Vector3){tri.b.x, tri.b.y, tri.b.z},
        (Vector3){tri.c.x, tri.c.y, tri.c.z},
        BLUE
    );
}


void draw_mesh_3d(OFD_Mesh3D tri) {
    for (int i = 0; i < tri.length; i++) {
        draw_triangle_3d(tri.mesh[i]);
    }
}




void start_frame() {


    if (IsKeyDown(KEY_LEFT)) {
        Vector3 cameraPosition = camera.position;
        camera.position.x = cameraPosition.x * cos(-4 * DEGREES_TO_RADIANS) - cameraPosition.y * sin(-4 * DEGREES_TO_RADIANS);
        camera.position.y = cameraPosition.x * sin(-4 * DEGREES_TO_RADIANS) + cameraPosition.y * cos(-4 * DEGREES_TO_RADIANS);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        Vector3 cameraPosition = camera.position;
        camera.position.x = cameraPosition.x * cos(4 * DEGREES_TO_RADIANS) - cameraPosition.y * sin(4 * DEGREES_TO_RADIANS);
        camera.position.y = cameraPosition.x * sin(4 * DEGREES_TO_RADIANS) + cameraPosition.y * cos(4 * DEGREES_TO_RADIANS);
    }


    BeginDrawing();
    ClearBackground((Color){64, 64, 64, 255});


    BeginMode3D(camera);
}

void end_frame() {
    EndMode3D();
    EndDrawing();
}


void initialize_renderer() {

    SetTraceLogLevel(LOG_ERROR); // Remove unnecessary logging from Raylib.

    InitWindow(800, 800, "Test Simulation of Open4D");
    SetTargetFPS(30);


    camera.position = (Vector3){ -10.0f, 0.0f, 2.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 0.0f, 1.0f };
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    rlDisableBackfaceCulling();

}
