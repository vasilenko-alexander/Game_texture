varying vec2 v_tex_coord;
uniform sampler2D s_texture;

void main()
{
    gl_FragColor = texture2D(s_texture, v_tex_coord);
}
