/*
 * Copyright (C) 2009 Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * SHA1 hmac test vectors from RFC2202
 */
signer_test_vector_t sha1_hmac_s1 = {
	.alg = AUTH_HMAC_SHA1_96, .len = 8,
	.key	= "\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b"
			  "\x0b\x0b\x0b\x0b",
	.data	= "Hi There",
	.mac	= "\xb6\x17\x31\x86\x55\x05\x72\x64\xe2\x8b\xc0\xb6"
};

signer_test_vector_t sha1_hmac_s2 = {
	.alg = AUTH_HMAC_SHA1_128, .len = 8,
	.key	= "\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b"
			  "\x0b\x0b\x0b\x0b",
	.data	= "Hi There",
	.mac	= "\xb6\x17\x31\x86\x55\x05\x72\x64\xe2\x8b\xc0\xb6\xfb\x37\x8c\x8e"
};

signer_test_vector_t sha1_hmac_s3 = {
	.alg = AUTH_HMAC_SHA1_160, .len = 8,
	.key	= "\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b"
			  "\x0b\x0b\x0b\x0b",
	.data	= "Hi There",
	.mac	= "\xb6\x17\x31\x86\x55\x05\x72\x64\xe2\x8b\xc0\xb6\xfb\x37\x8c\x8e"
			  "\xf1\x46\xbe\x00"
};

prf_test_vector_t sha1_hmac_p1 = {
	.alg = PRF_HMAC_SHA1, .key_size = 20, .len = 8,
	.key	= "\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b"
			  "\x0b\x0b\x0b\x0b",
	.seed	= "Hi There",
	.out	= "\xb6\x17\x31\x86\x55\x05\x72\x64\xe2\x8b\xc0\xb6\xfb\x37\x8c\x8e"
			  "\xf1\x46\xbe\x00"
};

prf_test_vector_t sha1_hmac_p2 = {
	.alg = PRF_HMAC_SHA1, .key_size = 4, .len = 28,
	.key	= "Jefe",
	.seed	= "what do ya want for nothing?",
	.out	= "\xef\xfc\xdf\x6a\xe5\xeb\x2f\xa2\xd2\x74\x16\xd5\xf1\x84\xdf\x9c"
			  "\x25\x9a\x7c\x79"
};

signer_test_vector_t sha1_hmac_s4 = {
	.alg = AUTH_HMAC_SHA1_96, .len = 50,
	.key	= "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa",
	.data	= "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd",
	.mac	= "\x12\x5d\x73\x42\xb9\xac\x11\xcd\x91\xa3\x9a\xf4"
			  "\x63\xf1\x75\xd3"
};

signer_test_vector_t sha1_hmac_s5 = {
	.alg = AUTH_HMAC_SHA1_128, .len = 50,
	.key	= "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa",
	.data	= "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd",
	.mac	= "\x12\x5d\x73\x42\xb9\xac\x11\xcd\x91\xa3\x9a\xf4\x8a\xa1\x7b\x4f"
};

signer_test_vector_t sha1_hmac_s6 = {
	.alg = AUTH_HMAC_SHA1_160, .len = 50,
	.key	= "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa",
	.data	= "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd",
	.mac	= "\x12\x5d\x73\x42\xb9\xac\x11\xcd\x91\xa3\x9a\xf4\x8a\xa1\x7b\x4f"
			  "\x63\xf1\x75\xd3"
};

prf_test_vector_t sha1_hmac_p3 = {
	.alg = PRF_HMAC_SHA1, .key_size = 20, .len = 50,
	.key	= "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa",
	.seed	= "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
			  "\xdd\xdd",
	.out	= "\x12\x5d\x73\x42\xb9\xac\x11\xcd\x91\xa3\x9a\xf4\x8a\xa1\x7b\x4f"
			  "\x63\xf1\x75\xd3"
};

prf_test_vector_t sha1_hmac_p4 = {
	.alg = PRF_HMAC_SHA1, .key_size = 25, .len = 50,
	.key	= "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10"
			  "\x11\x12\x13\x14\x15\x16\x17\x18\x19",
	.seed	= "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
			  "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
			  "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
			  "\xcd\xcd",
	.out	= "\x4c\x90\x07\xf4\x02\x62\x50\xc6\xbc\x84\x14\xf9\xbf\x50\xc8\x6c"
			  "\x2d\x72\x35\xda"
};

prf_test_vector_t sha1_hmac_p5 = {
	.alg = PRF_HMAC_SHA1, .key_size = 80, .len = 54,
	.key	= "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa",
	.seed	= "Test Using Larger Than Block-Size Key - Hash Key First",
	.out	= "\xaa\x4a\xe5\xe1\x52\x72\xd0\x0e\x95\x70\x56\x37\xce\x8a\x3b\x55"
			  "\xed\x40\x21\x12"
};

prf_test_vector_t sha1_hmac_p6 = {
	.alg = PRF_HMAC_SHA1, .key_size = 80, .len = 73,
	.key	= "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
			  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa",
	.seed	= "Test Using Larger Than Block-Size Key and Larger "
			  "Than One Block-Size Data",
	.out	= "\xe8\xe9\x9d\x0f\x45\x23\x7d\x78\x6d\x6b\xba\xa7\x96\x5c\x78\x08"
			  "\xbb\xff\x1a\x91"
};

