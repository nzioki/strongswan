/*
 * Copyright (C) 2011 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup pa_tnc_msg pa_tnc_msg
 * @{ @ingroup libimcv
 */

#ifndef PA_TNC_MSG_H_
#define PA_TNC_MSG_H_

typedef struct pa_tnc_msg_t pa_tnc_msg_t;

#include "pa_tnc_attr.h"

#include <library.h>

/**
 * Interface for the RFC 5792 PA-TNC Posture Attribute protocol.
 *
 */
struct pa_tnc_msg_t {

	/**
	 * Get the encoding of the PA-TNC message
	 *
	 * @return					encoded PA-TNC message
	 */
	chunk_t (*get_encoding)(pa_tnc_msg_t *this);

	/**
	 * Add a PA-TNC attribute
	 *
	 * @param attr				PA-TNC attribute to be addedd
	 */
	void (*add_attribute)(pa_tnc_msg_t *this, pa_tnc_attr_t* attr);

	/**
	 * Build the PA-TNC message
	 */
	void (*build)(pa_tnc_msg_t *this);

	/**
	 * Process the PA-TNC message
	 *
	 * @return					return processing status
	 */
	status_t (*process)(pa_tnc_msg_t *this);

	/**
	 * Enumerates over all PA-TNC attributes
	 *
	 * @return				return attribute enumerator
	 */
	enumerator_t* (*create_attribute_enumerator)(pa_tnc_msg_t *this);

	/**
	 * Destroys a pa_tnc_msg_t object.
	 */
	void (*destroy)(pa_tnc_msg_t *this);
};

/**
 * Create an empty PA-TNC message
 */
pa_tnc_msg_t* pa_tnc_msg_create(void);

/**
 * Create an unprocessed PA-TNC message from received data
 *
 * @param data					PA-TNC message data
 */
pa_tnc_msg_t* pa_tnc_msg_create_from_data(chunk_t data);

#endif /** PA_TNC_MSG_H_ @}*/
