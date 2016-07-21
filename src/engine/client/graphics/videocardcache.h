#ifndef ENGINE_VIDEOCARDCACHE_H
#define ENGINE_VIDEOCARDCACHE_H

class VideocardCache {
private:
	enum { MAX_TEXTURES = 16 };

	GLuint m_TextureGLIDs[MAX_TEXTURES];

public:
	void Upload(Texture tex);
	void Upload(Model model);
	GLuint GetTextureGLID(Texture tex);
	void Upload(const wchar_t glyph);
	void Upload(const wchar_t *glyphs);
};

#endif
