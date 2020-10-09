//------------------------------------------------------------------------------
// Include the IRremote library header
//
#include "IRremote.h"

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver 
//

int IR_RECEIVE_PIN = 0;

IRrecv irrecv(IR_RECEIVE_PIN);

//+=============================================================================
// Configure the Arduino
//
void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  // Start the receiver
}

//+=============================================================================
// Dump out the decode_results structure.
//
void dumpCode(decode_results *results) {
    // Start declaration
    Serial.print("unsigned int  ");          // variable type
    Serial.print("rawData[");                // array name
    Serial.print(results->rawlen - 1, DEC);  // array size
    Serial.print("] = {");                   // Start declaration

    // Dump data
    for (unsigned int i = 1; i < results->rawlen; i++) {
        Serial.print(results->rawbuf[i] * MICROS_PER_TICK, DEC);
        if (i < results->rawlen - 1)
            Serial.print(","); // ',' not needed on last one
        if (!(i & 1))
            Serial.print(" ");
    }

    Serial.print("};");  //End declaration

    Serial.println("");   // Newline
    Serial.println("");
}




//+=============================================================================
// The repeating section of the code
//
void loop() {
    decode_results results;        // Somewhere to store the results

    if (irrecv.decode(&results)) {  // Grab an IR code
        dumpCode(&results);           // Output the results as source code
        irrecv.resume();              // Prepare for the next value
    }
}
