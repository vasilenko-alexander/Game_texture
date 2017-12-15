attribute vec2 coords;
attribute vec2 tex_coords;
varying vec2 v_tex_coord;

void main()
{
    v_tex_coord = tex_coords;
    gl_Position = vec4(coords, 0.0, 1.0);
}
