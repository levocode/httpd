/* ====================================================================
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2000 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Apache" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 *
 * Portions of this software are based upon public domain software
 * originally written at the National Center for Supercomputing Applications,
 * University of Illinois, Urbana-Champaign.
 */

#ifndef APACHE_UTIL_MD5_H
#define APACHE_UTIL_MD5_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @package Apache MD5 library
 */

#include "apr_md5.h"

/**
 * Create an MD5 checksum of a given string
 * @param a Pool to allocate out of
 * @param string String to get the checksum of
 * @return The checksum
 * @deffunc char *ap_md5(apr_pool_t *a, const unsigned char *string)
 */
AP_DECLARE(char *) ap_md5(apr_pool_t *a, const unsigned char *string);

/**
 * Create an MD5 checksum of a string of binary data
 * @param a Pool to allocate out of
 * @param buf Buffer to generate checksum for
 * @param len The length of the buffer
 * @return The checksum
 * @deffunc char *ap_md5_binary(apr_pool_t *a, const unsigned char *buf, int len)
 */
AP_DECLARE(char *) ap_md5_binary(apr_pool_t *a, const unsigned char *buf, int len);

/**
 * Convert an MD5 checksum into a base64 encoding
 * @param p The pool to allocate out of
 * @param context The context to convert
 * @return The converted encoding
 * @deffunc char *ap_md5contextTo64(apr_pool_t *p, apr_md5_ctx_t *context)
 */
AP_DECLARE(char *) ap_md5contextTo64(apr_pool_t *p, apr_md5_ctx_t *context);

#ifdef APACHE_XLATE
/**
 * Create an MD5 Digest for a given file
 * @param p The pool to allocate out of
 * @param infile The file to create the digest for
 * @param xlate The translation header to use.
 * @warning The xlate parameter is only available if APACHE_XLATE is defined
 * @deffunc char *ap_md5digest(apr_pool_t *p, apr_file_t *infile, apr_xlate_t *xlate)
 */
AP_DECLARE(char *) ap_md5digest(apr_pool_t *p, apr_file_t *infile,
                                apr_xlate_t *xlate);
#else
AP_DECLARE(char *) ap_md5digest(apr_pool_t *p, apr_file_t *infile);
#endif

#ifdef __cplusplus
}
#endif

#endif	/* !APACHE_UTIL_MD5_H */
