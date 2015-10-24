// Copyright (c) The HLSL2GLSLFork Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.txt file.


#include "osinclude.h"

#define OS_VALID_TLS_INDEX		true

//
// Thread Local Storage Operations
//
OS_TLSIndex OS_AllocTLSIndex()
{
	OS_TLSIndex key;
	if(pthread_key_create(&(key.mKey),NULL) != 0)
	{
		assert(0 && "OS_AllocTLSIndex(): Unable to allocate Thread Local Storage");
		key.mIsValidIndex = OS_INVALID_TLS_INDEX ;
	}

	key.mIsValidIndex = OS_VALID_TLS_INDEX ;
	return key;
}


bool OS_SetTLSValue(OS_TLSIndex nIndex,void *lpvValue)
{
	if(pthread_setspecific(nIndex.mKey,lpvValue) != 0)
	{
		assert(0 && "OS_SetTLSValue(): Invalid TLS Key");
		nIndex.mIsValidIndex = OS_INVALID_TLS_INDEX ;
		return false;
	}

	nIndex.mIsValidIndex = OS_VALID_TLS_INDEX ;
	return true;
}


bool OS_FreeTLSIndex(OS_TLSIndex nIndex)
{
	if(pthread_key_delete(nIndex.mKey) != 0)
	{
		assert(0 && "OS_FreeTLSIndex(): Invalid TLS Index");
		nIndex.mIsValidIndex = OS_INVALID_TLS_INDEX ;
		return false;
	}

	nIndex.mIsValidIndex = OS_INVALID_TLS_INDEX ;
	return true;
}
