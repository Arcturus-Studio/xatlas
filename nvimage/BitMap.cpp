// This code is in the public domain -- castanyo@yahoo.es

#include "BitMap.h"
#include "nvcore/nvcore.h"

using namespace nv;

void BitMap::resize(uint32_t w, uint32_t h, bool initValue)
{
	BitArray tmp(w * h);
	if (initValue) tmp.setAll();
	else tmp.clearAll();
	// @@ Copying one bit at a time. This could be much faster.
	for (uint32_t y = 0; y < m_height; y++) {
		for (uint32_t x = 0; x < m_width; x++) {
			//tmp.setBitAt(y*w + x, bitAt(x, y));
			if (bitAt(x, y) != initValue) tmp.toggleBitAt(y * w + x);
		}
	}
	std::swap(m_bitArray, tmp);
	m_width = w;
	m_height = h;
}
