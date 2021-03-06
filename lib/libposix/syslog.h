/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBPOSIX_SYSLOG_H
#define __LIBPOSIX_SYSLOG_H

#include <Macros.h>
#include <Types.h>
#include "sys/types.h"

/**                                                                                                                                                                                                     
 * @defgroup libposix libposix (POSIX.1-2008)
 * @{
 */

/**
 * @brief Severity Levels.
 * @{
 */

/** @brief A panic condition. */
#define LOG_EMERG	(1 << 0)

/**
 * @brief A condition that should be corrected immediately,
 *        such as a corrupted system database.
 */
#define LOG_ALERT	(1 << 1)

/** @brief Critical conditions, such as hard device errors. */
#define LOG_CRIT	(1 << 2)

/** @brief Errors. */
#define LOG_ERR		(1 << 3)

/** @brief Warning messages. */
#define LOG_WARNING	(1 << 4)

/**
 * @brief Conditions that are not error conditions,
 *        but that may require special handling.
 */
#define LOG_NOTICE	(1 << 5)

/** @brief Informational messages. */
#define LOG_INFO	(1 << 6)

/**
 * @brief Messages that contain information normally
 *        of use only when debugging a program.
 */
#define LOG_DEBUG	(1 << 7)

/**
 * @}
 */

/**
 * @brief Logging Facilities.
 * @{
 */

/**
 * @brief Messages generated by arbitrary processes. This is
 *        the default facility identifier if none is specified.
 */
#define LOG_USER	(1 << 8)

/** @brief Reserved for local use. */
#define LOG_LOCAL0	(1 << 9)

/** @brief Reserved for local use. */
#define LOG_LOCAL1	(1 << 10)

/** @brief Reserved for local use. */
#define LOG_LOCAL2	(1 << 11)

/** @brief Reserved for local use. */
#define LOG_LOCAL3	(1 << 12)

/** @brief Reserved for local use. */
#define LOG_LOCAL4	(1 << 13)

/** @brief Reserved for local use. */
#define LOG_LOCAL5	(1 << 14)

/** @brief Reserved for local use. */
#define LOG_LOCAL6	(1 << 15)

/** @brief Reserved for local use. */
#define LOG_LOCAL7	(1 << 16)

/**
 * @}
 */

/**
 * @brief Log Options.
 * @{
 */

/**
 * @brief Log the process ID with each message. This is useful
 *        for identifying specific processes.
 */
#define LOG_PID		(1 << 0)

/**
 * @brief Write messages to the system console if they cannot
 *        be sent to the logging facility. The syslog() function
 *        ensures that the process does not acquire the console
 *        as a controlling terminal in the process of writing the message.
 */
#define LOG_CONS	(1 << 1)

/**
 * @brief Open the connection to the logging facility immediately. Normally
 *        the open is delayed until the first message is logged. This is
 *        useful for programs that need to manage the order in which file
 *        descriptors are allocated.
 */
#define LOG_NDELAY	(1 << 2)

/**
 * @brief Delay open until syslog() is called.
 */
#define LOG_ODELAY	(1 << 3)

/**
 * @brief Do not wait for child processes that may have been created
 *        during the course of logging the message. This option should
 *        be used by processes that enable notification of child
 *        termination using SIGCHLD, since syslog() may otherwise block
 *        waiting for a child whose exit status has already been collected. 
 */
#define LOG_NOWAIT	(1 << 4)

/**
 * @}
 */

/**
 * @brief String used to identify ourselves to the logging facility.
 */
extern char * logIdentity;

/**
 * @brief FileDescriptor number to the log file.
 */
extern int logFile;

/**
 * @brief Opens the system logging mechanism.
 *
 * This function simply opens /dev/log for logging.
 *
 * @param ident Identity string.
 * @param logopt Logging option flags.
 * @param facility The facility indicates the application or
 *                 system component generating the message.
 *
 * @see SystemLog
 * @see syslog
 * @see closelog
 */
extern C void openlog(const char *ident, int logopt, int facility);

/**
 * @brief Log a message to the system logging mechanism.
 *
 * This function formats the given message and writes it
 * to the open FileDescriptor of /dev/log.
 *
 * @param priority Values of the priority argument are formed by
 *                 OR'ing together a severity-level value and an
 *                 optional facility value.
 * @param message Describes the message to log.
 * @param ... Optional argument list.
 *
 * @see FileDescriptor
 * @see SystemLog
 */
extern C void syslog(int priority, const char *message, ...);

/**
 * @brief Close the system logging mechanism.
 *
 * Closes the /dev/log file using close().
 *
 * @see SystemLog
 * @see close
 */
extern C void closelog(void);

/**
 * @}
 */

#endif /* __LIBPOSIX_SYSLOG_H */
