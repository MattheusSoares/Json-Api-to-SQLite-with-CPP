/*
 * utils.h
 *
 *  Created on: Nov 5, 2014
 *  Author: csantana
 */

#ifndef UTILS_H_
#define UTILS_H_


#define MAX_RESPONSE_BUFFER_SIZE (10240)
#define DATE_TIME_BUFFER_SIZE (40)
#define BUFF_MEDIUM_SIZE (10240)

// check database for these values

#define TURNSTILE_OK (0)
#define TURNSTILE_TIMEDOUT (1)
#define TURNSTILE_WRONG_POSITION (2)
#define TURNSTILE_ERROR_UNKNOWN (3)

#define ADM_CARD_SHUTDOWN ("1")
#define ADM_CARD_SUSPEND_OPERATION ("2")
#define ADM_CARD_RESUME_OPERATION ("3")
#define ADM_CARD_RELEASE_TURNSTILE ("4")



#define WRITE_CARD_OK (1)
#define WRITE_CARD_ERROR (2)

#define TIMESTAMP_TEST_NO_SKIP (0)
#define TIMESTAMP_TEST_SKIP_TURSTILE_TIMEDOUT (1)


/** the undefined meal attempt */
#define	MEAL_ATTEMPT_UNKNOWN (0)
/** a successful meal attempt meaning that the user can have the current meal */
#define	MEAL_ATTEMPT_SUCCESS (1)
 /** the user have alread had the current meal. */
#define	MEAL_ATTEMPT_ALREADY_HAD_MEAL  (2)
/** card timestamp is somehow wrong (usually card time ahead of the system time) */
#define	MEAL_ATTEMPT_WRONG_TIMESTAMP (3)
/** there is not a registered meal to be served at server current time */
#define	MEAL_ATTEMPT_OUT_OF_TIME (4)

#endif /* UTILS_H_ */
