#import "CSStreamHandle.h"

#define CSBlockStreamHandle XADBlockStreamHandle

@interface CSBlockStreamHandle:CSStreamHandle
{
	uint8_t *currblock;
	off_t blockstartpos;
	int blocklength;
	BOOL endofblocks;
}

// Intializers
-(id)initWithName:(NSString *)descname length:(off_t)length;
-(id)initWithHandle:(CSHandle *)handle length:(off_t)length bufferSize:(int)buffersize;
-(id)initAsCopyOf:(CSBlockStreamHandle *)other;

// Public methods
-(uint8_t *)blockPointer;
-(int)blockLength;
-(off_t)blockStartOffset;
-(void)skipToNextBlock;

// Implemented by this class
-(void)seekToFileOffset:(off_t)offs;
-(void)resetStream;
-(int)streamAtMost:(int)num toBuffer:(void *)buffer;

// Internal methods
-(void)_readNextBlock;

// Implemented by subclasses
-(void)resetBlockStream;
-(int)produceBlockAtOffset:(off_t)pos;

// Called by subclasses
-(void)setBlockPointer:(uint8_t *)blockpointer;
-(void)endBlockStream;

@end
