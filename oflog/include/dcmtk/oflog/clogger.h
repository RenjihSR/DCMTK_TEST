// -*- C -*-
/**
 * Module:  Log4CPLUS
 * File:    clogger.h
 * Created: 01/2011
 * Author:  Jens Rehsack
 *
 *
 * Copyright 2011 Jens Rehsack & Tad E. Smith
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file 
 * This header defines the C API for log4cplus and the logging macros. */

#ifndef DCMTK_LOG4CPLUS_CLOGGERHEADER_
#define DCMTK_LOG4CPLUS_CLOGGERHEADER_

#include "dcmtk/oflog/config.h"

#if defined (DCMTK_LOG4CPLUS_HAVE_PRAGMA_ONCE)
#pragma once
#endif


#ifdef __cplusplus
extern "C"
{
#endif

// TODO UNICODE capable

typedef void *logger_t;
typedef int loglevel_t;

#define L4CP_OFF_LOG_LEVEL 60000
#define L4CP_FATAL_LOG_LEVEL 50000
#define L4CP_ERROR_LOG_LEVEL 40000
#define L4CP_WARN_LOG_LEVEL 30000
#define L4CP_INFO_LOG_LEVEL 20000
#define L4CP_DEBUG_LOG_LEVEL 10000
#define L4CP_TRACE_LOG_LEVEL 0
#define L4CP_ALL_LOG_LEVEL TRACE_LOG_LEVEL
#define L4CP_NOT_SET_LOG_LEVEL -1

#ifdef DCMTK_OFLOG_UNICODE
#  define DCMTK_LOG4CPLUS_TEXT2(STRING) L##STRING
typedef wchar_t log4cplus_char_t;
#else
#  define DCMTK_LOG4CPLUS_TEXT2(STRING) STRING
typedef char log4cplus_char_t;
#endif // DCMTK_OFLOG_UNICODE
#define DCMTK_LOG4CPLUS_TEXT(STRING) DCMTK_LOG4CPLUS_TEXT2(STRING)

DCMTK_LOG4CPLUS_EXPORT int log4cplus_file_configure(const log4cplus_char_t *pathname);
DCMTK_LOG4CPLUS_EXPORT int log4cplus_str_configure(const log4cplus_char_t *config);
DCMTK_LOG4CPLUS_EXPORT int log4cplus_basic_configure(void);
DCMTK_LOG4CPLUS_EXPORT void log4cplus_shutdown(void);

DCMTK_LOG4CPLUS_EXPORT int log4cplus_logger_exists(const log4cplus_char_t *name);
DCMTK_LOG4CPLUS_EXPORT int log4cplus_logger_is_enabled_for(
    const log4cplus_char_t *name, loglevel_t ll);
DCMTK_LOG4CPLUS_EXPORT int log4cplus_logger_log(const log4cplus_char_t *name,
    loglevel_t ll, const log4cplus_char_t *msgfmt, ...)
    DCMTK_LOG4CPLUS_FORMAT_ATTRIBUTE (__printf__, 3, 4);
DCMTK_LOG4CPLUS_EXPORT int log4cplus_logger_force_log(const log4cplus_char_t *name,
    loglevel_t ll, const log4cplus_char_t *msgfmt, ...)
    DCMTK_LOG4CPLUS_FORMAT_ATTRIBUTE (__printf__, 3, 4);

#ifdef __cplusplus
}
#endif

#endif /*?DCMTK_LOG4CPLUS_CLOGGERHEADER_*/
