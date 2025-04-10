

#ifndef renderer_c_h_
#define renderer_c_h_


#include <Open4D/OFD_geometry.h>
#include <Open4D/OFD_util.h>

/** Draw a triangle to the active screen. Will be rendered for one frame before being cleared. */
extern void draw_triangle_3d(OFD_Triangle3D tri);

/** Draw a series of triangles to the active screen. Will be rendered for one frame before being cleared. */
extern void draw_mesh_3d(OFD_Mesh3D tri);

/** Initialize the renderer, including creating the window and initializing the camera. */
extern void initialize_renderer();


/** @brief Start next frame. */
extern void start_frame();

/** @brief End the current frame. */
extern void end_frame();


#endif // renderer_c_h_