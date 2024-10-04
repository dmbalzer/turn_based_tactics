#ifndef CORE_H
#define CORE_H

/******************************************************************************
 * 
 ***************************************/
/***************************************
 * Initialize SDL, TTF, IMG
 * returns 0 on success
 ***************************************/
int init(void);

/***************************************
 * Process SDL events
 * Update keyboard state arrays
 * Update mouse state arrays
 * Update mouse positions
 ***************************************/
void process_events(void);

/***************************************
 * Clears background and begins draw
 ***************************************/
void begin_drawing(void);

/***************************************
 * Ends drawing and presents frame
 ***************************************/
void end_drawing(void);

/***************************************
 * Unload SDL, TTF, IMG
 ***************************************/
void unload(void);

#endif // CORE_H