/*
 * This file is part of FreeRCT.
 * FreeRCT is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * FreeRCT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with FreeRCT. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file text_buffer.h Text handling functions. */

#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

#include <string>

class TextBuffer {
	public:
		TextBuffer();
		~TextBuffer();

		void SetText(const char *txt);
		const std::string &GetText() const;
		void AppendText(const char *txt);
		void InsertText(const char *txt);
		void RemoveLastCharacter();
		void RemovePrevCharacter();
		void RemoveCurrentCharacter();

		void SetPosition(int position)
		{
			this->current_position = position;
		}

		int GetPosition();

		void IncPosition()
		{
			this->current_position = min(this->text.length() - 1, this->current_position + 1);
		}

		void DecPosition()
		{
			this->current_position = max(0, this->current_position - 1);
		}
	private:
		std::string text;      ///< String in which text is kept.
		uint current_position; ///< Current position of the 'cursor' in the buffer.
};

#endif
