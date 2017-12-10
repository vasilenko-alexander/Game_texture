attribute vec2 coords;
varying vec2 v_tex_coord;

void main()
{
    v_tex_coord = coords;
    gl_Position = vec4(coords, 0.0, 1.0);
}
