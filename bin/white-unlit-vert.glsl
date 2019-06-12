#version 150

//in_Position was bound to attribute index 0
in vec3 in_Position;
uniform mat4 mvpMatrix;

void main(void) {
    gl_Position = mvpMatrix * vec4(in_Position.x, in_Position.y, in_Position.z, 1.0);
}