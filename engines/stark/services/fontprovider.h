/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARK_SERVICES_FONT_PROVIDER_H
#define STARK_SERVICES_FONT_PROVIDER_H

#include "common/hash-str.h"
#include "common/ptr.h"

namespace Graphics {
class Font;
}

namespace Stark {

/**
 * The font provider offers a set of predefined fonts for the game to use
 */
class FontProvider {
public:
	FontProvider();
	~FontProvider();

	enum FontType {
		kSmallFont,
		kBigFont,
		kCustomFont
	};

	/**
	 * Request a font matching the specified parameters
	 */
	const Graphics::Font *getFont(FontType type, int32 customFontIndex);

	/**
	 * Get the height of the font matching the specified parameters
	 */
	int getFontHeight(FontType type, int32 customFontIndex);

private:
	struct FontHolder {
		Common::String _name;
		uint32 _height;
		uint32 _charset;
		Common::SharedPtr<Graphics::Font> _font;

		FontHolder() : _height(0), _charset(0) {}
		FontHolder(FontProvider *fontProvider, Common::String name, uint32 height, uint32 charset = 0);
	};

	void initFonts();
	FontHolder *getFontHolder(FontType type, int32 customFontIndex);

	FontHolder _smallFont;
	FontHolder _bigFont;
	FontHolder _customFonts[8];

	Common::StringMap _ttfFileMap;
};

} // End of namespace Stark

#endif // STARK_SERVICES_FONT_PROVIDER_H
