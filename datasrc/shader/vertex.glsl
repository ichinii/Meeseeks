attribute vec2 vertexPosition;
attribute vec2 vertexUV;

varying vec4 pos;
varying vec2 uv;

void main() {
	pos = vec4(vertexPosition, 0, 1);
	uv = vertexUV;
	gl_Position = pos;
}
