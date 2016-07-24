varying vec4 pos;
varying vec2 uv;

void main() {
	gl_FragColor = vec4(1, 0.1, 0.3, 1) * (-pos.z * 0.5 + 0.5);
}
