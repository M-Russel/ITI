/*
 * Buzzer.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Russel
 */

#ifndef BUZZER_H_
#define BUZZER_H_

// number of timer0 overflows/sec
#define INT_PER_SEC 31250

// Frequencies (in Hz) of notes
#define F_FSH_4 370
#define F_A_4 440
#define F_B_4 494
#define F_E_4 330
#define F_CSH_5 554
#define F_D_5 587
#define F_FSH_5 740
#define F_CSH_4 277
#define F_GSH_4 415

// number of timer0 overflows for notes
#define REST -1 // special case
#define FSH_4 INT_PER_SEC/F_FSH_4
#define A_4 INT_PER_SEC/F_A_4
#define B_4 INT_PER_SEC/F_B_4
#define E_4 INT_PER_SEC/F_E_4
#define CSH_5 INT_PER_SEC/F_CSH_5
#define D_5 INT_PER_SEC/F_D_5
#define FSH_5 INT_PER_SEC/F_FSH_5
#define CSH_4 INT_PER_SEC/F_CSH_4
#define GSH_4 INT_PER_SEC/F_GSH_4

#define SEMIQUAVER_TIME 60  // ms
#define BREATH_TIME 20      // ms


#endif /* BUZZER_H_ */
