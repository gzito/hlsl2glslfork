// Copyright (c) The HLSL2GLSLFork Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.txt file.


#ifndef __OSINCLUDE_H
#define __OSINCLUDE_H

#include <pthread.h>
#include <strings.h>
#include <cassert>

#define min(X,Y) ((X) < (Y) ? X : Y)
#define _vsnprintf vsnprintf
#define _stricmp strcasecmp

//
// Thread Local Storage Operations
//

#define OS_INVALID_TLS_INDEX	false

struct OS_TLSIndex_s {
	OS_TLSIndex_s() : mIsValidIndex(OS_INVALID_TLS_INDEX) {} ;
	OS_TLSIndex_s( const bool v ): mIsValidIndex(v) {} ;
	pthread_key_t mKey ;
	bool mIsValidIndex ;

	OS_TLSIndex_s& operator=(bool v) {
		mIsValidIndex = v ;
		return *this ;
	}
	
	bool operator==(bool v) {
		return mIsValidIndex == v ;
	}

	bool operator!=(bool v) {
		return mIsValidIndex != v ;
	}
} ;

typedef OS_TLSIndex_s OS_TLSIndex ;

OS_TLSIndex     OS_AllocTLSIndex();
bool            OS_SetTLSValue(OS_TLSIndex nIndex,void *lpvValue);
bool            OS_FreeTLSIndex(OS_TLSIndex nIndex);
inline void*    OS_GetTLSValue(OS_TLSIndex nIndex)
{
	return pthread_getspecific(nIndex.mKey);
}

#endif // __OSINCLUDE_H
