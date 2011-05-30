/*
 * Copyright (C) 2011 Andreas Steffen, HSR Hochschule fuer Technik Rapperswil
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
 *
 * @defgroup imv_test_state_t imv_test_state
 * @{ @ingroup imv_test_state
 */

#ifndef IMV_TEST_STATE_H_
#define IMV_TEST_STATE_H_

#include <imv/imv_state.h>
#include <library.h>

typedef struct imv_test_state_t imv_test_state_t;

/**
 * Internal state of an imv_test_t connection instance
 */
struct imv_test_state_t {

	/**
	 * imv_state_t interface
	 */
	imv_state_t interface;

	/**
	 * Check and decrease IMC-IMV round-trip count
	 *
	 * @return		new connection state
	 */
	bool (*another_round)(imv_test_state_t *this);

};

/**
 * Create an imv_test_state_t instance
 *
 * @param id		connection ID
 * @param rounds	total number of IMC re-measurements
 */
imv_state_t* imv_test_state_create(TNC_ConnectionID id, int rounds);

#endif /** IMV_TEST_STATE_H_ @}*/
