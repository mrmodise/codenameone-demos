#ifndef __BINARYBITMAP_H__
#define __BINARYBITMAP_H__

/*
 *  BinaryBitmap.h
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Counted.h"
#include "BitMatrix.h"
#include "BitArray.h"
#include "Binarizer.h"

namespace zxing {
	
	class BinaryBitmap : public Counted {
	private:
		Ref<Binarizer> binarizer_;
		int cached_y_;
		
	public:
		BinaryBitmap(Ref<Binarizer> binarizer);
		virtual ~BinaryBitmap();
		
		Ref<BitArray> getBlackRow(int y, Ref<BitArray> row);
		Ref<BitMatrix> getBlackMatrix();
		
		Ref<LuminanceSource> getLuminanceSource() const;

		int getWidth() const;
		int getHeight() const;

		bool isRotateSupported() const;
		Ref<BinaryBitmap> rotateCounterClockwise();

		bool isCropSupported() const;
		Ref<BinaryBitmap> crop(int left, int top, int width, int height);

	};
	
}

#endif /* BINARYBITMAP_H_ */
