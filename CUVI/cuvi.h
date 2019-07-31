
/*
 * Copyright (C) 2010-2012 TunaCode Pvt. Ltd.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 *
 * TUNACODE MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED
 * WARRANTY OF ANY KIND.  TUNACODE DISCLAIMS ALL WARRANTIES WITH REGARD TO`
 * THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL 
 * TUNACODE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL
 * DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOURCE CODE.  
 */

#ifndef CUVI_H
#define CUVI_H

#ifdef __cplusplus

#include "cuviCore.hpp"	//Core C++
#include "cuvico.hpp"	//Color Operations C++
#include "cuviif.hpp"	//Image Filtering C++
#include "cuvigt.hpp"	//Geometry Transforms C++
#include "cuvial.hpp"	//Arithmetic & Logic Operations C++
#include "cuvicv.hpp"	//Computer Vision C++
#include "cuvide.hpp"	//Data Exchange C++
#include "cuviis.hpp"	//Image Statistics C++
#include "cuviit.hpp"	//Image Transforms C++
#include "cuvidm.hpp"	//Device Management C++

#include "cuviio.hpp"	//Image IO
#include "cuvivs.hpp"	//Video Stabiliztion

#else
#error "This Header Requires a C++ Compiler"
#endif

#endif
