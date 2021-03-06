/*
* MIT License
* 
* Copyright (c) 2022 nap.software
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
/*!
 * @name aes:intro
 * @brief Encrypt & decrypt messages
 */
#if !defined(NAPC_MODULE_AES_h)
	#define NAPC_MODULE_AES_h

	#include <libnapc.h>

	/*!
	 * @name napc_aes_encrypt
	 * @brief Encrypt a message with AES-256.
	 * @version 1.0.0
	 * @description
	 * Encrypt a message with AES-256 in CBC mode.
	 * @param iv Initialization vector (16 bytes)
	 * @param key Key in HEX format (32 bytes)
	 * @param buffer Buffer to encrypt.
	 * @param buffer_size Size of buffer.
	 * @warning The input buffer must always be aligned to 16 bytes.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message[32];
	 * napc_u8 iv[16];
	 * const char *key = "secret";
	 * char key_hashed[65];
	 * 
	 * // initialize IV with random bytes
	 * // note that napc_random_getRandomBytesSync() is used here for simplicity
	 * // it is better to use napc_random_getRandomBytes().
	 * napc_random_getRandomBytesSync(sizeof(iv), iv);
	 * 
	 * // since napc_aes_encrypt() expects a HEX formatted key string
	 * // we simply calculate the SHA256 hash of the key
	 * // which is guaranteed to be a 32 byte hex formatted string.
	 * if (napc_sha_calculate(key, napc_strlen(key), key_hashed, sizeof(key_hashed))) {
	 *     // set all bytes in message to zero
	 *     // napc_aes_encrypt() always needs the input buffer's size to be 
	 *     // a multiple of 16. This way unused bytes are always zero.
	 *     napc_mzero(message, sizeof(message));
	 * 
	 *     // copy a message
	 *     napc_strncpy(message, "Hello, World!", sizeof(message));
	 * 
	 *     // do the encryption
	 *     if (napc_aes_encrypt(iv, key_hashed, message, sizeof(message))) {
	 *         // message is now encrypted
	 *         napc_printf("Message encrypted!\n");
	 * 
	 *         napc_printf("Key: %s\n", key_hashed);
	 * 
	 *         napc_printf("IV: ");
	 *         napc_misc_printHexArray(iv, sizeof(iv));
	 *         napc_printf("\n");
	 * 
	 *         napc_printf("Ciphertext: ");
	 *         napc_misc_printHexArray(message, sizeof(message));
	 *         napc_printf("\n");
	 *     }
	 * }
	 */
	bool napc_aes_encrypt(
		const napc_u8 *iv,
		const char *key,
		void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_aes_decrypt
	 * @brief Decrypt a message with AES-256.
	 * @version 1.0.0
	 * @description
	 * Decrypt a message with AES-256 in CBC mode.
	 * @param iv Initialization vector (16 bytes)
	 * @param key Key in HEX format (32 bytes)
	 * @param buffer Buffer to encrypt.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning The input buffer must always be aligned to 16 bytes.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_aes_decrypt(
		const napc_u8 *iv,
		const char *key,
		void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
