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
 * @defgroup ita_attr_commandt ita_attr_command
 * @{ @ingroup ita_attr_command
 */

#ifndef ITA_ATTR_COMMAND_H_
#define ITA_ATTR_COMMAND_H_

typedef struct ita_attr_command_t ita_attr_command_t;

#include "pa_tnc/pa_tnc_attr.h"

#define ITA_ATTR_COMMAND	0x01

/**
 * Class implementing the ITA Command PA-TNC attribute.
 *
 */
struct ita_attr_command_t {

	/**
	 * Public PA-TNC attribute interface
	 */
	pa_tnc_attr_t pa_tnc_attribute;

	/**
	 * Get the ITA command string
	 *
	 * @return				ITA command string
	 */
	char* (*get_command)(ita_attr_command_t *this);
};

/**
 * Creates an ita_attr_command_t object from a command string
 *
 * @param command			ITA command string
 */
pa_tnc_attr_t* ita_attr_command_create(char *command);

/**
 * Creates an ita_attr_command_t object from received data
 *
 * @param command			ITA command string
 */
pa_tnc_attr_t* ita_attr_command_create_from_data(chunk_t value);

#endif /** ITA_ATTR_COMMAND_H_ @}*/
