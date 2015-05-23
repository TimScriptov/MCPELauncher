package net.zhuoweizhang.mcpelauncher.texture;
import org.json.*;
public final class TexturePackDescription {

	public String type;
	public String path;
	public TexturePackDescription(String type, String path) {
		this.type = type;
		this.path = path;
	}

	// Schema for texture packs:
	// JSON; "t": type, "p": path
	// we expect scripts to be added to this, eventually
	// not sure about addons?

	public JSONObject toJson() throws JSONException {
		return new JSONObject().put("t", type).put("p", path);
	}

	public String toString() {
		return type + ":" + path;
	}

	public static TexturePackDescription fromJson(JSONObject obj) throws JSONException {
		return new TexturePackDescription(obj.getString("t"), obj.getString("p"));
	}
}
